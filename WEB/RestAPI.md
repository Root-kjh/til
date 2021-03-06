# REST API
---

## REST API란

    웹의 장점을 최대한 활용할 수 있는 아키텍처

## 구성

* 자원 - URI

* 행위 - HTTP Method

* 표현

## REST API 디자인 가이드

* URI는 정보의 자원을 표현해야 한다.

* 자원에 대한 행위는 HTTP Method로 표현한다.

### HTTP Method의 역할

* POST : 리소스 생성

* GET : 리소스 조회

* PUT : 리소스 수정

* Delete : 리소스 삭제

### URI 설계

* 슬래시(/)는 계층 관계를 나타내는데 쓰임

* 하이픈(-)은 가독성을 높이는데 사용

* 언더바(_)는 사용하지 않음

* URI 경로에는 소문자가 적합

* 파일 확장자는 포함시키지 않는다.

* 관계명이 복잡할 시 서브 리소스에 명시

    * /users/{userid}/devices (일반적으로 소유 ‘has’의 관계를 표현할 때)

    * /users/{userid}/likes/devices (관계명이 애매하거나 구체적 표현이 필요할 때)

### HTTP 응답 상태 코드

* 200 : 요청의 정상적 수행

* 201 : 리소스 생성의 정상적 수행

---

* 400 : 클라이언트의 요청이 부적절

* 401 : 클라이언트가 인증되지 않은 상태에서 보호된 리소스 요청

* 403 : 유저 인증상태와 관계 없이 응답하고 싶지 않은 리소스를 클라이언트가 요청했을 때 사용

    (403 대신 400 or 404 사용 권고. 403 코드의 경우 리소스가 존재함을 암시)

---

* 301 : 요청한 리소스에 대한 URI가 변경되었을 경우

* 500 : 서버에 문제가 있을 경우

## Spring 에서 Rest API 적용

@RequestMapping을 이용해 method 지정, 변수 매핑 가능

```java
@RequestMapping("/dog/{name}", method= RequestMethod.GET)
public String dog(@PathVariable String name) {
```

### REST API 관련 의존성 설치

RETURN 값을 JSON 형식으로 출력해주는 의존성 설치

```xml
		<dependency>
		    <groupId>com.fasterxml.jackson.core</groupId>
		    <artifactId>jackson-databind</artifactId>
		    <version>2.9.7</version>
		</dependency>
```

### @RestController 적용

@Controller 대신 @RestController를 적용해 Return값이 그대로 출력되게 한다.

### JwtToken

RESTAPI는 세션을 사용하지 않기 떄문에 JwtToken을 이용해 인증