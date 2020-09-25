# 함수

## 작게 만들어라

함수를 만드는 첫번째 규칙은 '작게 만들어라' 이다.

함수를 만드는 두번째 규칙은 '더 작게 만들어라' 이다.

### 블록과 들여쓰기

if/else, while문 등에 들어가는 블록은 한 줄이어야 한다.

대개 거기서 함수를 호출한다.

그러면 함수가 작아질 뿐만 아니라, 함수 이름을 적절히 짓는다면 코드를 이해하기도 쉬워진다.

또한 함수에서 들여쓰기 수준은 1단, 2단을 넘어서면 안된다.

## 한가지만 해라

함수는 한 가지만을 해야 하며, 그 한가지를 잘 해야 한다.

해당 함수를 의미 있는 다른 이름으로 추출할 수 있다면 그 함수는 여러 작업을 하는 셈이다.

## Switch문

switch문은 분기가 단 두개인 경우에도 너무 길며, 한가지 작업만 하는 switch문도 만들기 어렵다.

민약 switch문을 사용해야 한다면(다형적 객체를 생성하는 불가피한 경우), interface에 switch문을 숨겨 사용한다.

## 서술적인 이름을 사용하라

## 함수 인수

함수의 인수는 최대한 적게 한다.

최선은 입력 인수가 없는 경우이며, 차선은 입력 인수가 1개뿐인 경우다.

## 부수효과

한가지 기능을 수행하면서 함수로 넘어온 인수, 시스템 전역 변수를 수정하지 말자

## 명령과 조회의 분리

## 오류코드보다 예외사용

if를 사용해 오류를 체크하기보다 예외처리를 통해 오류를 처리하자

try/catch 블록은 코드 구조에 혼란을 일으키며, 정상 동작과 오류 처리 동작을 뒤섞기 때문에 try/catch 블록을 별도 함수로 뽑아내는 편이 좋다.

### 오류도 한번에 한가지 작업만

## 코드 반복을 최대한 줄여라

## 함수짜는법

* 처음엔 길고 복잡하게 즉흥적으로 코드를 작성한다.

* 해당 코드에 대한 테스트 케이스를 만든다.

* 코드를 다듬고, 중복을 제거한다. (이 와중에도 코드는 항상 테스트를 통과한다.)