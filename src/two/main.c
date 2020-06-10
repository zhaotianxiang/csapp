#include"print_byte.h"
#include<string.h>

void test(int val)
{
    int ival = val;
    float fval = (float) val;
    int *pval = &val;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main()
{
    int a = 1;
    test(a);

    int val = 0x87654321;
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);

    char *s = "12ABab";
    show_bytes((byte_pointer) s, strlen(s)+1);
    return 0;
}