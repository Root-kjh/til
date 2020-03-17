# 거품 정렬(Bubble Sort)

>서로 인접한 두 원소의 대소를 비교하고, 조건에 맞지 않다면 자리를 교환하며 정렬하는 알고리즘

* 시간 복잡도 O(n^2), 공간복잡도 O(n2)

* 구현이 매우 간단하고 코드가 직관적이다.

* 배열 안에서 교환하는 방식으로, 별도의 메모리 공간이 필요하지 않다.

* 시가 복잡도가 어떤 상황에서도 O(n^2)으로, 비효율적이다.

```python
def Bubble_Sort(arr):
    length=len(arr)
    for i in range(length,0,-1):
        for j in range(1,i):
            if arr[j]<arr[j-1]:
                temp=arr[j]
                arr[j]=arr[j-1]
                arr[j-1]=temp
    return arr
```