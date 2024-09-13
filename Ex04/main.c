#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void)
{
    char str[] = "{[(}])";
    int len = strlen(str);
    Pilha a = pilha(len);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(')
        {
            empilha(str[i], a);
        }
        else if (str[i] == ']' || str[i] == '}' || str[i] == ')')
        {
            if (topo(a) == '[' && str[i] == ']' || topo(a) == '{' && str[i] == '}' || topo(a) == '(' && str[i] == ')')
            {
                desempilha(a);
            }
            else
            {
                printf("Não é balanceada");
                destroip(&a);
                break;
            }
        }
        if (vaziap(a))
        {
            printf("Pilha balanceada");
            destroip(&a);
            break;
        }
    }
    printf("\n");

    return 0;
}