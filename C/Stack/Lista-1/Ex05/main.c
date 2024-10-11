#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void)
{
    Pilha pilha_a = pilha(11);
    char string[11];
    char *var;

    for (int i = 1; i <= 3; i++)
    {
        printf("? ");
        gets(string);
        var = strdup(string);
        empilha(var, pilha_a);
    }

    while (!vaziap(pilha_a))
        puts(desempilha(pilha_a));

    return 0;
}