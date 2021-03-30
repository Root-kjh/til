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

