#include <stdio.h>
#include <ctype.h>
#include "pilha.h"
#include "fila.h"

#define maxLength 256

int main(void)
{
    char s[maxLength];
    Fila F = fila(maxLength);
    Pilha P = pilha(maxLength);
    printf("\nFrase? ");
    fgets(s, maxLength, stdin);
    for (int i = 0; s[i]; i++)
        if (isalpha(s[i]))
        {
            enfileira(toupper(s[i]), F);
            empilha(toupper(s[i]), P);
        }
    while (!vaziaf(F) && desenfileira(F) == desempilha(P));
    if (vaziaf(F))
        puts("A frase e palindroma");
    else
        puts("A frase nao e palindroma");
    destroif(&F);
    destroip(&P);
    return 0;
}