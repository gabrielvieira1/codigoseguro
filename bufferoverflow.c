#include <stdio.h>
#include <string.h>

/*
Usar "%s" para ler uma palavra em um buffer é altamente desencorajado. Sempre haverá uma palavra maior que 
o buffer fornecido, o que resultará em uma vulnerabilidade grave de estouro de buffer.
*/

void BufferOverflow()
{
 char palavra[10];
 memset(palavra, 0, sizeof(palavra));
 printf("palavra: ");
 //scanf("%s", palavra); //stack smashing detected
 scanf("%10s", palavra); //correção

 printf("palavra: %s\n", palavra);
}

int main()
{
 BufferOverflow();
 return 0;
}