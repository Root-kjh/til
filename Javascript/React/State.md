# State

동적 데이터 사용 시 쓰임

```javascript
class Clock extends React.Component {
  constructor(props) {
    super(props);
    this.state = {date: new Date()};
  }

  render() {
    return (
      <div>
        <h1>Hello, world!</h1>
        <h2>It is {this.state.date.toLocaleTimeString()}.</h2>
      </div>
    );
  }
}
```

## State Update

```javascript
this.setState({comment: 'Hello'});
```

## 생명주기 메서드

### 마운트

    컴포넌트의 인스턴스가 생성되어 DOM 상에 삽입될 때 순서대로 호출

* constructor() : 메서드를 바인딩하거나 state를 초기화하는 작업이 없다면 굳이 구현하지 않아도 된다.

* render() : 반드시 구현되어야 할 유일한 메서드

* componentDidMount()

### 업데이트

    props 또는 state가 변경되어 갱신이 발생할 때(컴포넌트가 다시 랜더링 될 때) 순서대로 호출

* shouldComponentUpdate()

* render()

* getSnapshotBeforeUpdate()

* componentDidUpdate()

### 마운트 해제

    컴포넌트가 DOM 상에서 제거될 때 호출

* componentWillUnmount()


### 오류 처리

    자식 컴포넌트를 렌더링하거나, 자식 컴포넌트가 생명주기 메서드를 호출하거나, 또는 자식 컴포넌트가 생성자 메서드를 호출하는 과정에서 오류가 발생했을 때 호출

* componentDidCatch()
