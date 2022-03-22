#include <stdio.h>

int main(){

    int valor=0;
    float dm=0,cm=0,mm=0;

    printf("DIgite o valor em metros: ");
    scanf("%d",&valor);

    dm=valor*10;
    cm=valor*100;
    mm=valor*1000;

    printf("Valor em decimetros: %.2f\n",dm);
    printf("Valor em centrimetros: %.2f\n",cm);
    printf("Valor em milimetros: %.2f\n",mm);

    return 0;
}
