#include <stdio.h>

int main()
{
 /*
 Integer overflow É um erro que ocorre quando uma operação aritmética tenta criar um valor numérico que 
 está fora do intervalo que é representado com um determinado número de dígitos. Maior que o máximo ou menor 
 que o valor mínimo representável.
 */
 // short numMAX = 2147483647;
 // short numMIN = -2147483648;
 
 int numMAX = 2147483648;
 int numMIN = -2147483649;

 printf("%d\n", numMAX);
 printf("%d\n", numMIN);

 return 0;
}