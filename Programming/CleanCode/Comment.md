# 주석

## 주석은 나쁜 코드를 보완하지 못한다.

주석이 필요없는 코드를 짜기위해 노력하자

## 좋은주석

1. 법적인 주석
    > // Copyright ~~
    
    > // GNU General ~~

2. 정보를 제공하는 주석

    ```
    // kk:mm:ss EEE, MMM ,dd, yyyy 형식
    Pattern timeMatcher = Pattern.compile("\\d*:\\d*:\\d* \\w*, \\w*, \\d*, \\d*");
    ```

3. 코드의 의도를 설명하는 주석

4. 결과를 경고하는 주석

5. Todo 주석