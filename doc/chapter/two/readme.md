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


## 2.2 Integer Representations


## 2.3 Integer Arithmetic
## 2.4 Floating Point
## 2.5 Summary