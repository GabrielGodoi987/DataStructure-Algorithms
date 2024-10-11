#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

#define maxLength 513

int prio(char o)
{
    switch (o)
    {
    case '|':
        return 0;
    case '&':
        return 1;
    case '!':
        return 2;
    }

    return -1;
}

char *postfix(char *str)
{
    static char s[maxLength];
    Pilha p = pilha(maxLength);
    int j = 0;
    for (int i = 0; str[i]; i++)
    {
        if (strchr("FV", str[i]))
        {
            s[j++] = str[i];
        }
        else if (str[i] == '(')
        {
            empilha('(', p);
        }
        else if (strchr("|&!", str[i]))
        {
            while (!vaziap(p) && prio(topo(p)) >= prio(str[i]))
            {
                s[j++] = desempilha(p);
            }

            empilha(str[i], p);
        }
        else if (str[i] == ')')
        {
            while (topo(p) != '(')
            {
                s[j++] = desempilha(p);
            }
            desempilha(p);
        }
    }
    while (!vaziap(p))
    {
        s[j++] = desempilha(p);
    }

    s[j] = '\0';
    destroip(&p);
    return s;
}

int booleans(char bol)
{
    switch (bol)
    {
    case 'F':
        return 0;
    case 'V':
        return 1;
    }

    return -1;
}

int verfifyOperation(char *o)
{
    Pilha p = pilha(maxLength);
    for (int i = 0; o[i]; ++i)
    {
        if (strchr("FV", o[i]))
        {
            empilha(booleans(o[i]), p);
        }
        else
        {
            switch (o[i])
            {
            case '!':
            {
                int n = desempilha(p);
                empilha(!n, p);
            }
            break;
            case '&':
            {
                int a = desempilha(p);
                int b = desempilha(p);
                empilha(a & b, p); 
            }
            break;
            case '|':
            {
                int a = desempilha(p);
                int b = desempilha(p);
                empilha(a | b, p);
            }
            break;
            }
        }
    }
    int result = desempilha(p);
    destroip(&p);
    return result;
}

int main(void)
{
    char operation[maxLength];
    puts("Digite uma operação lógica com valores boleanos (V ou F) e operadores lógicos(!, &, |)");
    fgets(operation, maxLength, stdin);

    for (int i = 0; i < strlen(operation); i++)
    {
        operation[i] = toupper(operation[i]);
    }


    char *o = postfix(operation);

    // Imprime a expressão pós-fixa
    printf("valor posfixa = %s\n", strrev(o));
    printf("////////////////////////////\n");

    printf("final value teste = %d\n", verfifyOperation(o));

    return 0;
}