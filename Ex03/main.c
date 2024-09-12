#include <stdio.h>
#include <string.h>
#include "pilha.h"
#define LIMITSTRING 80

int main(void)
{
  char str[LIMITSTRING];
  puts("Digite o seu nome ou uma frase");
  fgets(str, LIMITSTRING, stdin);
  char *pch;
  int length = strlen(str), j = 0, k = 0;
  Pilha A = pilha(length);
  Pilha B = pilha(length);

  printf("Quebrando a string \"%s\" em uma pilha de letras:\n", str);
  pch = strtok(str, " ,.-!");
  while (pch != NULL)
  {
    for (int i = 0; i < strlen(pch); i++)
    {
      printf("%c\n", pch[i]);
      empilha(pch[i], B);
    }
    puts("Quero ver o topo de B a cada iteração");
    while (!vaziap(B))
    {
      printf("%c\n", topo(B));
      empilha(topo(B), A);
      desempilha(B);
    }
    empilha(" ", B);
    pch = strtok(NULL, " ,.-");
  }

  puts("");

  while (!vaziap(A))
  {
    printf("%c", topo(A));
    desempilha(A);
  }
  return 0;
}
