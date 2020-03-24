# 기본 문자열 탐색법

패턴과 문자열을 한 글자씩 검사해가며 확인하는 방식

```python
def default(context,keyword):
    key_count=0
    keyword_len=len(keyword)
    pos=0
    count=0
    for idx in range(len(context)-keyword_len+1):
        while True:
            if context[idx+key_count]==keyword[key_count]:
                key_count+=1
                if key_count==keyword_len:
                    count+=1
                    key_count=0
                    break
            else:
                key_count=0
                break
    return count
```