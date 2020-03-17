# 기본 문자열 탐색법

패턴과 문자열을 한 글자씩 검사해가며 확인하는 방식

```python
def find_text(context,keyword):
    key_count=0
    keyword_len=len(keyword)
    pos=0
    count=0
    for ch in context:
        if ch==keyword[key_count]:
            key_count+=1
            if key_count==keyword_len:
                count+=1
                key_count=0
        else:
            key_count=0
        pos+=1
    return count
```