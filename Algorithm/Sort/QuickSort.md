# 퀵 정렬(Quick Sort)
> 분할 정복 알고리즘의 하나로, 평균적으로 매우 빠른 수행속도를 자랑한다.

## 퀵 정렬의 과정

* 리스트 안의 한 요소를 선택한다. 이 요소를 피벗(pivot) 이라 부른다.

* 피벗을 기준으로 피벗보다 작은 요소들은 모두 피벗의 왼쪽으로, 큰 요소들은 오른쪽으로 옮겨진다.

* 피벗을 제외한 왼쪽 리스트와 오른쪽 리스트를 다시 정렬한다.

    * 분할된 부분 리스트에 대해 순환 호출을 이용해 정렬을 반복한다.

* 부분 리스트의 크기가 0이나 1이 될 때까지 반복한다. 

```python
table=[4,1,7,6,3,8,2,5]

def Quick_Sort(low,high):
    global table

    if high-low<1:
        return

    tlow=low
    thigh=high
    pivot=high
    high-=1
    while high>=low:
        while table[low]<table[pivot] and low<=thigh:
            low+=1
        while table[high]>table[pivot] and high>=tlow:
            high-=1
        if high>low:
            temp=table[high]
            table[high]=table[low]
            table[low]=temp
            low+=1
            high-=1
    temp=table[low]
    table[low]=table[pivot]
    table[pivot]=temp
    Quick_Sort(tlow,low-1)
    Quick_Sort(low+1,thigh)

if __name__ == "__main__":
    Quick_Sort(0,len(table)-1)
    print(table)
```