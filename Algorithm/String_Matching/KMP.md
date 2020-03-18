# KMP 알고리즘

    문자열의 접두사와 접미사가 일치하는 최대 일치 길이를 구해 점프해가며 문자열을 검색하는 알고리즘

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
            i=kmp_table[idx-1]
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