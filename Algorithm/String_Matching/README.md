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
count : 0.0014093999999999982
kmp : 0.4736629
rabin karp : 1.2707847
default : 0.5837794999999999
```

모든 알고리즘의 실행 결과는

1. count함수
3. KMP 알고리즘
2. Default 알고리즘
4. Rabin-Karp 알고리즘
의 순서로 나왔다.