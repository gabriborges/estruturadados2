#include <stdio.h>

int main(){

    float num1=0, num2=0, soma=0, produto=0, quadrado=0;
    
    printf("Digite os primeiro Numero: \n");
    scanf("%f",&num1);
    printf("Digite os segundo Numero: \n");
	scanf("%f",&num2);
	
	soma=num1+num2;
	produto=num1*(num1*num2);
	quadrado=num1*num1;
	
	printf("Soma: %.2f\n",soma);
	printf("Produto: %.2f\n",produto);
	printf("Quadrado: %.2f\n",quadrado);
	
    return 0;
}
