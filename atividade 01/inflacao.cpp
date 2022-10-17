#include <stdio.h>

int main(){

    float produto=0;
    
    printf("Digite o vaor do produto: \n");
    scanf("%f",&produto);
	
	if(produto<100){
		produto=produto+((produto/100)*10);
		printf("Valor: %.2f\n",produto);
	}else{
		produto=produto+((produto/100)*20);
		printf("Valor: %.2f\n",produto);
	}
	
	
    return 0;
}
