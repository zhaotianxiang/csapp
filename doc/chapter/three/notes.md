# CSAPP Notes
## Assembly Operand

### 1. movq and leaq Operand
|source|dest|example|C analog|
|-|-|-|-|
|imm|reg|movq $0x4, %rax|temp=0x4|
|imm|mem|movq $147, (%rax)|*p=-147|
|reg|reg|movq %rax, %rdx|temp2=temp1|
|reg|mem|movq %rax, (%rdx)|*p=temp|
|mem|reg|movq (%rax), %rdx|temp=*p|

Pointer derferencing 
```
int *p = &a;
movq (%rcx), %rax
```
```c
void swap(long *xp, long *yp)
{
    long t0 = *xp; //从内存中mov到寄存器中
    long t1 = *yp;
    *xp = t1; // 从寄存器中mov到内存中
    *yp = t0;
}

swap:
    movq    (%rdi), %rax // (%rdi)括号表示取寄存器%rdi中的值
    movq    (%rsi), %rdx
    movq    %rdx,   (%rdi)
    movq    %rax,   (%rsi)
    //(%rdi)括号表示取寄存器%rdi中的值,写回去内存
    ret
```

|Expression|Address Computation|Address|
|-|-|-|
|0x8(%rdx)|0xf000 + 0x8|0xf008|
|(%rdx,%rcx)|0xf000 + 0x100|0xf100|
|(%rdx,%rcx,4)|0xf000 + 4*0x100|0xf400|
|0x80(,%rdx,2)|2*0xf000 +0x80|0x1e080|

### 2. Two Oprand Arithmetic(两元运算符)
 - addq +
 - subq -
 - imulq x
 - salq <<
 - shlq <<
 - sarq >>
 - shrq >>>
 - xorq ^
 - andq &
 - orq |

 addq src,dest dest = dest + src

 ### 3. One Oprand Instructions
  - incq ++
  - decq --
  - negq -
  - notq ~

  ## Control Instructions
  寄存器不是内存的一部分，不是缓存的一部分。
  condition code CF,ZF,SF,OF

  %rsp stack pointer, %rip Dead

Condition Codes
   - CF Carry Flag unsigned overflow
   - SF Sign Flag if t < 0
   - ZF Zero Flag if t==0 ?
   - OF Overflow Flag (a>0 && b>0 && t<0) || (a<0 && b<0 && t>=0)

`cmpq` instructions is sub operations and do nothing. `testq` instructions with conditions .`setXq` instructions set bit. 

Arguments x is `%rdi`, Arguments y is `%rsi`, `%rax` is return value.

```
int gt(long x, long y)
{
    return x>y
}

cmpq %rsi, %rdi      compare x:y
    setg %al         # set when >
    movzbl %al, %eax # Zero rest of %rax eax is rax low 32 bit
    ret
```

jx branch statements
 - jmp
 - je  ==
 - jne !=
 - js  
 - jns
 - jg jump greater(大于转移,SF=0且 ZF=0)
 - jge
 - jl 
 - jle
 - ja  jump above(大于转移,CF=0且 ZF=0)
 - jb

```
 abs:
    compq %rsi, %rdi
    jle .L4
    movq %rdi, %rax
    subq %rsi, %rax
    ret
.L4:
    movq %rsi, %rax
    subq %rdi, %rax
    ret
```

### 4.switch case
 All case value will be shift to unsigned, and index block.

 if you have case 0 and case 10000, assembly code will build a 10000 size of table.(废物) case value few and far between they will build if-else block to replace.

