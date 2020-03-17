# KMP 알고리즘

    문자열의 접두사와 접미사가 일치하는 최대 일치 길이를 구해 점프해가며 문자열을 검색하는 알고리즘

```python
def kmp(context,keyword):
    keyword_len=len(keyword)
    context_len=len(context)
    kmp_table=[0]*keyword_len
    sub_idx=0
    count=0
    for idx in range(1,keyword_len):
        while sub_idx>0 and keyword[idx]!=keyword[sub_idx]:
            sub_idx=kmp_table[sub_idx-1]
        if keyword[idx]==keyword[sub_idx]:
            sub_idx+=1
            kmp_table[idx]=sub_idx
    
    sub_idx=0
    for idx in range(context_len):
        while sub_idx>0 and context[idx]!=keyword[sub_idx]:
            sub_idx=kmp_table[sub_idx-1]
        if context[idx]==keyword[sub_idx]:
            if sub_idx==keyword_len-1:
                count+=1
            else:
                sub_idx+=1
    return count
```