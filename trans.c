#include <stdio.h>
#include "translator.h"

void push(int st[], int *num, int k)
{
    st[(*num)++] = k;
}
int pop(int st[], int *num)
{
    return st[--(*num)];
}