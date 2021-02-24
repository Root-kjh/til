# 완전탐색(Exhaustive Search)

## 연습코드

### 0번부터 차례대로 번호 매겨진 N개의 원소 중 K 개를 고르는 모든 경우

```python
pick_list = []

def pick(n, picked, to_pick):
    if to_pick == 0:
        pick_list.append(list(picked))
        return
    smallest = picked[-1]+1 if picked else 0

    for next in range(smallest, n):
        picked.append(next)
        pick(n, picked, to_pick-1)
        picked.pop()

if __name__ == '__main__':
    N = int(input("Num range : "))
    K = int(input("Pick list size : "))
    pick(N, [], K)
    print('\n'.join(str(picked) for picked in pick_list))
```

### 보글 게임

보글은 5*5의 알파벳 격자를 가지고 하는 게임입니다.

이때 게임의 목적은 상하좌우/대각선으로 인접한 칸들의 글자들을 이어서 단어를 찾아내는 것입니다.

각 글자들은 대각선으로도 이어질 수있으며, 한 글자가 두 번 이상 사용될 수 있습니다.

보글게임판(y, x)에서 시작하는 단어 word의 존재를 반환

```python
Boggle = [
            ['U', 'R', 'L', 'P', 'M'],
            ['X', 'P', 'R', 'E', 'T'],
            ['G', 'I', 'A', 'E', 'T'],
            ['X', 'T', 'N', 'Z', 'Y'],
            ['X', 'O', 'Q', 'R', 'S']
        ]

DX = [-1, -1, -1, 1, 1, 1, 0, 0]
DY = [-1, 0, 1, -1, 0, 1, -1, 1]

def is_in_range(y, x):
    return 0<=y and 5>y and 0<=x and 5>x

def has_word(y, x, word, count):
    if not is_in_range(y, x):
        return False

    if Boggle[y][x] != word[count]:
        return False

    if count==len(word)-1:
        return True

    for i in range(8):
        nextY = y+DY[i]
        nextX = x+DX[i]
        if has_word(nextY, nextX, word, count+1):
            return True

if __name__ == '__main__':
    word = input("Type word : ")
    for y in range(5):
        for x in range(5):
            if has_word(y, x, word, 0):
                print(True)
                exit()
    print(False)
```