# Event

## React에서 Event 처리

```html
<button onClick={activateLasers}>
  Activate Lasers
</button>
```

```html
<a href="#" onclick="console.log('The link was clicked.'); return false">
  Click me
</a>
```

```javascript
function ActionLink() {
  function handleClick(e) {
    e.preventDefault();
    console.log('The link was clicked.');
  }

  return (
    <a href="#" onClick={handleClick}>
      Click me
    </a>
  );
}
```

## Event Handler에 인자 전달

```html
<button onClick={(e) => this.deleteRow(id, e)}>Delete Row</button>
<button onClick={this.deleteRow.bind(this, id)}>Delete Row</button>
```