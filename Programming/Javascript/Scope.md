# 유효범위(Scope)

## var의 의미

```javascript
var vscope='global';

function fscope(){
    var vscope='local';
}

fscope();
alert(vscope);
```

    global 출력

```javascript
var vscope='global';

function fscope(){
    vscope='local';
}

fscope();
alert(vscope);
```

    local 출력

함수 안의 변수가 var로 선언된다면 같은 이름의 전역변수가 따로 생성되먀, var이 없다면 global 변수의 값을 수정한다는 것을 알 수 있다.

```java

for(int i=0;i<5;i++){
    String temp="test";
}
System.out.println(temp);
```

    temp 변수를 찾을 수 없어 오류 선언

```javascript
for(var i=0;i<5;i++){
    var temp="test";
}
console.log(temp);
```

    temp 변수 정상 출력

Javascript는 함수 안에서 선언된 변수 만이 그 함수의 지역변수가 되고, if, for 등의 안에서 선언된 변수는 지역변수의 성격을 갖지 않는다.

```javascript
var i=5;

function a(){
    var i=10;
    b();
}

function b(){
    document.write(i);
}
```

b 함수는 함수가 

Javascript는 함수가 선언된 시점에서의 유효범위를 갖는다. 이러한 방식을 정적 유효범위(Static Scoping), 렉시컬(Lexical Scoping)이라고 한다.

