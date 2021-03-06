## 메모리 관리

### 메모리 관리 기법과 가상 메모리
>물리 메모리의 한계를 극복하기 위해 나온 기법 중 가장 성공적인 기법

#### 가상 메모리
>실제 시스템에 존재하는 물리 메모리의 크기와 관계없이 가상 주소 공간을 사용자 태스크에게 제공한다.

32bit CPU의 경우 주소 지정할 수 있는 최대 크기인 2^32 크기(4GB)를 제공하며,
64bit CPU의 경우 2^64 크기(16EB)의 크기를 제공한다.

4GB의 공간은 프로그래머에게 제공되는 가상의 공간이며, 실제로는 사용자가 필요한 만큼의 물리 메모리를 제공한다.

### 물리 메모리 관리 자료 구조

복수 개의 CPU를 가지고 있는 컴퓨터 시스템 중 모든 CPU가 메모리와 입출력 버스 등을 공유하는 구조를 SMP라 부른다.

CPU들을 몇 개의 그룹으로 나누고 각각의 그룹에게 별도의 지역 메모리를 주는 구조를 NUMA라 부르며, 기존 시스템을 UMA라 한다.

NUMA 구조에서는 CPU에서 어떤 메모리에 접근 하느냐에 따라 성능의 차이가 생길 수 있다.

예를 들어 CPU를 자신에게 가까운 곳의 메모리를 주로 사용해야 빠르게 데이터를 읽어올 수 있다.

즉, 각각의 구조에 적합한 메모리 정책을 사용해야 한다.

#### Node
>뱅크를 표현하는 구조

**뱅크(Bank)**
>리눅스에서 접근 속도가 같은 메모리의 집합

만약 NUMA 구조의 시스템에서 리눅스가 수행되면 복수 개의 노드가 존재할 것이고, UMA 구조의 시스템에서는 한 개의 노드가 존재할 것이다.

복수 개의 노드는 리스트를 통해 관리되며, pgdat_list 배열을 통해 접근 가능하다.
![Bank와 Node의 관계](https://t1.daumcdn.net/cfile/tistory/2279804D553B7CBC01)

출처 : [A.T.S Mucha](http://atsequence.tistory.com/30)

하나의 노드는 pg_data_t 구조체를 통해 표현된다.

이 구조체는 해당 노드에 속해있는 물리 메모리의 실제 양(node_present_pages), 해당 물리메모리가 메모리 맵의 몇 번지에 위치하고 있는지를 나타내기 위한 변수(node_start_pfn) 등이 정의되어 있다.

만약 리눅스가 물리 메모리의 할당을 요청 받게 되면, 되도록 할당을 요청한 태스크가 수행되고 있는 CPU와 가까운 노드에서 메모리를 할당하려 한다.

이러한 이유 때문에 이전에 수행되었던 CPU에서 다시 수행되도록 하는 정책이 높은 성능을 얻게 된다.

#### Zone
>Node의 일부분을 따로 관리 할 수 있게 만든 자료구조

다른 Zone의 메모리와는 별도로 관리되어야 하는 메모리의 집합이다.

* ZONE_DMA
>16MB 이하

* ZONE_NORMAL
>16MB 이상

* ZONE_HIGHMEN
>896BM 이상

#### Page Frame
>각각의 zone은 자신에 속해 있는 물리 메모리 들을 관리하는데, 이 물리 메모리의 최소 단위를 Page Frame 이라 한다.

![Zone과 Page Fraem](https://t1.daumcdn.net/cfile/tistory/21096236553B84CE0C)

출처 : [A.T.S Mucha](http://atsequence.tistory.com/30)

복수 개의 Page Frame -> Zone

복수 개의 Zone -> Node

### Buddy, Slab

리눅스의 메모리 최소 할당 단위는 페이지 프레임 단위인 4KB이다.
>할당된 공간마다 메타 데이터로 관리 할 때 합리적인 최소 할당 공간

#### 버디 할당자(Buddy Allocator)
>2.6.19 버전 이전의 메모리 할당자, 현재는 Lazy Buddy Allocator가 쓰인다.

버디 할당자는 zone 구조체에 존재하는 free_area() 배열을 통해 구축된다.

free_area 배열의 각 엔트리는 free_area 라는 구조체이며, free_list, map 이라는 필드를 갖는다.

free_area 배열은 10개의 엔트리를 가진다 0~9까지 각각의 숫자는 해당 free_area가 관리하는 할당의 크기를 나타낸다.
예를들어 0인 2^0, 1인경우 2^1로 각각 1개의 페이지 프레임, 2개의 페이지 프레임이 할당되는 단위이다.

결국 버디는 2^n 의 페이지 프레임들을 할당해준다.

free_area 구조체는 free_list 변수를 통해 자신에게 할당된 free 페이지 프레임들을 list로 관리한다.

또한 자신이 관리하는 수준에서 페이지의 상태를 map 변수를 통해 비트맵으로 관리한다.

![버디 할당자의 동작 예1](https://t1.daumcdn.net/cfile/tistory/210E9A3C524D11CC09)

출처 : [Daeseok's Blog](http://woodz.tistory.com/57)

    
    그림을 보면 15개의 페이지 프레임이 있는데,
    
    5, 10 12-15번 까지의 페이지 프레임이 free 상태다.

    free_list 를 보면 2^0인 1프레임씩 5번과 10번이 free 상태이고,

    2^2인 12번이 4프레임 단위로 free 라는 것을 알 수 있다. 
    

![버디 할당자의 동작 예2](https://t1.daumcdn.net/cfile/tistory/266B3939524D11E613)

출처 : [Daeseok's Blog](http://woodz.tistory.com/57)

    그림을 보면 3번 프레임을 할당 해제 해 free가 된 것을 알 수 있다.
    

![버디 할당자의 동작 예3](https://t1.daumcdn.net/cfile/tistory/2743D03A524D11FB16)

출처 : [Daeseok's Blog](http://woodz.tistory.com/57)

    이번 그림에서는 0과 1번 프레임이 추가로 free가 되었다.

![버디 할당자의 동작 예4](https://t1.daumcdn.net/cfile/tistory/2216B037524D122011)

출처 : [Daeseok's Blog](http://woodz.tistory.com/57)

    free가 된 0 과 1번 프레임은 연속된 2^1 크기 프레임 이기 때문에 list의 1번으로 변경된다.

![버디 할당자의 동작 예5](https://t1.daumcdn.net/cfile/tistory/265A3C34524D123901)

출처 : [Daeseok's Blog](http://woodz.tistory.com/57)

![버디 할당자의 동작 예6](https://t1.daumcdn.net/cfile/tistory/2208D535524D126706)

출처 : [Daeseok's Blog](http://woodz.tistory.com/57)

    0과 1번 프레임이 다시 allocated 상태가 되면서 list에서 삭제 되었다.

![버디 할당자의 동작 예7](https://t1.daumcdn.net/cfile/tistory/266B3939524D128116)

출처 : [Daeseok's Blog](http://woodz.tistory.com/57)

    이번에는 11,12,13번 프레임이 allocated 상태가 되었다.

    따라서 연속된 4프레임이 free 였던 12-15 프레임은 14-15 프레임만 free 상태가 되었다.

    14-15 프레임은 2^1 단위로 연속된 프레임이기 때문에 1번 리스트에 14번 프레임이 들어간다.

### Lazy Buddy
>zone에 가용 메모리가 충분한 경우, 메모리 해제 후 합치는 작업을 최대한 뒤로 미뤄 오버헤드를 최소화하는 할당자.

### 슬랩 할당자(Slab Allocator)
>미리 메모리를 할당받아 관리하고 있다가 작은 메모리 할당 요청이 들어오면 조금씩 떼어주면서 내부 단편화를 줄이는 할당자

슬랩 할당자는 32Byte에서 4MB까지의 캐시를 유지한다.

각 cache는 슬랩들로 구성되고, 슬랩은 다시 객체(Object)들로 구성된다.

슬랩은 구성하고 있는 객체들의 상태에 따라 Full, Free, Partial로 구분된다.

Free슬랩은 모든 객체가 사용 가능한 상태이고, Full 슬랩은 모든 객체가 이미 사용 중인 상태이며, Partial 슬랩은 일부는 사용 중이고 일부는 비사용 중인 상태이다.

슬랩 할당자에게 메모리 할당 요청이 들어온다면 가장 적합한 크기의 캐시를 찾아가서, partial 슬랩으로부터 객체를 할당해준다.

#### kmem_cache

리눅스는 다양한 크기의 캐시를 효율적으로 관리하기 위해 kmem_cache라는 자료구조를 정의해두었다.

kmem_cache는 각 캐시가 담고 있는 객체 크기등의 정보를 표현한다.

따라서 새로운 캐시를 생성하기 위해서 kmem_cache라는 구조체로부터 할당받아야 한다.

kmem_cache 또한 슬랩 할당자로부터 캐시를 할당받는데, kmem_cache구조체 크기의 객체를 담고 있는 캐시의 이름이 cache_cache이다.

cache_cache는 다른 캐시들보다 먼저 생성되어야 하며, cache_cache가 생성되어야 kmem_cache를 위한 공간을 할당받아 다양한 캐시를 생성할 수 있게 된다.

슬랩 할당자가 더 이상 할당해줄 공간이 없다면 슬랩 할당자는 버디로부터 페이지 프레임을 더 할당받아 슬랩을 확장한다.

![슬랩 할당자의 구조](https://t1.daumcdn.net/cfile/tistory/205CF04F5004EBF009)

### 가상 메모리 관리 기법
    태스크는 자신의 고유한 가상 메모리를갖는다.
    
    따라서 커널은 태스크의 가상 메모리가 어디에 존재하는지 관리를 해야 한다.

    task_struct에서 태스크의 메모리와 관련된 내용은 mm이라는 이름의 필드에 담겨 있다.

    mm_struct 자료구조가 관리하는 정보들은 크게 3부분으로 구분할 수 있다.

    
1. vm_area_struct 구조체

2. pgd 변수

3. 가상 메모리의 구조에 대한 변수들


##### vm_area_struct
    리눅스 커널은 가상 메모리 공간 중 같은 속성을 가지며 연속인 영역을 'region'이라 부른다.
    (세그먼트='region')

    리눅스는 각각의 region을 vm_area_struct라는 자료구조를 통해 관리한다.

    같은 태스크에 속한 vm_area_struct들은 RBTree로 연결되어 있다.

    mm_struct에는 이 트리의 시작을 가리키는 변수인 mm_rb와
    최근에 접근한 vm_area_struct를 가리키는 mmap_cache 변수 등이 존재한다.

##### pgd변수
   주소변환을 위한 페이지 디렉터리의 시작점 주소를 pgd변수에 유지한다.

##### 가상 메모리의 구조에 관한 변수들
    가상 메모리의 구조에 대한 변수들은 start_code, start_data, start_stack등이 해당된다.

![mm_struct 구조](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQqfKZh3C_eioGjxbsQ3IRJEKXjcsfhzPGdeGAy2PgKDMLTtaf8Cw)

출처 : [esos.hanyang.ac.kr](http://esos.hanyang.ac.kr/tc/2015gradproject2/i/entry/2)

태스크는 텍스트, 데이터, 스택 등의 region으로 구성된다.

텍스트는 가상 메모리의 0번지 부터 시작한다.(start_code)

텍스트의 끝(end_code)부터 데이터가 차지한다(start_data).

데이터의(end_data) 끝부터 힙이 차지한다(start_brk).

힙의 끝은 brk라는 변수가 가리킨다.

태스크에 새로운 메모리 공간이 동적으로 할당되면 brk부터 힙이 위쪽 방향으로 자라게 된다.

스택은 커널과 자용자 영역의 경계인 3GB 바로 아래에 존재한다.

스택의 끝은 환경변수(environment variable)와 초기 인자(inital argument)가 차지한다(env_start와 env_end).

vm_area_struct 자료구조를 구체적으로 나타내면 자료구조가 가리키는 세그먼트의 시작 주소(vm_start), 끝 주소(vm_end), reion의 접근 제어등을 기록하는 플래그(vm_flags)등의 변수를 갖는다.

또한 이 세그먼트가 실제 실행 파일의 어느 위치에 있는지에 대한 정보를 vm_file와 vm_offset 변수로 관리한다.

이 변수들은 페이지 폴트가 발생했을 때 어떤 파일의 어느 부분을 읽어야 하는지 결정할 때 쓰인다.

![vm_area_struct와 가상 메모리 공간](https://sites.google.com/site/bletchleypark2/_/rsrc/1468735995738/3-operating-system/linux/linux-memory-management/vm_area_struct.jpg)

출처 : [Bletchley Park](https://sites.google.com/site/bletchleypark2/3-operating-system/linux/linux-memory-management)

물리 메모리 관리기법과 마찬가즈로 가상 메모리 역시 고정된 크기의 할당 단위로 관리된다.

4KB의 페이지들이 모여 vm_area를 구성하고, 이를 vm_area_struct라는 자료구조로 관리한다.

또한 같은 태스크에 속한 vm_area 들이 모여 하나의 mm_struct로 관리된다.

vm_area_struct들은 겹쳐지지 않으며 새로 사용하려는 가상 주소 공간이 인접한 vm_area_struct와 같은 속성을 가진다면 합쳐져서 관리될 수 있다.

### 가상 메모리와 물리 메모리의 연결 및 반환

    태스크가 생성되면 가상 메모리 주소 공간이 제공되고,
    
    필요하다면 물리 메모리의 일부를 할당해 준 뒤,
    
    태스크가 원하는 디스크상의 내용을 읽어 물리 메모리에 올려놓고,
    
    물리 메모리의 실제 주소와 가상 주소 공간을 연결해 주어야 한다.

디스크에 저장되어 있는 실행 파일의 어느 부분을 읽어서 물리 메모리에 올려놓을 것인가는 ELF 포맷 파일의 헤더를 읽음으로써 가능하고, 이를 가상 주소 몇번지와 연결해 줄 것인가는 미리 정해져 있는 규칙을 따른다.

프로그램의 명령어나 데이터를 물리 메모리에 올려놓고 이를 읽어 오려면 가상 주소를 물리 주소로 변환할 수 있는 방법이 있어야 한다.

이때 이용되는 것이 페이지 테이블(page table)이다.

![페이지 테이블을 통한 주소 공간 연결](https://i.stack.imgur.com/e2NNe.png)

출처 : [Stack Exchange](https://cs.stackexchange.com/questions/66698/difference-between-page-table-and-inverted-page-table)

예를들어 CPU가 가상 주소 1000번지를 접근하려 한다면, 커널은 가상 주소를 가상 메모리의 최소 단위인 페이지로 나눈다.

그리고 몫을 페이지 테이블의 엔트리를 탐색하는 인덱스로 사용하고, 나머지는 페이지 프레임 내에서 오프셋(offset)으로 활용한다.

가상주소가 1000이므로 몫은 0, 나머지는 1000이 된다.

0을 인덱스로 페이지 테이블을 탐색해 첫번째 엔트리를 찾게 되면 7KB라고 나온다.

즉, 7KB로 시작하는 페이지 프레임의 오프셋 1000만큼 이동하면 가상주소에 대한 물리 주소를 얻을 수 있게 된다.

이렇게 페이지 테이블을 통해 가상 주소를 물리 주소로 변환하는 과정을 페이징(pag-ing)이라 부른다.

    태스크가 실제로 실행되면 실제 메모리에 모든 페이지를 적재하지 않는데, 태스크가 수행하면서 이 페이지를 접근하려고 하면
    페이지 폴트가 발생하며 트랩이 걸리고, IDT 테이블을 거쳐 결국 페이지 폴트 핸들러가 발생된다.

    페이지 폴트 핸들러는 free 페이지 프레임 하나를 할당받고
    실행파일에서 해당 페이지를 읽어 할당받은 페이지 프레임에 읽어다 놓는다.

    즉, 실행파일을 처음 메모리에 적재할 때 수행에 필요한 일부 페이지만 적재하고 다른 페이지들은
    실제로 참조될 때 비로소 페이지 폴트 처리 과정을 통해 적재되도록 한다.

실제 리눅스커널 내부에서 이뤄지는 페이징 작업은 훨씬 복잡하다.

만약 각 태스크마다 하나의 페이지 테이블을 사용하면 그 페이지 테이블의 엔트리 개수가 너무 많아지기 때문에 리눅스는 페이징을 여러 단계로 구분했다.

