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

// inverter expressão
char *reverse(char *str)
{
    int length = strlen(str);
    static char newStr[minLength];
    int j = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        if (str[i] == '(')
            newStr[j++] = ')';
        else if (str[i] == ')')
            newStr[j++] = '(';
        else
            newStr[j++] = str[i];
    }
    newStr[j] = '\0';

    return newStr;
}

char *prefixOperation(char *post)
{
    char *newValue = postfix(reverse(post));
    int length = strlen(newValue);
    static char newStr[minLength];
    int j = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        newStr[j++] = newValue[i];
    }

    newStr[j] = '\0';
    return newStr;
}

int valpre(char *exp)
{
    Pilha p = pilha(maxLength); 
    for (int i = strlen(exp) - 1; i >= 0; i--)
    { 
        if (isdigit(exp[i]))
        {

            empilha(exp[i] - '0', p); 
        }
        else if (strchr("+-*/", exp[i]))
        {

            int operand1 = desempilha(p);
            int operand2 = desempilha(p);
            int result;


            switch (exp[i])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 != 0)
                {
                    result = operand1 / operand2;
                }
                else
                {
                    fprintf(stderr, "Error: Division by zero.\n");
                    return 0;
                }
                break;
            default:
                fprintf(stderr, "Error: Unknown operator %c.\n", exp[i]);
                return 0;
            }

            empilha(result, p);
        }
    }

    int finalResult = desempilha(p);
    destroip(&p);
    return finalResult;
}

// utilize uma pilha de pratos para pensar em como devemos operar
int main(void) {
    char str[minLength] = "(2*3)+(8/4)";
    char *prefix = prefixOperation(str); 
    
    printf("Prefix Notation: %s\n", prefix);  
    
    int val = valpre(prefix);
    printf("Result: %d\n", val);

    return 0;
}
