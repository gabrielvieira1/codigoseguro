#include <stdio.h>
#include <string.h>

/*
Usar "%s" para ler uma palavra em um buffer é altamente desencorajado. Sempre haverá uma palavra maior que 
o buffer fornecido, o que resultará em uma vulnerabilidade grave de estouro de buffer.
*/

void BufferOverflow()
{
 char palavra[10];
 char buffer[10];

 memset(palavra, 0, sizeof(palavra));
 printf("palavra: ");
 //scanf("%s", palavra); //stack smashing detected
 scanf("%10s", buffer); //correção

 int len = strlen(buffer);

 //sprintf(palavra, "ola %s", buffer); // Usar sprintf pode levar a vulnerabilidades graves de estouro de buffer. Use a alternativa segura snprintf.

 snprintf(palavra, len, "ola %s", buffer); // Correção


 printf("palavra: %s\n", palavra);
}

int main()
{
 BufferOverflow();
 return 0;
}