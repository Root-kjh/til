# 네트워킹 기본
## 네트워크 소개
>네트워크는 물리적 또는 논리적으로 연결된 하드웨어 장비의 모음이다.

### 네트워크의 장점과 이익

**연결성과 통신**

한 건물이나 작업 그룹 내의 개인들은 근거리 네트워크(LAN, Local Area Networks)로 연결될 수 있다. 원거리에 있는 LAN이 서로 연결되면 원거리 네트워크(WAN, Wide Area Networks)가 된다.

네트워크가 연결되면 네트워크 사용자는 이메일과 같은 기술을 사용하여 통신할 수 있다.

이렇게 함으로써 네트워크가 없는 경우보다 더 쉽고, 효율적이고, 적은 비용으로 정보를 전달할 수 있다.

**데이터 공유**

네트워킹은 수천 명의 직원들이 쉽고 빠르게 데이터를 공유하도록 한다.

데이터베이스, 그룹 소프트웨어와 같은 여러 애플리케이션은 네트워킹을 이용해 많은 사람들이 동일한 데이터를 조회하고 공유할 수 있도록 한다.

**하드웨어 공유**

네트워크를 사용하게 되면 프린터 하나를 네트워크에 설치해 모두가 사용할 수 있게 할 수 있다.

**인터넷 접속**

인터넷 자체가 광대한 네트워크이므로, 인터넷에 접속했다면 이미 네트워크를 사용하는 것이다.

**인터넷 접속 공유**

여러 사용자가 하나의 인터넷 연결을 공유 할 수 있다.

특수 하드웨어 장비를 이용하면 낮은 속도의 회선에 여러 개 가입하는 대신 빠른 속도 회선 하나에 가입하는 것이 가능해진다.

**데이터 보안과 관리**

사용자들이 만드는 데이터를 관리자는 공유 서버로 모을 수 있고, 이렇게 되면 데이터의 관리가 쉬워진다.

관리자는 다양한 중요 정보를 읽거나 수정하는 권한을 통제하는 보안 조치를 구현할 수도 있다.

**성능 향상과 분배**

특정 상황에서 계산 작업을 네트워크의 여러 컴퓨터로 분배하여 일부 애플리케이션의 전체적인 성능을 향상시킬 수 있다.

### 네트워크의 단점과 비용 

**네트워크 하드웨어, 소프트웨어, 구성, 관리비용**

네트워크를 구성하려면 하드웨어와 소프트웨어에 투자해야 한다.

**데이터 보안 염려**

보안이 허술한 네트워크는 중요한 데이터를 해커나 허가 받지 않은 접근, 파괴와 같은 위험에 노출시킨다.

---

## 기본 네트워크 특성

### 네트워킹 계층, 모델, 구조
>네트워킹의 구조를 잘 알려면 OSI 모델부터 이해해야 한다.

**TCP/IP**
>OSI 모델 4계층에서 동작하는 전송 제어 프로토콜 (TCP, Transmission Control Protocol)과 OSI 모델 3계층 에서 동작하는 인터넷 프로토콜 (IP, Internet Protocol)에서 유래

### 프로토콜
>장비와 시스템이 통신하기 위한 언어, 규칙, 절차 등을 정의

### 서킷 스위칭과 패킷 스위칭 네트워크

**서킷 스위칭(Circuit-Switching)**

모든 통신에 사용되는 서킷이라는 연결이 두 장비간에 맺어진다. 서킷의 속성정보는 네트워크에 의하여 유지된다.

서킷은 항시 고정되어서 존재할 수 있고, 필요에 따라 생겨난다. 통신하는 장비간의 경로가 여러가지라고 해도 실제 통신은 서킷이 맺어진 하나의 경로를 이용하게된다.

서킷스위칭의 예로 전화통화를 들 수 있다.

통화중일때는 통화가 종료될 때 까지 회선을 점유하기때문에 다른사람이 회선을 점유하고 있는 이상 회선을 사용할 수 없다.

![서킷 스위칭](http://mblogthumb1.phinf.naver.net/20141125_160/wnsgmlsnsk12_14169050177253VE93_GIF/4.gif?type=w2)

출처 : [네이버 블로그](https://m.blog.naver.com/PostView.nhn?blogId=wnsgmlsnsk12&logNo=220191672010&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F)

**패킷 스위칭(Packet-Switching)**

패킷 스위칭 네트워크에서는 데이터 전송을 위한 특정 경로가 존재하지 않는다.

이 네트워크에서는 데이터를 패킷이라는 작은 조각으로 나눈 뒤 전송한다.

이 패킷은 최종 목적지에 도달하기 전에 라우팅, 결합, 분할 될 수 있다.

패킷 수신자는 패킷을 읽어 원본 데이터를 만든다.

![패킷 스위칭](https://mblogthumb-phinf.pstatic.net/20141125_51/wnsgmlsnsk12_1416905425636vm77N_GIF/6.gif?type=w2)

출처 : [네이버 블로그](https://m.blog.naver.com/PostView.nhn?blogId=wnsgmlsnsk12&logNo=220191672010&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F)

### 연결형 프로토콜과 비연결형 프로토콜

**연결형(Connection-Oriented) 프로토콜**

1. 두 장비가 데이터를 전송하기 전 논리적 연결을 맺도록 요구

2. 이를 위해 장비들은 연결을 어떻게 시작하고, 협상하고, 관리하고, 끊는지를 명시하는 규칙을 따라야 함

3. 이들 장비는 연결을 위한 제어 정보를 주고 받음

4. 이 과정이 성공하면 두 장비는 데이터를 교환할 수 있다.

5. 데이터 교환을 모두 마치면 연결을 끊는다.

**비연결형(Connectionless) 프로토콜**

1. 장비간의 연결을 맺지 않는다.

2. 데이터를 보내고 싶은 장비는 즉시 그 데이터를 보낸다.

>서킷 스위칭 네트워크는 근본적으로 연결에 기반하여 쓰임

TCP/IP에는 OSI 전송 계층에서 동작하는 주요 프로토콜 두가지가 있다.

1. TCP(연결형) : FTP와 같이 연결 수립을 필요로 하는 애플리케이션에 쓰이며, 데이터를 전송하기 전에 일정한 규칙을 통해 논리적 연결을 협상.

2. UDP(비연결형) : 연결을 비롯한 여러 기능 필요X, 빠른 속도를 요하는 애플리케이션에 쓰임

### 메시지: 패킷, 프레임, 데이터그램, 셀

* 패킷 : OSI 참조 모델의 네트워크 계층에서 동작하는 프로토콜이 보내는 메시지를 의미

* 데이터그램 : 패킷과 동의어, 네트워크 계층 메시지 의미
    > OSI 참조 모델의 상위 계층에서 전송되는 메시지를 언급하는데 쓰임

* 프레임 : OSI 참조 모델의 하위 계층에서 오가는 메시지와 연관되어 있음
    > 데이터 링크 계층 메시지를 언급할 때 쓰이는 경우가 많음

* 셀 : 크기가 고정된 메시지, OSI 하위 계층에서 동작하는 기술에 쓰임

* 프로토콜 데이터 유닛(PDU)과 서비스 데이터 유닛(SDU) : OSI 참조 모델에서 프로토콜 메시지를 설명할 때 쓰이는 단어


### 메시지 포매팅: 헤더, 페이로드, 푸터
>메시지 : 네트워크를 통해 정보를 전송하는 데 쓰이는 구조

모든 프로토콜은 자신이 이용하는 메시지의 구조를 결정하는 특수한 포매팅 방법(FormattingMethod)을 사용한다.

특정한 메시지 유형의 포맷은 그 메시지를 사용하는 기술에 따라 달라지지만 모든 메시지들은 공통적으로 다음 3개의 요소로 이루어진다.

![네트워크 메시지 포매팅](https://mblogthumb-phinf.pstatic.net/MjAxNzA0MDJfMjEg/MDAxNDkxMDk2Mzk0NTg2.BMZyyAs_mQaUTQpf9_UGw2wGIcMOQJlQYnsQjqRmOZQg.XRKefMwvRo6a9htvddb5kLavlzv2I95ydI6lbZMVXcQg.PNG.timschel85/funformatting.png?type=w800)

출처 : [네이버 블로그](https://m.blog.naver.com/PostView.nhn?blogId=timschel85&logNo=220973043231&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F)

**헤더(Header)**

실제 데이터 앞부분에 위치하는 정보.

메시지가 담고 있는 데이터의 중요한 속성, 데이터를 해석하고 사용하는 법을 설명하는 여러 작은 제어 정보 바이트를 포함한다.

서로 다른 장비의 프로토콜 요소간 통신/제어 링크 역할을 한다.

**데이터(Data)**

전송되는 실제 데이터를 가지고 있다.

**푸터(Footer)**

데이터 뒷부분에 위치하는 정보.
>헤더와 푸터는 모두 메시지에서의 위치를 제외하면 기능상으로 동일한 역할을 하지만, 푸터 필드는 전송중인 데이터를 계산에 이용한 값을 저장 할 때 쓰인다.

### 메시지 주소지정과 전송 방법

![유니캐스트, 멀티캐스트, 브로드캐스트 메시지 주소지정과 전송](https://mblogthumb-phinf.pstatic.net/20120828_201/luckyknight_1346139820037oGReb_PNG/2012-08-28_%BF%C0%C8%C4_4-41-22.png?type=w2)

출처 : [네이버 블로그](https://m.blog.naver.com/PostView.nhn?blogId=luckyknight&logNo=10146308094&proxyReferer=&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F)


**유니캐스트 메시지**

한 장비에서 다른 장비로 전송하는 메시지

지정된 수신자가 아닌 장비는 메시지를 받으면 안된다.

**브로드캐스트 메시지**

이 메시지는 네트워크의 모든 장비로 전송된다.

장비의 주소를 모를 떄 이 메시지를 사용한다.

**멀티캐스트 메시지**

특정 기준을 만족하는 스테이션 그룹으로 전송된다.

이들 스테이션은 공통적인 기능을 수행하거나 멀티캐스트 그룹에 속해 있는 경우가 많다.

**유니캐스트 주소지정**

목적지 주소가 특정한 하나의 주소여야 한다.

가장 널리 쓰이는 방법으로, 거의 모든 프로토콜에서 이 주소지정방법을 지원하고 있다.

**브로드캐스트 주소지정**

보통 브로드캐스트를 위해 에약된 특수 주소를 이용한다.

브로트캐스트 주소로 전송된 메시지를 받은 장비는 그 메시지를 모든 장비에게 전송되는 것으로 해석한다.

**멀티캐스트 주소지정**

메시지를 수신할 특정 장비 그룹을 식별하기 위한 수단을 필요로 한다는 점에서 가장 복잡하다.

멀티캐스트는 어떤 장비가 어떤 그룹에 속해 있는지를 관리하기 위한 방법을 필요로 한다.

## 네트워크 구조 모델과 클라이언트/서버, 피어투피어 네트워킹
>네트워크는 일반적으로 두 가지 기본 구조 모델 중 하나를 이용하여 자원을 공유한다.
---
**피어투피어 네트워킹**

각 컴퓨터가 네트워크에서 동등한 상대방(Peer)으로 인식된다.

각 머신은 다른 머신과 공유할 수 있는 자원을 가지고 있다.

특정 장비에 특수한 역할이 할당되는 경우는 없으며, 다른 모든 장비에게 요청을 보낼 수 있다.

단순하고 비용이 저렴하다.

**클라이언트/서버 네트워킹**

소수의 중앙 서버가 클라이언트라는 다수의 사용자 머신에 서비스를 제공한다.

각 장비에게 특수한 역할이 부여된다.

클라이언트/서버 컴퓨팅은 서로 대응된다.

TCP/IP와 인터넷 애플리케이션의 많은 부분이 클라이언트/서버 구조로 되어있다.

복잡하고 비용이 많이 들지만 성능, 확장성, 보안, 안정성 측면에서 장점이 있다.

요즘은 클라이언트/서버 네트워킹을 많이 사용하고 있다.

## 네트워크의 유형과 크기
---
**근거리 네트워크(LAN)**
>Local Area Network

대부분의 사람들이 PC나 다른 소형 컴퓨터를 연결할 때 사용하는 네트워크

**무선 LAN(WLAN)**
>Wireless LANs

무선 장비를 다른 무선 장비뿐만 아니라 아니라 유선 장치와도 연결한다.

**원거리 네트워크(WAN)**
>Wide Area Networks

LAN보다 훨씬 먼 거리에 있는 장비나 다른 네트워크를 연결하는 네트워크

**캠퍼스 네트워크(CAN)**
>Canmpus Area Networks

대학의 캠퍼스와 같이 동일 지역의 여러 건물에 걸친 네트워크

LAN이나 WAN을 적용하기에 정확히 들어맞지 않는 중간적 네트워크

**도시권 네트워크(MAN)**
>Metropolitan Area Networks

LAN과 WAN 중간에 위치한 네트워크

특정 지역 또는 도시에 걸친 네트워크

## 세그먼트, 네트워크, 서브네트워크, 인터네트워크
>네트워크의 상대적인 크기와 일부분을 설명하기 위한 용어
---

**네트워크**
>수천 혹은 수만 대의 머신이 연결된 것

**서브네트워크(서브넷)**
>네트워크의 일부분, 더 큰 네트워크를 구성하는 네트워크

**세그먼트(네트워크 세그먼트)**
>네투워크의 작은 영역

서브네트워크보다 더 작은 것을 의미

**인터네트워크(인터넷)**
>작은 네트워크를 서로 연결하여 이룬 큰 네트워킹 구조

일부 기술에서는 다른 네트워크를 구성 요소로 포함하는 매우 큰 네트워크라는 의미를 갖는다. 

TCP/IP에서 네트워크는 보통 OSI 참조 모델의 2계층에서 이더넷이나 토큰링 기술을 이용하여 연결된 머신, 허브, 스위치 모음을 가리킨다.

인터네트워크는 이러한 네트워크가 3계층에서 연결될 때 구성된다.

**세그먼트**

* 특정 케이블을 지칭하는 말

* 하나의 충돌 도메인을 나타내는 전기적으로 연결된 케이블 모음
> 충돌 도메인 : 일반적으로 한 시점에 오직 하나만이 전송을 할 수 있는 하드웨어 장비의 모음

* TCP에서 전송되는 메시지의 이름

## 인터넷, 인트라넷, 엑스트라넷
---
**인터넷**
>전 세계적으로 연결된 컴퓨터와 그들이 제공하는 서비스와 기능을 포함하는 개념

**인트라넷**
>사적 인터넷처럼 동작하는 내부 네트워크

**엑스트라넷**
>회사 외부의 사람들과 접속을 허용하는 인트라넷
