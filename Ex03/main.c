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
  Pilha A = pilha(LIMITSTRING);
  Pilha B = pilha(LIMITSTRING);

  pch = strtok(str, " ,.-!");
  while (pch != NULL)
  {
    for (int i = 0; i < strlen(pch); i++)
    {
      empilha(pch[i], B);
    }
    while (!vaziap(B))
    {
      empilha(topo(B), A);
      desempilha(B);
      //printf("%c", topo(A));
    }
    if (!vaziap(A))
      empilha(" ", A);
    pch = strtok(NULL, " ,.-");
  }

  printf("%c", topo(A));

  return 0;
}
