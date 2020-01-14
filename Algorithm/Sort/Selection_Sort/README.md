# 선택 정렬(Selection Sort)
> 정렬 알고리즘 중 가장 직관적이고 쉽게 구현 가능

## 선택 정렬의 과정

* 리스트 중 가장 작은 값을 찾아 0번째 요소에 있는 값과 바꾼다.

* 리스트 중 정렬된 값을 제외하고 남은 값 중 가장 작은 값을 n번째 요소에 있는 값과 바꾼다.

* 정렬이 끝날때까지 반복한다.

```python
def Selection_Sort(table):
    count=0
    table_size=len(table)

    while count<table_size:
        minIdx=-1
        minValue=0

        for i in range(count,table_size):    
            if minIdx==-1 or minValue>table[i]:
                minValue=table[i]
                minIdx=i

        temp=table[count]
        table[count]=table[minIdx]
        table[minIdx]=temp

        count+=1

    return table

if __name__ == "__main__":
    table=[5,2,1,3,4]
    Selection_Sort(table)
    print(table)
```