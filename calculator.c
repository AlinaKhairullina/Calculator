#include <stdio.h>
#define N 100

void push(int st[], int *num, int x)
{
    st[(*num)++] = x;
}

int pop(int st[], int *num)
{
    return st[--(*num)];
}

int res()
{
    int stack[N];
    int top = 0;
    int c;
    long tmp, tmp1, tmp2;
    while ( ((c = getchar()) != EOF) && (c != '\n') )
    {
        if (c == ' ') continue;
        else if (c == '!') 
        {
            tmp = !( pop(stack, &top) );
            push(stack, &top, tmp);
        }
        else if (c == '&')
        {
            tmp1 = pop(stack, &top);
            tmp2 = pop(stack, &top);
            tmp = (tmp1 && tmp2);
            push(stack, &top, tmp);
            c = getchar();
        }
        else if (c == '|')
        {
            tmp1 = pop(stack, &top);
            tmp2 = pop(stack, &top);
            tmp = (tmp1 || tmp2);
            push(stack, &top, tmp);
            c = getchar();
        }
        else 
        {
            long elem = c - '0';
            long k = 10;
            while ((c = getchar()) != ' ') 
            {
                elem += (c - '0') * k;
                k *= 10;
            }
            push(stack, &top, elem);
        }
    }
    tmp = pop(stack, &top);
    return tmp;
}

int main()
{
    printf ( "Answer %d", res() );
    return 0;
}

