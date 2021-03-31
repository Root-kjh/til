# Typescript 기본 문법

### Types

* Boolean
```ts
let isDone: boolean = false;
```

* Number
```ts
let decimal: number = 6;
let hex: number = 0xf00d;
let binary: number = 0b1010;
let octal: number = 0o744;
```

* String
```ts
let color: string = "blue";
color = "blue";
let age:number = 21;

let sentence: string = `Hello, my Age is ${ age+1 }.
my favorite color is ${ color }`;
```

* Array
```ts
let list: number[] = [1, 2, 3];
let list: Array<number> = [1, 2, 3];
```

* Tuple
```ts
let x: [strimg, number];
x = ["hello", 10]
x = [10, "hello"] // error
```

* Enum
```ts
enum Color {Red, Green, Blue}
let c: Color = Color.Green; // 1

enum Color {Red = 1, Green, Blue}
let c: Color = Color.Green; // 2

enum Color {Red = 1, Green = 2, Blue = 4}
let c: Color = Color.Blue; // 4

enum Color {Red = 1, Green = 2, Blue = 4}
let colorName: string = Color[2]; // Green
```

* Any
```ts
let notSure: any = 4;
notSure = "maybe a string instead";
notSure = false;
```

* Void
```ts
function warnUser(): void {
    console.log("This is my warning message");
}

let unsable: void = undefined;
unsable = null;
```

* Never
```ts
function invalid(message:string): never{
    throw new Error(message);
}

function fail(){
    return invalid('fail');
}

let never_type: never;
never_type = (function():never { throw new Error('ERROR')})();
```

* Custom
```ts
type operation = {
    data: number[],
    output: (num:number)=>number[]
}

let sum:operation = {
    data: [10, 30, 60],
    output(num){
        return this.data.map(n=>n+num)
    }
}
```