# OSI 7계층

    네트워크에서 통신이 일어나는 과정을 7단계로 나눈 것

### 물리계층(Physical)

통신 케이블을 이용한 데이터 전송

통신 단위는 비트이며 0과 1로 나타내어진다.

대표적인 장비로 통신 케이블, 허브 등이 있다.

### 데이터 링크계층(DataLink)

MAC 주소 부여, 에러검출(CRC), 재전송, 흐름제어 기능을 한다.

대표적인 장비로 브리지, 스위치 등이 있다.



### 네트워크계층(Network)

IP주소 부여, 라우팅 기능을 한다.

TCP/IP에서 IP계층이 네트워크 계층의 역할을 한다.

대표적인 장비로 라우터가 있다.

### 전송계층(Transport)

패킷생성 및 전송 기능을 한다.

가장 잘 알려진 전송계층의 예는 TCP이다.

* TCP : 신뢰적인 전송을 보장한다.(패킷의 손실, 중복, 순서 바뀜 등이 없도록 보장)
* UDP : 헤더가 단순하고 신뢰성이 없으나 속도가 빨라 실시간 응용에 적합

### 세션계층(Session)

양 끝단의 응용 프로세스가 통신을 관리하기 위한 방법을 제공한다.

동시 송수신 방식(deplex), 반이중 방식(half-duplex), 전이중 방식(Full Duplex)의 통신과 함께 체크 포인팅, 유휴, 종료, 다시시작 과정을 수행한다.

TCP/IP 세션을 만들고 없애는 책임을 진다.
(운영체제가 해줌)

### 표현 계층(Presentation)

사용자의 명령어를 완성 및 결과 표현, 포장/압축/암호화를 진행한다.

MIME인코딩, 암호화등의 동작이 이 계층에서 이루어진다.

해당 데이터가 TEXT, GIF, JPG인지 구분하는 역할을 한다.

### 응용 계층(Application)

최종 목적지로서 HTTP, FTP, SMTP등의 프로토콜이 있다.

응용 프로세스와 직접 관계하여 일반적인 응용 서비스를 수행한다.