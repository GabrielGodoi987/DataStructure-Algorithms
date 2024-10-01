#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"
#define lengthMax 513

int prio(char digit)
{
    switch (digit)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }

    return -1;
}

char *postfix(char *e)
{
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);
    for (int i = 0; e[i]; i++)
    {
        if (e[i] == '(')
            empilha('(', P);
        else if (isdigit(e[i]))
            s[j++] = e[i];
        else if (strchr("+-/*", e[i]))
        {
            while (!vaziap(P) && prio(topo(P)) >= prio(e[i]))
                s[j++] = desempilha(P);
            empilha(e[i], P);
        }
        else if (e[i] == ')')
        {
            while (topo(P) != '(')
                s[j++] = desempilha(P);
            desempilha(P);
        }
    }
    while (!vaziap(P))
    {
        s[j++] = desempilha(P);
    }
    s[j] = '\0';
    destroip(&P);
    return s;
}

int eval(char *str)
{
    int value = 0;
    Pilha p = pilha(lengthMax);
    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]))
        {
            empilha(str[i] - '0', p);
        }
        else if (strchr("+-/*", str[i]))
        {
            int n2 = desempilha(p);
            int n1 = desempilha(p);
            if (str[i] == '*')
            {
                value = n1 * n2;
                empilha(value, p);
                value = 0;
            }
            else if (str[i] == '/')
            {
                value = n1 / n2;
                empilha(value, p);
                value = 0;
            }
            else if (str[i] == '-')
            {
                value = n1 - n2;
                empilha(value, p);
                value = 0;
            }
            else if (str[i] == '+')
            {
                value = n1 + n2;
                empilha(value, p);
                value = 0;
            }
        }
    }

    return desempilha(p);
    destroip(&p);
}

int main(void)
{
    char e[lengthMax] = "(2*3)+(8/4)";

    char *val = postfix(e);
    printf("Posfixa: %s\n", val);

    printf("posfixa resolvida %d\n", eval(val));
    return 0;
}