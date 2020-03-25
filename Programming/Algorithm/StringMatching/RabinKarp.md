# 라빈-카프 알고리즘

패턴 문자열의 길이만큼 문자열을 잘라 해쉬화 한 값을 비교한다.

해쉬 충돌 문제 때문에 같은 해쉬를 찾으면 해당 문자열이 같은지 한번 더 비교한다.

    이유는 모르겠지만 기본 알고리즘보다 성능이 좋지 않았다.

```python
def rabin_karp(context, keyword):
    modules=101
    alphabet_size=256
    keyword_len=len(keyword)
    context_len=len(context)
    keyword_hash=0
    context_hash=0
    power=1
    count=0
    for idx in range(keyword_len):
        context_hash=(ord(context[idx])+context_hash*alphabet_size)%modules
        keyword_hash=(ord(keyword[idx])+keyword_hash*alphabet_size)%modules
        if idx==keyword_len-1:
            continue
        power=(power*alphabet_size)%modules

    for idx in range(0,context_len-keyword_len+1):
        if context_hash==keyword_hash and context[idx:idx+keyword_len]==keyword:
            count+=1
        if idx==context_len-keyword_len:
            continue
        context_hash=(
            (context_hash-ord(context[idx])*power)*alphabet_size
            +ord(context[idx+keyword_len])
        )%modules
    return count
```

