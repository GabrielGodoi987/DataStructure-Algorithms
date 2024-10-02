#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"
#define maxLength 513
#define minLength 256

// criar uma função para que faça o teste de prioridade de cada elemento da função
int prio(char wre)
{
    switch (wre)
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

// pegar uma operação aritética e transformar em posfixa

char *postfix(char *str)
{
    static char s[maxLength];
    Pilha p = pilha(maxLength);
    int j = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
        {
            empilha('(', p);
        }
        else if (isdigit(str[i]))
        {
            s[j++] = str[i];
        }
        else if (strchr("+-/*", str[i]))
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
// pegar a posfixa e inverter a sua cadeia de caracteres e retorná-los
char *_strrev(char *str)
{
    //                 topo
    //[2][3][*][8][4][/][+]
    // adicione o topo da pilha a um array de caracteres criado
    // após isso desempilhe cada valor adicionado
    int length = strlen(str);
    Pilha p = pilha(length);
    char value[length];
    int j = 0;

    for (int i = 0; i < length; i++)
    {
        empilha(str[i], p);
    }

    while (!vaziap(p))
    {
        str[j] = topo(p);
        desempilha(p);
        j++;
    }

    return str;
}

// criar uma função para que possamos testar a operação e ver qual o seu valor
int valPre(char e)
{
}
// utilize uma pilha de pratos para pensar em como devemos operar

int main(void)
{
    char str[] = "(2*3)+(8/4)";

    char *post = postfix(str);
    printf("postfix operation = %s\n", post);

    puts("operação reversa");
    printf("%s\n", _strrev(post));
    return 0;
}