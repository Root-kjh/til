# Concept

    Typescript를 시작하기 전 알아둬야 할 개념

### Javascript의 짧은 역사

Javascript는 브라우저를 위한 스크립팅 언어로, 웹 페이지 속 짧은 코드들을 위해 사용할 것으로 여겨졌다.

그러나 시간이 흘러 JS가 유명해지면서, 웹 개발자들은 JS를 이용해 상호작용을 하는 경험을 하기 시작했다.

웹 브라우저 개발자들은 실행 엔진을 최적화 시키고 할 수 있는 일을 확장하여 웹 개발자가 더 많이 JS를 사용할 수 있게 했다.

하지만 이로인해 많은 문제를 만들게 되었다. 예를들어

```js
if ("" == 0) // True
if (1 < x < 3) // Any value of x is true.

const obj = { width: 10, height: 15 };
const area = obj.width * obj.heigth; // area = Nan
```

Javascript의 동일 연산자는 인수를 강제로 변환하여 예기치 않은 동작을 유발하고, 존재하지 않는 프로퍼티의 접근을 허용한다.

이는 수백에서 수천줄의 어플리케이션을 작성할때 심각한 문제로 다가왔다.

### Typescript: A Static Type Checker

정적타입 검사자인 Typescript는 프로그램을 실행시키기 전엥 값의 종류를 기반으로 프로그램의 오류를 찾는다.

### Typescript: A Typed Superset of Javascript

##### 구문(Syntax)

Typescript는 js의 구문이 허용되는, js의 상위 집합 언어이다.

Typescript는 독특한 구문 때문에 Javascript 코드를 오류로 보지 않는다.

즉, 어떻게 작성되었는지 모르지만 작동하는 Javascript 코드를 Typescript 파일에 넣어도 잘 작동한다.

##### 타입(Types)

그러나 Typescript는 다른 종류의 값들을 사용할 수 있는 방법이 추가된, 타입이 있는 상위 집합이다.

위의 obj.heigth 오류는 구문 오류가 아닌, 값의 타입을 잘못 사용해서 생긴 오류가 된다.

또 다른 예시로, 아래와 같은 Javascript 코드가 브라우저에서 실행될 때, 다음과 같은 값이 출력된다.

```ts
console.log(4 / []); // @errors: 2363
```

구문적으로 옳은 위 코드는 Javascript에서 NaN을 출력하지만, Typescript에서 배열로 숫자를 나누는 연산이 옳지 않다고 판단해 오류를 발생시킨다.

##### 런타임 특성

Typescript는 Javascript의 런타임 특성을 가진 프로그래밍 언어로, Javascript 코드의 런타임 특성을 절대 변화시키지 않는다.

##### 삭제된 타입

Typescript의 컴파일러가 코드 검사를 마치면 타입을 삭제해 컴파일된 코드를 만든다.

즉, 코드가 한번 컴파일되면 결과로 나온 일반 JS코드에는 타입 정보가 없다.

결론적으로 컴파일 도중 타입 오류가 표출될 수 있지만, 타입 시스템 자체는 프로그램이 실행될 때 작동하는 방식과 관련이 없다. 