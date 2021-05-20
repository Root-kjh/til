# 들어가기 전에

### 프로그램의 실행 과정(간단한)

실행파일(바이너리)은 Disk에 존재한다.

프로그램을 실행하게 되면 실행파일이 메모리에 적재된다.

메모리에 적재된 바이너리는 CPU에 의해 한 줄 한 줄 실행된다.

### 리눅스와 다른 운영체제의 비교

리눅스를 개발한 토발즈는 Minix를 사용한 지식을 바탕으로 리눅스를 개발했다.

하지만 리눅스의 코드는 Minix와 많이 달랐다.

리눅스는 Monolithic kernel 구조였던 반면, Minix는 Micro kernel 구조였다.

##### Monolithic구조와 Micro구조의 차이

Monolithic kernel구조는 간단히 한 프로그램(운영체제)을 통으로 개발하는 것을 말한다.

Micro kernel구조는 가장 core한 부분을 제외한 나머지를 user영역에서 모듈로 덧붙이는 것을 말한다.

지금 시대의 개발은 마이크로 커널 구조가 더 좋은 구조라고 생각된다.

(Windows도 처음엔 Micro kernel구조로 시작했다.)

하지만 점점 시간이 지나고, 모듈간의 통신이 필요했던 Micro kernel 구조는 시스템 복잡도가 증가할수록 overhead가 급격히 증가했고, 결국 성능 저하라는 단점으로 이어졌다.

Windows는 초기 설계의 많은 부분이 Micro kernel구조지만, 성능에 영향을 미치는 많은 코드들은 Monolithic kernel구조를 닮아있다.