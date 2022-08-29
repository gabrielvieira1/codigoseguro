#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
 stack_overflow_01();
 stack_overflow_02();
 heap_overflow_01();
 heap_overflow_02();
 return 0;
}