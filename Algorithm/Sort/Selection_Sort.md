# 선택 정렬(Selection Sort)

>해당 순서에 원소를 넣을 위치는 이미 정해져 있고, 어떤 원소를 넣을지 선택하는 알고리즘

* 시간복잡도는 최선, 최악 모두 O(n^2)으로 동일하다.

* 정렬 알고리즘 중 가장 직관적이고 쉽게 구현 가능하다.

* Bubble Sort에 비해 실제 교환 횟수가 적기 때문에 많은 교환이 일어나야 하는 자료상태에서 효율적이다.

* 다른 메모리 공간을 필요로 하지 않는다.

* 불안정 정렬이다.

    정렬되지 않은 상태에서 같은 키값을 가진 원소의 순서가 정렬후에 유지되지 않음

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