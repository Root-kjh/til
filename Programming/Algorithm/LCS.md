# LCS(Longest Common Subsequence, 최장 공통 부분 수열)

## 문제

LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

## 입력

첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

## 출력

첫째 줄에 입력으로 주어진 두 문자열의 LCS를 출력한다.

## 풀이

```python
if __name__ == '__main__':
    string_one = input()
    string_two = input()
    string_one_len = len(string_one)
    string_two_len = len(string_two)
    dp = [[0 for j in range(string_one_len+1)] for i in range(string_two_len+1)]

    for i in range(1, string_two_len+1):
        for k in range(1, string_one_len+1):
            dp[i][k] = dp[i-1][k]
        for j in range(1, string_one_len+1):
            if string_two[i-1] == string_one[j-1]:
                temp = dp[i][j-1]+1
                if temp>dp[i][j]:
                    for k in range(j, string_one_len+1):
                        dp[i][k] = temp
                        
    temp=0
    result=list()
    for i in range(string_one_len):
        if dp[string_two_len][i]>temp:
            result.append(string_one[i-1])
            temp=dp[string_two_len][i]
    print(''.join(result))
```