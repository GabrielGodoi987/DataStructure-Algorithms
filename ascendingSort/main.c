#include <stdio.h>
#include "pilha.h"

int main(void)
{
    int n, numeros;
    puts("Digite o tamanho da sequencia:");
    scanf("%d", &n);
    Pilha a = pilha(n * sizeof(int));
    Pilha b = pilha(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        puts("Digite os números da sequência");
        scanf("%d", &numeros);
        empilha(numeros, b);
    }

    printf("\n");

    int length = sizeof(b->item) / sizeof(b->item[0]);
    int aux = 0;
    for(int i = 0; i <= length; i++){
        aux = b->item[i];
        if(aux < b->item[i + 1]){
          empilha(b->item[i + 1], a);
        }
    }

    for(int j = 0; j <= length; j++){
       printf("%d\n", b->item[j]);
    }


    printf("%d\n", topo(a));
    return 0;
}