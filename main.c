#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING 20

void stack_overflow_01()
{
 // O uso de gets pode levar a graves vulnerabilidades de estouro de buffer. Use a alternativa segura fgets.
 char buf[10];
 memset(buf, 0, sizeof(buf));
 printf("buf: ");

 // gets(buf); Perigosa
 fgets(buf, sizeof(buf), stdin); // Segura

 printf("buf: %s\n", buf);
 printf("strlen: %d\n", strlen(buf));
}

void stack_overflow_02()
{
 // Stack corruption
 char buf2[16] = "overwriteme";
 char buf1[16];

 strcpy(buf2, "123456789012345678901234567890");

 printf("buf1 val: %s\n", buf1);
 printf("buf2 val: %s\n", buf2);
 printf("buf1 addr: %p\n", &buf1);
 printf("buf2 addr: %p\n", &buf2);
}

void heap_overflow_01()
{
 char *buf2 = malloc(10);
 printf("buf2: ");

 // gets(buf2); Perigosa
 fgets(buf2, sizeof(buf2), stdin); // Segura

 printf("buf2: %s\n", buf2);
 printf("strlen: %d\n", strlen(buf2));
 free(buf2);
}

void heap_overflow_02()
{
 // Heap corruption
 char *buf3 = malloc(12 * sizeof(char)); // Fuga de memória. A memória alocada por malloc nunca é liberada. Na função principal
 char *buf4 = malloc(12 * sizeof(char));

 // O resultado de malloc, que pode retornar fluxos nulos para o primeiro argumento de strcpy.
 // Isso pode resultar em comportamento indefinido. Considere adicionar uma verificação de nulidade.
 /*
 char *buf3 = malloc(-1);
 if (!buf3 || !buf4) {
   perror("Erro na alocação de memória");
   return 1;
 }
 */
 strcpy(buf4, "mywordshere");
 strcpy(buf3, "1234567890123456789012345678901234567890");

 printf("buf3 val: %s\n", buf3);
 printf("buf4 val: %s\n", buf4);
 printf("buf3 addr: %p\n", &buf3);
 printf("buf4 addr: %p\n", &buf4);
 // free(buf3);
 // free(buf4);
}

void stack_overflow_03()
{
 char campo1[11];
 // int i = (int)strlen(campo1); // O valor de retorno de strlen é um size_t, que é um unsigned int. Não é possível converter um unsigned int em um int.

 memset(campo1, '\0', sizeof(campo1));
 // strcpy(campo1, "123456789012345"); // Insegura
 // strncpy(campo1, "1234567890", sizeof(campo1)); // Insegura
 // strcat(campo1, "1234567890"); // Insegura
 //  Quando o usar o strncat é necessário subtrair o tamanho do campo do tamanho do conteúdo dele.
 strncat(campo1, "1234567890", sizeof(campo1) - strlen(campo1)); // Segura
 // Sempre que for usar o campo1, verifique se ele está nulo.

 // printf("strlen: %d\n", i);
 printf("strlen: %d\n", strlen(campo1));
 printf("campo1: %s\n", campo1);

 printf("\n\n");
}

void heap_overflow_03()
{
 char *nome = (char *)malloc(MAX_STRING); // Definir constantes para os tamanhos de buffer é uma boa prática.

 // char *nome = (char *)malloc(-1); // O malloc pode dar problema de alocação e retornar um fluxo nulo. Verifique se o fluxo é nulo antes de usar.

 if (!nome) // Verificar se o malloc retornou um fluxo nulo.
 {                                       
  perror("Erro na alocação de memória"); // perror imprime a mensagem de erro associada ao valor de errno.
  return 1;
 }

 memset(nome, '\0', sizeof(MAX_STRING));
 // strncpy(nome, "Gabriel1234567890", sizeof(nome)); // Insegura. Sizeof(nome) retorna o tamanho do ponteiro, não o tamanho do conteúdo.
 strncpy(nome, "Gabriel1234567890", MAX_STRING);

 printf("nome: %s\n", nome);
 printf("strlen: %d\n", strlen(nome));
 printf("sizeof: %d\n", sizeof(nome)); // sizeof(nome) retorna o tamanho do ponteiro (8 bytes em 64 bits).

 free(nome);
 nome = NULL; // Sempre que der um free no ponteiro, coloque ele como NULL.
 printf("\n\n");
}

int main(int argc, char *argv[])
{
 stack_overflow_01();
 stack_overflow_02();
 heap_overflow_01();
 heap_overflow_02();
 stack_overflow_03();
 heap_overflow_03();
 return 0;
}