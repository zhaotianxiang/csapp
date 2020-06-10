# Representing and Manipulating Information(表示和操作信息)
Human use 10-based but machine use binary better.

Computer use a limited number of bits to encode a number, and hence some operate can *overflow* when the result too large,such as 32-bit for data type of int.

Three representions as follows.
## 2.1 Information Storage
Bytes(8-bits) is smallest addressable unit of memory. Adress includes a lot of unique Bytes, all possible set is as known as **virtual address space**
### 2.1.1 Hexadecimal Notation(十六进制表示法)
### 2.1.2 Words
Every computer has a word size, indicating the nominal size of integer and pointer.

Virtual address is 0 ~ 2^w -1, most 32-bits means 4GB virtual address

### 2.1.3 Data Size
|  C declaration   | 32-bit | 64-bit |
|  ----  | ----  | ---- |
| char  | 1 | 1 |
| short int | 2 | 2 |
|  int | 4 | 4 |
| long int | 4 | 8 |
| long long int | 8 | 8 |
| char * | 4 | 8 |
| float | 4 | 4 |
| double | 8 | 8 |

### 2.1.4 Addressing and Byte Ordering
x of type of int has address 0x100, &x is 0x100, Then 4 bytes of x would be stored in memory 0x100,0x101,0x102,0x103.(地址由大小到大或者由大到小)。suppose x=0x01234567

- Big endian(大端从小到大读)
    |0x100|0x101|0x102|0x103|
    |-|-|-|-|
    |01|23|45|67|
- Little endian(小端从大到小读)
    |0x100|0x101|0x102|0x103|
    |-|-|-|-|
    |67|45|23|01|

### 2.1.5 Representing String
A string c is encode by an array of characters terminated by the null(0);
ehch charcters is ASCII codeed.

![ASCII](https://bkimg.cdn.bcebos.com/pic/e850352ac65c103880a07b53bc119313b17e8941)
```c
char *s = "12ABab";
0x31 0x32 0x41 0x42 0x61 0x62 0x00
49   50   65   66   97   98   0
```

Aside is Unicode standard for text encoding, "\u.."

### 2.1.6 Representing Code
Consider the following C function:
```c
int sum(int x, int y)
{
    return x+y;
}
```
When complied on our machines, machine code is:
| OS | byte code|
|-|-|
|Linux32| 55 89 e5 8b 45 0c 03 45 08 c9 c3|
|Linux64| 55 48 89 7d fc 89 75 f8 03 45 fc c9 c3|
|Windows| 55 89 e5 8b 45 0c 03 45 08 c9 c3|
Program is a seqence of bytes.

### 2.1.7 Introduction to Boolean Algebra(布尔代数)
We can create eight colors based on the absence(0) or presence(1):

|R|G|B|Color|
|-|-|-|-|
|0|0|0|Black|
|0|0|1|Blue|
|0|1|0|Green|
|*|*|*|*|
|1|1|1|White|

### 2.1.8 Bit-Level Operations in C
- &
- |
- ^
- ~

Such as a^a = 0, so.
```c
void inplace_swap(int *x, int *y)
{
    *y = *x^*y;
    *x = *x^*y;
    *y = *x^*y;
}
```
Reverse the elements of an array.
```c
void reverse_array(int a[], int cnt)
{
    int first, last;
    for(first=0, last=cnt-1; first<=last; first++, last--)
    {
        inplace_swap(&a[first], &a[last]);
    }
}
```

One common use of bit-level operations is to implement **masking** operations, where the mask is a bit of pattern that indicates a selected set of bits within a word, such as 0xff.

The Digital Equipment VAX computer was a very popular machine. It has operations:
- bis(bit set)
- bic(bit clear)
- and
- or

They generate result *z* consists of a data word *x* and a mask word *m*
```c
int bis(int x, int m)
{
    return x|m;
}

int bic(int x, int m)
{
    return x&m;
}

int bool_or(int x, int y)
{
    int result = bis(x,y);
    return result;
}

int bool_xor(int x, int y)
{
    int result = ?;
    return result;
}

```

### 2.1.9 Logic Operations in C
- ||
- &&
- !
### 2.1.10 Shift Operations in C
- <<
- \>> ： 一般而言都是算数移位，即补码表示时，标志位复制

## 2.2 Integer Representations
|C data type|Min|Max|
|-|-|-|-|
|char|1000 0000 = -128| 0111 111 = 127|
|unsigned char|0000 0000 = 0| 1111 1111 = 255|
|short|-32768|32767|
|int|-2^(w-1)|2(w-1)|

### 2.2.1 Interal Data Type
### 2.2.2 Unsigned Encodings
Assume we have an integer data type of w bits, [x<sub>w-1</sub> - - - x<sub>0</sub>].
Binary To Unsigned is for length w :

   B2U<sub>w</sub>(x) = $$\alpha


## 2.3 Integer Arithmetic
## 2.4 Floating Point
## 2.5 Summary