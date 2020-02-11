# JSX

## JSX란

HTML과 비슷한 문법으로, 작성시 React.createElement를 사용하는 Javascript 형태로 변환되는 언어

## Javascript에서 JSX 사용

```javascript
function getGreeting(user) {
  if (user) {
    return <h1>Hello, {formatName(user)}!</h1>;
  }
  return <h1>Hello, Stranger.</h1>;
}
```

## JSX에서 Javascript 변수 사용

```javascript
const element = <img src={user.avatarUrl}></img>;
```