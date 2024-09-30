#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

char *postfix(char *e)
{
    static char s[256];
    Pilha p = pilha(256);
    int j = 0;

    for (int i = 0; e[i]; i++)
    {
        if (isdigit(e[i]))
            s[j++] = e[i];
        else if (strchr("+*/-", e[i]))
            empilha(e[i], p);
        else if (e[i] == ')')
            s[j++] = desempilha(p);
        s[j] = '\0';

        destroip(&p);
        return s;
    }
}

int main(void)
{
    char str[513] = "(2*3)+(8/4)";

    puts("infix operator");
    printf("%s \n", str);

    puts("postfix operator");
    printf("%s \n", postfix(str));

    return 0;
}