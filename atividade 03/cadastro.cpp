#include <stdio.h>
#include <stdlib.h>

struct aluno{
 int mat;
 char nome[81];
 char turma[1];
 float p1;
 float p2;
 float p3;
 float media; 
};
typedef struct aluno Aluno;

void inicializa(int n, Aluno** tab){
 for(int i=0;i<n;i++){
  tab[i]=NULL;
 }
}

void inserir(int n, Aluno** tab, int i){
  
  if(i < 0 || i>=n){
    printf("Indice fora do limite do vetor\n");
    exit(1);
  }

  if(tab[i]==NULL){ 
    tab[i] = (Aluno*)malloc(sizeof(Aluno));
  }

  printf("Entre com a matricula: ");
  scanf("%d", &tab[i]->mat);
  printf("Entre com o nome: ");
  scanf("%s", &tab[i]->nome);
  printf("Entre com a turma: ");
  scanf("%s", &tab[i]->turma);
  printf("Entre com a nota 1: ");
  scanf("%f", &tab[i]->p1);
  printf("Entre com a nota 2: ");
  scanf("%f", &tab[i]->p2);
  printf("Entre com a nota 3: ");
  scanf("%f", &tab[i]->p3);
  
  tab[i]->media =(((tab[i]->p1)+(tab[i]->p2)+(tab[i]->p3))/3);
  
  printf("Aluno inserido com sucesso\n");

}

void imprime_aluno(int n, Aluno **tab, int i){
  
  if(i < 0 || i>=n){
    printf("Indice fora do limite do vetor\n");
    exit(1);
  }
  
  if(tab[i]!=NULL){
    if(tab[i]->media >= 7){
      printf("\n#Dados do aluno %d\n",i+1);
      printf("Nome do aluno: %s\n", tab[i]->nome);
      printf("Matricula do aluno: %d\n", tab[i]->mat);
      printf("Turma do aluno: %s\n", tab[i]->turma);
      printf("Media do aluno: %f\n", tab[i]->media);
    }
  }
  
}

void imprime_aprovados(int n, Aluno** tab){
  

 for(int i = 0; i < n; i++){

      imprime_aluno(n,tab,i);

 }
}


int main(){
 
 Aluno* tab[10];
 
 inicializa(10, tab);
 
 inserir(10,tab, 0);
 inserir(10,tab, 1);
 imprime_aprovados(10, tab);
 
 return 0;
}
