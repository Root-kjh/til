# 라빈-카프 알고리즘

패턴 문자열의 길이만큼 문자열을 잘라 해쉬화 한 값을 비교한다.

해쉬 충돌 문제 때문에 같은 해쉬를 찾으면 해당 문자열이 같은지 한번 더 비교한다.

    이유는 모르겠지만 기본 알고리즘보다 성능이 좋지 않았다.

```python
def rabin_karp(context, keyword):
    keyword_len=len(keyword)
    context_len=len(context)
    keyword_hash=0
    context_hash=0
    power=1
    count=0
    for idx in range(context_len-keyword_len+1):
        if idx==0:
            for sub_idx in range(keyword_len):
                context_hash+=ord(context[keyword_len-1-sub_idx])*power
                keyword_hash+=ord(keyword[keyword_len-1-sub_idx])*power
                if sub_idx<keyword_len-1:
                    power*=2
            if context_hash==keyword_hash:
                count+=1
        else:
            context_hash=2*(context_hash-ord(context[idx-1])*power)+ord(context[keyword_len-1+idx])
            # print(f'idx : {idx} hash : {context_hash}')
            if context_hash==keyword_hash:
                count+=1
                # print(context[idx:idx+keyword_len])
    return count
```

