# Spring Security
---

## Spring Security란

    인증과 권한을 담당하는 프레임워크

* 인증(Authentication) : 애플리케이션의 작업을 수행할 수 있는 주체인지 인증

* 권한(Authhorization) : 권한 승인이 필요한 부분으로 접근하려면 인증 과정을 통해 주체가 증명 되어야 함

## Spring Security의 구조

1. 로그인 시도(http request)

2. AuthenticationFilter에서 UserDB검색

3. 인증이 성공하면 User Session 생성

4. spring security의 인메모리 세션저장소 SecurityContextHolder에 저장

5. 유저에게 session ID와 함께 응답을 내려줌

6. 이후 요청에서 JESSIONID로 검증

