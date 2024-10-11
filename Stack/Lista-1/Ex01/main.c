#include <stdio.h>
#include "pilha.h"

int main(void)
{
    int n, numeros;
    puts("Digite o tamanho da sequencia:");
    scanf("%d", &n);
    Pilha a = pilha(n * sizeof(int));
    Pilha b = pilha(n * sizeof(int));

    for (int k = 0; k < n; k++)
    {
        puts("Digite os números da sequência");
        scanf("%d", &numeros);
        empilha(numeros, a);
    }

    while (!vaziap(a))
    {
        int k = topo(a);
        desempilha(a);

        while (!vaziap(b) && topo(b) < k)
        {
            empilha(topo(b), a);
            desempilha(b);
        }

        empilha(k, b);
    }

    puts("");

    puts("\nSequência ordenada:");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a->item[i]);
    }

    printf("o topo dessa merda é %d\n", topo(b));

    return 0;
}