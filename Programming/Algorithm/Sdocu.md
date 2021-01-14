# 스도쿠 풀이 알고리즘

    스도쿠 문제를 풀이하는 알고리즘

## 기본적인 스토쿠 풀이 전략

### 1.

0 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
- | - | - | - | - | - | - | - | -
2 |
3 |
4 |
5 |
6 |
7 |
8 |
9 |

해당 표에서 가로, 세로를 탐색해 0의 자리에 1을 넣는다.

### 2.

1 | 2 | 3
- | - | -
4 | 0 | 6
7 | 8 | 9

해당 표에서는 0의 자리에 해당하는 블록을 탐색해 5를 넣는다.

### 풀이 전략을 바탕으로 한 코드 작성

 스도쿠의 모든 칸을 탐색하며, 0을 만날 경우 위에서 설명한 2가지의 풀이 전략을 이용해 0의 자리를 채우며, 모든 0을 채울 때까지 반복한다.

```python
sdocu_size = 9

sdocu_array = [[0 for j in range(9)] for i in range(9)]

for i in range(sdocu_size):
    sdocu_array[i]=list(map(int, input().split()))

zero_flag = True
while zero_flag:
    zero_flag = False
    for i in range(sdocu_size):
        for j in range(sdocu_size):
            if sdocu_array[i][j] == 0:
                zero_flag = True

                count = 45
                flag = True
                for k in range(sdocu_size):
                    if k == i:
                        continue
                    if sdocu_array[k][j] == 0:
                        flag = False
                        break
                    else:
                        count -= sdocu_array[k][j]
                if flag:
                    sdocu_array[i][j] = count
                    break

                count = 45
                flag = True
                for k in range(sdocu_size):
                    if k == j:
                        continue
                    if sdocu_array[i][k] == 0:
                        flag = False
                        break
                    else:
                        count -= sdocu_array[i][k]
                if flag:
                    sdocu_array[i][j] = count
                    break

                count = 45
                flag = True
                temp_i = i%3
                temp_j = j%3
                domain_i = i-(temp_i)
                domain_j = j-(temp_j)
                for k in range(3):
                    for m in range(3):
                        if k == temp_i and m == temp_j:
                            continue
                        if sdocu_array[domain_i+k][domain_j+m] == 0:
                            flag = False
                            break
                        else:
                            count -= sdocu_array[domain_i+k][domain_j+m]
                    if not flag:
                        break
                if flag:
                    sdocu_array[i][j] = count

print("\n".join([" ".join(str(j) for j in i) for i in sdocu_array]))
```

## 약간 응용한 풀이 전략

### 1. (Hidden Single)

0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 3
- | - | - | - | - | - | - | - | -
0 | 4 | 2 | 0 | 0 | 0 | 0 | 0 | 0
0 | 7 | 0 | 0 | 0 | 0 | 0 | 0 | 0
0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0

해당 표의 첫번째 블록에서 3이 들어갈 자리는 (3, 3) 밖에 없다.

### 2. (Naked Single)

0 | 0 | 0 | 0 | 0 | 0 | 0 | 8 | 3
- | - | - | - | - | - | - | - | -
0 | 4 | 2 | 0 | 0 | 0 | 0 | 0 | 0
0 | 7 | 6 | 0 | 0 | 0 | 0 | 0 | 0
0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
5 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0

해당 표의 첫번째 블록에서 (1, 1) 자리에는 9만 들어갈 수 있다.

### 풀이 전략을 바탕으로 한 코드 작성

두 개의 풀이 전략을 이용하면 빈칸에 들어갈 숫자의 범위를 좁히는 방향으로 전 알고리즘보다 한번의 탐색에 더 많은 빈칸을 채울 수 있다.

```python
sdocu_size = 9

sdocu_array = [[[0 for k in range(10)] for j in range(9)] for i in range(9)]

for i in range(sdocu_size):
    j = 0
    for num in list(map(int, input().split())):
        sdocu_array[i][j][0] = num
        j+=1

zero_flag = True
while zero_flag:
    zero_flag = False
    for i in range(sdocu_size):
        for j in range(sdocu_size):
            if sdocu_array[i][j][0] == 0:
                zero_flag = True
                flag_table = [1] * 10
                for k in range(sdocu_size):
                    if sdocu_array[k][j][0] != 0:
                        flag_table[sdocu_array[k][j][0]] = 0

                for k in range(sdocu_size):
                    if sdocu_array[i][k][0] != 0:
                        flag_table[sdocu_array[i][k][0]] = 0
                temp_i = i%3
                temp_j = j%3
                domain_i = i-(temp_i)
                domain_j = j-(temp_j)
                for k in range(3):
                    for m in range(3):
                        if sdocu_array[domain_i+k][domain_j+m][0] != 0:
                            flag_table[sdocu_array[domain_i+k][domain_j+m][0]] = 0
                flag = True
                num = 0
                for n in range(1, 10):
                    if flag_table[n] == 1:
                        if num != 0:
                            flag = False
                        else:
                            num = n
                if flag:
                    sdocu_array[i][j][0] = num

print("\n".join([" ".join(str(j[0]) for j in i) for i in sdocu_array]))
```

## 탐색 전략

    일반 사람의 생각처럼 일정한 규칙에 의해 채워넣는것이 아닌 무작위의 수를 넣고 답을 찾을 때까지 하나하나 시도해 보는 방법

빈 수도쿠에 무작위의 수를 순서대로 넣고 답을 찾게되면 경우의 수는 9^81로, 196627050475552913618075908526912116283103450944214766927315415537966391196809 가지의 경우의 수가 있다.

실제로 무작위 숫자 하나를 넣고 검사하는것을 하나의 연산이라고 해도 초당 14경 8600조의 연산을 하는 슈퍼컴퓨터로 42498152141377242110626082522156542060704657066823747년이 걸리는 연산이다.

