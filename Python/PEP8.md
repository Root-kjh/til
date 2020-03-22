 # PEP8
 
    파이썬 코드 작성을 위한 가이드

# Code Layout

## 들여쓰기

    들여 쓰기 레벨 당 4 개의 공백 사용

연속되는 문장은 괄호를 이용해 수직으로 정렬되거나, 'hanging indent'를 사용해야 한다.

* 좋은 예

```python
# 여는 구분기호로 정렬되는 경우
foo = long_function_name(var_one, var_two,
                      var_three, var_four)

# 추가적인 들여쓰기로 나머지 코드 구분
def long_function_name(
        var_one, var_two, var_three,
        var_four):
    print(var_one)

# hanging indent는 반드시 한 레벨을 추가한다.
foo = long_function_name(
    var_one, var_two,
    var_three, var_four)

# hanging indent의 경우 반드시 4칸 띄어쓰기를 사용하지 않아도 된다.
foo = long_function_name(
  var_one, var_two,
  var_three, var_four)

if 문의 경우 조건문과 if문 내의 문장의 구분을 위해 여러 선택지를 제공한다.

```python
# 추가적인 들여쓰기를 사용하지 않음
if (this_is_one_thing and
    that_is_another_thing):
    do_something()

# 주석을 추가해 조건문과 나머지 코드 구분
if (this_is_one_thing and
    that_is_another_thing):
    # 두 조건문이 만족되면 아래를 실행
    do_something()

# 추가적인 들여쓰기를 통해 조건문과 나머지 코드 구분
if (this_is_one_thing
        and that_is_another_thing):
    do_something()
```

여러 줄 생성자의 닫히는 괄호는 마지막 줄의 공백이 아닌 첫번째 요소 위치에 오거나 마지막 줄에서 생성자가 시작되는 첫번째 열에 위치한다.

```python
my_list = [
    1, 2, 3,
    4, 5, 6,
    ]

result = some_function_that_takes_arguments(
    'a', 'b', 'c',
    'd', 'e', 'f',
    )

my_list = [
    1, 2, 3,
    4, 5, 6,
]

result = some_function_that_takes_arguments(
    'a', 'b', 'c',
    'd', 'e', 'f',
)
```

## Tap or Spaces

    들여쓰기는 space가 권장 된다.

tap은 이미 tap으로 들여쓰기가 사용된 코드에서만 단독으로 사용되며, 파이썬3에서 space와 tap의 혼용을 금한다.

## Maximum Line Length

    모든 코드는 한 줄에 최대 79자까지 쓰는 것을 허용한다.

여러 줄로 길게 표현되는 문장은 괄호를 이용해 여러 행으로 분리해 표현한다.

백슬래시를 사용해 연속 되는 문장의 줄바뀜을 표현하는 것도 좋다.

```python
with open('/path/to/some/file/you/want/to/read') as file_1,\
     open('/path/to/some/file/being/written', 'w') as file_2:
    file_2.write(file_1.read())
```

## Should a line break before or after a binary operator

    PEP은 연산자의 앞에서 줄바꿈을 하는 것을 권장한다.

```python
income = (gross_wages
          + taxable_interest
          + (dividends - qualified_dividends)
          - ira_deduction
          - student_loan_interest)
```

## Blank Lines

Top-level 함수와 클래스 정의부는 2개의 빈줄을 이용해 구분한다.

클래스 속 메소드는 한 개의 빈줄을 이용해 구분한다.

## Source File Encoding

파이썬3은 항상 UTF-8 방식을 사용한다.

## Import

임포트는 반드시 행을 분리해 선언한다.

```python
import os
import sys
```

임포트는 절대경로를 이용한 절대 임포트가 권장된다.

```python
import mypkg.sibling
from mypkg import sibling
from mypkg.sibling import example
```

복잡한 레이아웃을 가진 패키지에서는 명시적 상대 임포트가 허용된다.

```python
from . import sibling
from .sibling import example
```

Module level dunder names

모듈레벨의 dunder은(\_\_all__, \_\_future__ 등)은 Docstring 뒤, import 앞에 와야한다.

단, from \_\_future__ import는 docstring 바로 뒤, 그 어떤 코드보다 먼저 위치해야 한다.

```python
For example:

"""This is the example module.
This module does stuff.
"""

from __future__ import baarry_as_FLUFL

__all__ = ['a', 'b', 'c']
__version__ = '0.1'
__author__ = 'Cardinal Biggles'

import os
import sys
```

# String Quotes(따옴표)

문자열 표현 시 따옴표는 자유롭게 사용하되, 가독성을 위해 이스케이프 문자 사용을 피하도록 적절히 따옴표를 선택한다.

세 개의 따옴표를 사용할 때에는 반드시 쌍따옴표를 사용한다. (\"\"\")

# Whitespacce in Expressions and Statements

## Pet peeves

아래와 같은 상황에서 무의미한 공백을 피한다.

* 괄호 안의 양쪽 끝

```python
spam(ham[1], {eggs: 2})
```

* 콤마, 세미콜론, 콜론 바로 앞

```python
if x==4: print x, y; x, y = y, x
```

슬라이스에서 콜론은 우선순위가 낮은 이항연산자와 유사한 방식으로 사용되며, 양쪽에 동일한 공간을 할당해야 한다.

확장된 슬라이스에서 모든 콜론은 같은 크기의 공간이 할당되어야 한다.

피연산자가 누락되었을 경우, 공백 또한 주지 않는다.

```python
ham[1:9], ham[1:9:3]. ham[0:9]. ham[1::3], ham[1:9:]
ham[lower:upper], ham[lower:upper:], ham[lower::step]
ham[lower+offset : upper+offset]
ham[: upper_fn(x) : step_fn(x), ham[:: step_fn(x)]]
ham[lower + offset : upper + offset]
```
* 함수 호출시 인자를 넣기 위한 소괄호의 바로 앞

```python
spam(1)
```

* 리스트, 사전의 인덱스나 슬라이스에 사용되는 대괄호의 바ㅡ로 앞

```python
dct['key'] = lst[index]
```

* 대입 연산자의 앞뒤는 공백을 준다.

```python
x = 1
y = 2
long_variable = 3
```

* 문장의 마지막에 따라오는 공백을 없게 한다.
* 모든 이항연산자 앞뒤로는 공백을 둔다.
* 우선순위가 다른 연산자를 사용할 경우, 낮은 순위의 연산자에 공백을 준다.
* 절대 한 칸을 초과하는 공백은 사용하지 않으며, 이항연산자의 양쪽은 같은 공백을 가진다.

```python
i = i + 1
submitted += 1
x = x*2 - 1
hypot2 = x*x + y*y
c = (a*b) * (a-b)
```

* 키워드 인자나 디폴트 인자에 사용되는 대입연산자는 공백을 사용하지 않는다.

```python
def complex(real, imag=0.0):
    return magic(r=real, i=imag)
```

* function annontation에 사용되는 콜론은 기존 룰을 따르며, '->'는 양 옆에 공백을 한 칸씩 가진다.

```python
def munge(input: AnyStr): ...
def munge() -> AnyStr: ...
```

* argument annontation을 디폴트 변수에 사용할 때, 기존 디폴트 변수에 사용할때의 공백 없는 대입연산자와 다르게 대입연산자 앞 뒤에 공백을 한 칸씩 가진다.

```python
def munge(sep: AnyStr = None): ...
def munge(input: AnyStr, sep: AnyStr = None, limit=1000): ...
```

* 여러 구문이 한 줄에 오는 것은 권장하지 않는다.

```python
if foo == 'blah':
    do_blah_thing()
do_one()
do_two()
do_three()
Rather not:
```

* 가끔 짦은 몸체의 if, for, while 문에서는 여러 구문을 한 줄에 써도 되지만, 절대 여러 줄의 절에서는 한 줄에 쓰면 안된다.
* 또한 긴 줄에서 폴딩은 피해야한다.

```python
Rather not:

if foo == 'blah': do_blah_thing()
for x in lst: total += x
while t < 10: t = delay()
Definitely not:

if foo == 'blah': do_blah_thing()
else: do_non_blah_thing()

try: something()
finally: cleanup()

do_one(); do_two(); th_three(long, argument,
                             list, like, this)
if foo == 'blah': one(); two(); three()
```
