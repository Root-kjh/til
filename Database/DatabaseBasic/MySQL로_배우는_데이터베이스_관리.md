## MySQL로 배우는 데이터베이스 관리

### 스토리지 엔진

MySQL DB를 조작하는 경우는 클라이언트 프로그램이 MySQL 서버 프로세스에 접속하여 SQL 문을 발생하는 흐름이다.

이때 서버는 아래와 같은 순서로 처리한다.

1. 클라이언트의 접속을 허용하여 전용 스레드를 할당한다. 접속이 끝긴 상태에서는 스레드가 다음 접속에 대비해 캐시 영역에 보관된다. 이에 따라 접속/절단의 오버헤드를 줄인다.

2. SELECT 문이 이전에 실행 것과 세세한 부분까지 다르지 않으면 검색을 실제로 하는 대신 미리 캐시해 놓은 검색 결과를 그대로 반환한다(쿼리 캐시).

3. 쿼리 캐시에 히트하지 않으면 전송된 SQL문이 구문으로서 올바른지 확인을 한다(구문 파싱 처리).

4. 구문 분석이 완료되면 SQL 문의 실행 계획을 결정한다. SQL문의 실행 계획은 테이블에 엑세스하는 방법을 규정하는 것으로 구체적으로는 인덱스 사용여부다. 이를 사용하는 경우 어떤 인덱스를 사용할지와 조인 시에 어떤 테이블을 먼저 읽어야 할지 등을 결정한다(최적화).

![Mysql Storage Architecture](https://3.bp.blogspot.com/-WllJC9xfxqg/VxTbuAoMm4I/AAAAAAAAHzA/1tF7Sxx8Y34levMmR9fYPZfDQDHVdWzKwCLcB/s400/MySQL%2BArchitecture.png)

출처 : [Database blog by Rathish kumar](https://www.rathishkumar.in/2016/04/understanding-mysql-architecture.html)

MySQL은 다양한 레코드 처리 구현 방법을 제공하고 있어, 용도에 맞는 것을 선택할 수 있는 아키텍처를 채용하고 있다.

다른 주요 RDBMS에 가장 비슷하게 구현되어 있는 것은 InnoDB다 따라서 모든 테이블에 InnoDB를 사용해두면 유연하게 스토리지 엔진을 서낵할 수 있다는 장점은 사라지지만 다른 RDBMS와 같은 감각으로 사용할 수 있다.

#### InnoDB 스토리지 엔진
>현재 MySQL에서 가장 널리 사용되고 있는 스토리지 엔진

MyISAM과 InnoDB의 가장 큰 차이점은 innoDB는 트랜잭션을 지원한다는 점이다.

##### 파일 구성

MySQL에서는 스토리지 엔진에 관게없이 모든 테이블에 대해 테이블 정의 정보를 기록한 테이블명.frm이라는 파일이 만들어진다.

.frm 파일은 테이블의 메타 정보를기록하기 위한 파일로, MySQL 5.0까지 테이블 이름을 영문자 또는 밑줄 등의 ASCII 문자로 구성해야 했다.

InnoDB 전용 파일로는 InnoDB 데이터파일 (예 : idbdata1)과 InnoDB 로그 파일 (예 : ib_logfile0,1)의 두 가지 파일이 생성된다.

실제 데이터가 기록되는 것은 InnoDB 데이터 파일로, 크기가 커지면 자동으로 확장되어 간다.

### MySQL 운용에 필요한 파일의 기초 지식

#### 로그 파일 형식

* 오류 로그 파일
> MySQL 본체 프로세스의 기동/정지의 정보 및 오류 정보를 출력하는 파일이다.

* 슬로우 쿼리 로그 파일
> 실행에 일정 시간 이상을 필요로 하는 쿼리를 로그 파일에 출력하는 기능이다.

* 일반 로그 파일
> 실행된 모든 SQL문을 로그 파일에 출력하기 위한 기능이다.

* 바이너리 로그 파일
>애플리케이션에서 발행된 업데이트성의 SQL문이 기록된다.

#### my.cnf의 설정 항목

* basedir/datadir
> basedir : MySQL본체 설치 디렉터리, datadir : DB의 테이블을 만든 디렉터리

* port/socket
> port : MySQL의 포트 번호 , socket : UNIX 소켓 파일에 따른 접속을 위한 파일명 지정

* default-storage-engine
>테이블을 만들 때 기본적으로 선택되는 스토리지 엔진 지정 기본값은 MyISAM이다.

* log-bin
>바이너리 로깅을 활성화하기 위한 파라미터

* slow-query-log
>슬로우 쿼리 로그를 사용하는 파라미터

* long-query-time
>실행에 몇 초 이상 걸린 SQL문을 슬로우 쿼리 로그에 기록할지 여부 지정

* max_connections
>MySQL에 접속 가능한 상한의 접속 수

* innodb_buffer_pool_size
>InnoDB 데이터 영역을 메모리 상에서 관리하기 위한 버퍼 사이즈

* innodb_flush_method
>InnoDB 데이터 파일과 로그 파일을 읽고 쓰는 방법 지정

* innodb_data_file_path
>InnoDB 데이터 파일의 초기 크기와 배치 디렉터리 지정

* innodb_autoextend_increment
>데이터 크기가 꽉 찼을 때 자동으로 확장하는 단위

* innodb_log_file_ize
>InnoDB 로그 파일 사이즈 지정

### MySQL 백업의 기초

#### 백업 유형

##### 콜드 백업과 온라인 백업

* 콜드백업
>MySQL의 실행을 멈추고 백업하는 것

* 온라인 백업
>MySQL을 실행하면서 백업하는 것

##### 논리적 백업과 물리적 백업

* 논리적 백업
>SQL문과 같이 인간이 읽을 수 있는 형식으로 백업하는 것

* 물리적 백업
>파일 복사 만으로 복원 가능