#include <stdio.h>

int main(){

    int x=1;
	float nota1[50], nota2[50], media=0;
    
    
    printf("Quantos alunos na turma? ");
    scanf("%d",&x);
    
    	for(int i=0; i<x;i++){
    		
    		do{
			
    		printf("\n--------Aluno %d--------\n",i+1);
    		
    		printf("Nota da primeira prova: ");
    		scanf("%f",&nota1[i]);
    		
    		if(nota1[i]==50){
    			return 0;
			}
			
    		printf("Nota da segunda prova: ");
    		scanf("%f",&nota2[i]);
    		
    		media=(nota1[i]+nota2[i])/2;
    		
    		if((nota1[i]<0) || (nota1[i]>10) || (nota2[i]<0) || (nota2[i]>10)){
    			printf("ERRO! As notas tem de estar no intervalo de 0-10\n");
    			printf("--Digite as notas novamente--\n");
    			nota1[i]=0;
    			nota2[i]=0;
    			i--;
			}else{
				printf("Media: %.2f\n", media);
			}
    		
			}while((nota1[i]<0) || (nota1[i]>10) || (nota2[i]<0) || (nota2[i]>10));
			
		}
	
    return 0;
}
