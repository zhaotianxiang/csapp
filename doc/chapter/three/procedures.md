# Procedures (过程)

ABI 二进制编程接口

```
p(···) 
{
    ·
    ·
    y=Q(x);
    print(y);
    ·
}

int Q(int i)
{
    return 10*i;
}
```

 - passing control
 - passing data
 - memary management
 - mechanisms all implemented with machine instructions

在很好的编程风格中，专注于很小的功能的函数非常优美。

## 1. stack 
 stack pointer: %rsp, 倒扣在内存中的栈 
 %rsp contains lowest rtack address. when stack is ++, %rsp--. %rbp 基指针
## 2. Procedure control Flow 
  - call:
    - 1. %rsp-- `(含糊不清)`
  - ret: pop address from stack, %rip = address

## 3. Passing data
 first 6 arguments for passing data
 - %rdi
 - %rsi
 - %rdx
 - %rcx
 - %r8
 - %r9
 return value
 - %rax

 超过6个参数怎么？放入栈中的内存中

## 4. Manage local data
call chain
**Stack frame**
 - Contents
   * return information
   * local storage
   * temporary space
 - Management 
   * space allocated when enter procdure
   * deallocated when return
![stack frame](www.baidu.com.3-stack.JPG)

栈的调用层次是有限制的，stackoverflow来了

## Register saving conventions
 - caller
 - callee : do not store data in register





