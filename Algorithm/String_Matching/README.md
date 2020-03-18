# 문자열 탐색 알고리즘

    주어진 문자열 중 패턴과 일치하는 문자열을 찾는 알고리즘

1. [Default](/Algorithm/String_Matching/default.md)

2. [Rabin Karp](/Algorithm/String_Matching/Rabin_Karp.md)

3. [KMP](/Algorithm/String_Matching/KMP.md)


```python
import sys
import os
import timeit

def rabin_karp(context, keyword):
    keyword_len=len(keyword)
    keyword_idx_max=keyword_len-1
    context_len=len(context)
    keyword_hash=0
    context_hash=0
    power=1
    count=0
    for idx in range(context_len-keyword_len+1):
        if idx==0:
            for sub_idx in range(keyword_len):
                context_hash+=ord(context[keyword_idx_max-sub_idx])*power
                keyword_hash+=ord(keyword[keyword_idx_max-sub_idx])*power
                if sub_idx<keyword_idx_max:
                    power*=2
            if context_hash==keyword_hash:
                count+=1
        else:
            context_hash=2*(context_hash-ord(context[idx-1])*power)+ord(context[keyword_idx_max+idx])
            if context_hash==keyword_hash:
                count+=1
    return count

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
                sub_idx=kmp_table[sub_idx]
            else:
                sub_idx+=1
    return count

def readfile_read(file_dir):
    try:
        with open(file_dir,'r') as file: # 파일 오픈
            return file.read()
    except OSError as e:
        exit("can't open file")

if __name__ == '__main__':
    if len(sys.argv)!=3: # 인자의 수 확인
        exit("argv is incorrect")

    from_word=sys.argv[1]
    in_file=sys.argv[2]
    context=readfile_read(in_file)
    number=10
    print("count : "+str(timeit.timeit('context.count(from_word)',globals=globals(),number=number)))
    print("kmp : "+str(timeit.timeit('kmp(context,from_word)',globals=globals(),number=number)))
    print("rabin karp : "+str(timeit.timeit('rabin_karp(context,from_word)',globals=globals(),number=number)))
    print("default : "+str(timeit.timeit('default(context,from_word)',globals=globals(),number=number)))
```

```
count : 0.0018466000000000038
kmp : 0.4254551
rabin karp : 0.7186627999999999
default : 0.6225997000000001
```

모든 알고리즘의 실행 결과는

1. count함수
3. KMP 알고리즘
2. Default 알고리즘
4. Rabin-Karp 알고리즘
의 순서로 나왔다.