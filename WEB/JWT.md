# JWT

---

## JWT란

    Json 객체를 사용해 자가수용적 방식으로 정보를 전달하는 토큰

## JWT 구조

    aaaaaaaaa.bbbbbbbb.ccccccccccc
    (Header) (Payload) (Signature)

각 부분에 해당하는 내용을 base64 Eocoding 후 이어 붙인다.

### Header

* Type : 토큰의 타입 지정 (Default : JWT)

* alg : 해싱 알고리즘 지정

### Payload

* Claim : Payload에 담기는 정보의 한 조각, name : value의 형식으로 이루어져있다.

#### Claim

* Registered Claim

    토큰에 대한 정보들을 담기 위해 이름이 이미 정해진 클레임

    * iss : 토큰 발급자

    * sub : 토큰 제목

    * aud : 토큰 대상자

    * exp : 토큰의 만료시간

    * nbf : 토큰의 활성날짜

    * iat : 토큰의 발급시간

    * jti : jwt의 고유 식별자, 주로 중복적인 처리르 방지하기 위해 사용

* Public Claim

    이름의 충돌을 방지하기 위해 클레임 이름을 URI 형식으로 짓는다.

    ```
    {
        "http://recruit-list.kro.kr:8080/user" : true
    }
    ```

* Private Claim

    클라이언트와 서버 합의하에 사용되는 클레임

    ```
    {
        "username" : "test",
        "email" : "test@gmail.com"
    }
    ```

### Signature

Header Encoding, Payload Encoding 값을 합친 후 주어진 비밀키로 Hash화 하여 생성

```
HMACSHA256(
  base64UrlEncode(header) + "." +
  base64UrlEncode(payload),
  secret)
```

### Spring에서 JWT 사용

#### JWT 생성

```java
    Jwts.builder()
    .setHeaderParam("typ", "JWT")
    .setExpiration(new Date(curTime+600000))
    .setIssuedAt(new Date(curTime))
    .claim("user", user.getName())
    .signWith(SignatureAlgorithm.HS256, this.generateKey())
    .compact();
```

#### JWT 사용자 인증

```java
    Jws<Claims> cJws=Jwts.parser()
            .setSigningKey(generateKey())
            .parseClaimsJws(jwt);
    String username=(String) cJws.getBody().get("user");
```