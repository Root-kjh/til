# Protected Mode
>여러 개의 프로그램들이 가상의 독립된 환경에서 실행되게 하는 모드

### Protected Mode로 변환을 해야 하는이유

* 각 프로그램마다 가상 메모리 영역이 할당되어 여러 프로그램을 동시에 실행가능

* 다른 프로세스의 접근을 막아 데이터를 보호한다.

* 메모리의 가용범위를 늘려준다.

### GDT(Global Descriptor Table)
>GDT는 Global Descriptor 들을 모아놓은 Table이다.

* Global Descriptor
>32bit protected mode에서 사용할 세그먼트영역에 대한 데이터를 기술한 디스크립터


### Global Descriptor Architecture

![Global Descriptor Architecture](https://t1.daumcdn.net/cfile/tistory/2254A53C53E6F0A810)
출처 : [kcats's mindstory](https://kcats.tistory.com/156?category=554568)

* Segment Limit
    1. Segment의 한계점(크기)를 나타내며, 오프셋은 이 숫자를 넘길 수 없다.
    2. G비트에 저장된 값에 따라 한계점이 달라진다. (G비트가 1일 경우 : 세그먼트*4KB)

* Base Address
    1. 세그먼트의 물리주소
    2. 상위, 하위 주소로 나누어 저장한다.

* 속성
    * P(Present)
        1. 세그먼트의 메모리 존재 여부를 나타냄
        2. 페이징 기능과 관련있음

    * DPL(Descriptor Privilege Level)
        1. 커널레벨과 유저레벨을 구분함
        2. 0~3의 값을 가짐 (0: 커널레벨 , 3: 유저레벨)
    
    * S(System)
        1. 시스템 세그먼트인지 코드 세그먼트인지 지정

    * Type
        1. Type의 첫 비트 : 코드 세그먼트인지 데이터 세그먼트인지 구분
		![Code and Data-Segment Types Table](https://t1.daumcdn.net/cfile/tistory/2207804A53E8F6851E)
    
    * G(Granularity)
        1. 세그먼트 단위 설정
        2. 0일경우 : 세그먼트 단위를 Byte로 설정
        3. 1일경우 : 세그먼트 단위를 4KB로 설정

    * D(Default Size)
        1. 0일 경우 : 해당 세그먼트가 16트
        2. 1일 경우 : 해당 세그먼트가 32비트

    * 0
        1. 항상 0으로 설정되어있는 비트

    * AVL(Available and reserved bits)
        1. 시스템 소프트웨어에 의해 사용됨

```assembly
[org 0]
[bits 16]

start:
	mov ax, cs   ; cs에는 0x1000이 들어 있다.
	mov ds, ax
	xor ax, ax
	mov ss, ax
	
	cli
	
	lgdt[gdtr]
	
	mov eax, cr0
	or eax, 0x00000001
	mov cr0, eax
	
	jmp $+2
	nop
	nop
	
	db 0x66
	db 0x67
	db 0xEA
	dd PM_Start
	dw SysCodeSelector
	
[bits 32]

PM_Start:

	mov bx, SysDataSelector
	mov ds,bx
	mov es,bx
	mov fs,bx
	mov gs,bx
	mov ss,bx
	
	xor eax,eax
	mov ax, VideoSelector
	mov es, ax
	mov edi, 80*2*10+2*10
	lea esi, [ds:msgPMode]
	call printf
	
	jmp $

printf:
	push eax
	
printf_loop:
	or al, al
	jz printf_end
	mov al, byte[esi]
	mov byte [es:edi], al
	inc edi
	mov byte[es:edi], 0x06
	inc esi
	inc edi
	jmp printf_loop
	
printf_end:
	pop eax
	ret
	
msgPMode db "We are in Protected Mode", 0






gdtr:                       
	dw gdt_end - gdt - 1        ;gdt의 크기를 저장
	dd gdt + 0x10000            ;커널소스가 0x1000부터 시작이기 때문에 gdt의 시작 주소를 저장
	
gdt:
	dw 0
	dw 0
	db 0
	db 0
	db 0
	db 0

SysCodeSelector equ 0x08
	dw 0xFFFF					;Limit 0~15bit
	dw 0x0000					;Base address 0~15bit
	db 0x01						;Base address 16~24bit
	db 0x9A						;Bin(10011010) P : 1 / DPL : 00 / S : 1 /  TYPE : 1010(Code:Execute/Read)
	db 0xCF						
	db 0x00
	
SysDataSelector equ 0x10
	dw 0xFFFF
	dw 0x0000
	db 0x01
	db 0x92
	db 0xCF
	db 0x00
	
VideoSelector equ 0x18
	dw 0xFFFF
	dw 0x8000
	db 0x0B
	db 0x92
	db 0x40
	db 0x00
	
gdt_end:
```