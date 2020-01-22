# N-Queen

    N*N 크기의 체스판이 주어졌을 때, 서로 공격할 수 없는 N개의 Queen을 놓는 경우의 수를 구하는 알고리즘

## BackTracking 알고리즘

![BackTracking](http://sooyoung32.github.io/assets/img/queens4_backtrack.png)

[BackTracking](/Algorithm/BackTracking)

```python
count=0
n=int(input())
stack=list()
Flag=True
for j in range(n):
    stack.append([0,j,[[0,j]]])
while stack:
    node=stack.pop()
    if node[0]==(n-1):
        count+=1
        continue
    i=node[0]
    for j in range(n):  
        Flag=True  
        for queen in node[2]:
            if j==queen[1] or abs(queen[1]-j)==(i+1-queen[0]):
                Flag=False
                break
        if Flag:
            stack.append([i+1,j,node[2]+[[i+1,j]]])
print(count)
```

BackTracking Algorithm을 이용해 유망성 노드만 탐색한다.

