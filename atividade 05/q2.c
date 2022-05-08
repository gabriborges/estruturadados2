#include <stdio.h>
#include <string.h>

typedef struct{
  char nome[50];
  int idade;
  char endereco[100];
} Dados;


int main(void) {
  Dados dados;

  printf("\nNome: ");
  fgets(dados.nome, 50, stdin);
  
  printf("\nIdade: ");
  scanf("%d", &dados.idade);
  
  getchar();
  printf("\nEndereco: ");
  fgets(dados.endereco, 100, stdin);

  return 0;
}