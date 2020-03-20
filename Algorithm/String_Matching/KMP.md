# KMP 알고리즘

    문자열의 접두사와 접미사가 일치하는 최대 일치 길이를 구해 점프해가며 문자열을 검색하는 알고리즘

* 접두사와 검사하는 글자 수 마다 패턴의 접미사가 일치하는 최대 길이 테이블을 구한다.

* 문자열과 패턴을 비교하던 중, 문자가 같지 않을 경우 마지막 일치 문자까지 되돌아간다.

```python
def kmp(context,keyword):
    keyword_len=len(keyword)
    keyword_max_idx=keyword_len-1
    context_len=len(context)
    kmp_table=[0]*keyword_len
    sub_idx=1
    idx=0
    count=0
    
    while sub_idx<keyword_len:
        if keyword[idx]==keyword[sub_idx]:
            idx+=1
        elif idx>0:
            idx=kmp_table[idx-1]
            continue
        kmp_table[sub_idx]=idx
        sub_idx+=1
    
    idx=0
    sub_idx=0

    while idx<context_len:
        if keyword[sub_idx]==context[idx]:
            if sub_idx==keyword_max_idx:
                count+=1
                sub_idx=0
            sub_idx+=1

        elif sub_idx>0:
            sub_idx=kmp_table[sub_idx-1]
            continue
        idx+=1
    return count
```