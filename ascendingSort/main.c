#include <stdio.h>
#include "pilha.h"

int main(void)
{
    int n, numeros, j = 0;
    puts("Digite o tamanho da sequencia:");
    scanf("%d", &n);
    Pilha a = pilha(n * sizeof(int));
    Pilha b = pilha(n * sizeof(int));
    int length = sizeof(b->item) / sizeof(b->item[0]);

    for (int i = 0; i < n; i++)
    {
        puts("Digite os números da sequência");
        scanf("%d", &numeros);
        empilha(numeros, b);
    }

    printf("\n");

    do
    {
        if (j != length)
        {
            printf("%d proximo número %d\n", b->item[j], b->item[j + 1]);
            if (b->item[j] > b->item[j + 1])
            {
                empilha(b->item[j], a);
                printf("%d\n", b->item[j]);
                j++;
            }
        }
    } while (j != length);

        printf("\n");

    for (int i = 0; i <= length; i++)
    {
        printf("%d\n", a->item[i]);
    }

    printf("%d", topo(a));
    return 0;
}