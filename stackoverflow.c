#include <stdio.h>
#include <string.h>

/* 
A função Chama a si mesma infinitas vezes, atigindo o limite de chamadas que pode ser feito no programa
e estourando o erro Segmentation fault (Stack Overflow).

Uma função recursiva é aquela que invoca a si mesma ao longo de sua execução. 
Para que isso funcione corretamente, ela precisa em algum momento parar de invocar-se 
(chamamos isso de ponto de fuga).
*/
// void StackOverflow(int tam)
// {
//  if (tam < 10) return;

//  return StackOverflow(tam + 1);
// }

void StackOverflow(int tam, int qtdChamadas)
{
 if (qtdChamadas == 3) return; // Ponto de fuga

 if (tam < 10) return;

 return StackOverflow(tam + 1, qtdChamadas + 1);
}


int main()
{
 int tam = 10;
 int qtdChamadas = 0;
 StackOverflow(tam, qtdChamadas);
 return 0;
}