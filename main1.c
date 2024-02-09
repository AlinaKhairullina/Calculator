#include <stdio.h>
#define N 100
void push(int st[], int *num, int k)
{
    st[(*num)++] = k;
}
int pop(int st[], int *num)
{
    return st[--(*num)];
}
int main()
{
    int st[N];
    int  c; // читаемый символ
    int num = 0; //количество элементов в стэке
    int  x ; // вспомогательная переменная, печатающая операции со стэка 
    while (((c = getchar()) != '\n') && (c != EOF) && (c != '='))
    {
        if (c == ' ') continue; // если пробел, то переход на след итерацию

        switch (c) 
        {
            case '(':
                printf(" "); 
                push(st, &num, c); //открывающуюся скобку заносим в стек
                break;
            case  '&':
                if ((c = getchar()) == '&') //если символ & и следующий
                // за ним & , то проверяем операции в стекe
                {
      
                    printf(" ");
                    while ( (num != 0) && ((st[num - 1] == '!') || (st[num -1]) == '&')) //пока последний элемент стека не является операцией с приоритетом выше или равным 
                    {
                        x = pop(st, &num);
                        if (x == '!') printf(" ! "); // печатаем элемент стека
                        else printf(" && ");
                    }
           
                    push(st, &num, c); //заносим текущую операцию в стек
                }
                break;
            case  '!' : 
                while ((num != 0) && ((st[num - 1]) == '!')) // пока последний элемент !
                {
                    pop(st, &num);
                    printf(" ! ");

                }       
                push(st, &num, c);
                break;
            case  '|': 
                if ((c = getchar()) == '|') // если следующий символ |
                {
                    printf(" ");
                    while ( (num != 0) && (st[num - 1] == '!' || st[num - 1] == '&' || st[num - 1] == '|')) 
                    {  // пока посл элемент ! или  & или |
                        x = pop(st, &num);
                        if (x == '!') printf(" ! "); 
                        else if (x == '&') printf(" && "); 
                        else printf(" || "); 
                    }
                    push(st, &num, c);
                }
                break;
            case ')': 
                while ( (num != 0) && ((st[num - 1]) != '(')) // печатаем все операции из стэка до ( 
                {
                    x = pop(st, &num);
                    if (x == '!') printf(" ! ");
                    else if (x == '|') printf(" || ");
                    else if (x == '&') printf(" && ");
                }
                break;
            default:  
                putchar(c);
                break;

        }
    }
    printf(" ");
    while (num != 0 ) 
    {
        x = pop(st, &num); 
        switch (x) 
        {
            case '!': //печатаем оставшиеся элементы из стэка
                printf(" ! ");
                break;
            case  '|':
                printf(" || ");
                break;
            case '&':
                printf(" && "); 
                break;
        }
    } 
    printf("\n");
    return 0;
    
}