# BootCode

### 컴퓨터의 부팅과정

1. 컴퓨터가 구동되면 전기적 신호에 의해 메인보드의 BIOS가 구동된다.

2. POST(Power On Self Test)를 통해 하드웨어를 점검한다.

3. CMOS설정 정보를 읽어들이고 부팅에 필요한 정보를 획득한다.

4. 하드디스크의 첫번째 섹터인 Master Boot Record(MBR)을 검사하고 로드한다.
> MBR은 전체 512Byte다.

5. 부트로더가 실행되어 커널을 메모리에 적재한다.
> 부트로더에 의해 MBR의 512Byte가 메모리 0x07C0로 로딩된다.

7. 이후 부트로더에 의해 커널이 로드되며, 커널이 로드되면 제어권이 OS로 넘어간다.

### 부트 코드

```assembly
[org 0]
[bits 16]
    jmp 0x7c0:start

start:
    mov ax, cs
    mov ds, ax              ; ds를 cs로 초기화

    mov ax, 0xB800
    mov es, ax              ; es를 0xB800로 초기화(컬러 텍스트 비디오 메모리 주소가 0xB800이다.)
    mov di, 0
    mov cx, 0x7FF           ; cx를 2047로 초기화
    mov ax, word[msg]       ; ax를 '.' 으로 초기화
print:
    mov word[es:di], ax     ;0xB800:di 주소의 메모리를 ax의 값으로 초기화
    add di, 2
    dec cx                  ;cx를 1씩 감소

    jnz print               ;cx가 0이 될때까지 반복

    mov edi, 0
    mov byte[es:edi], 'D'   ;0xB800:0 에서부터 메모리에 글자와 글자색 값을 넣음
    inc edi
    mov byte[es:edi], 0x05  ;글자 색 지정
    inc edi
    mov byte[es:edi], 'r'
    inc edi
    mov byte[es:edi], 0x05
    inc edi
    mov byte[es:edi], '_'
    inc edi
    mov byte[es:edi], 0x05
    inc edi
    mov byte[es:edi], 'K'
    inc edi
    mov byte[es:edi], 0x05
    inc edi

    jmp $

msg db '.', 0x05

times 510-($-$$) db 0           ; 메모리의 510까지 0으로 채움

dw 0xAA55                       ;마지막 2byte를 시그니처 코드인 AA55로 채움
```