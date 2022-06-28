#include <stdio.h>



int main(){
	float cali;
	int exp;
	float *pc;
	int *pe;
	pc=&cali;
	pe=&exp;
	printf("Ingresa el expediente: ");
	scanf("%d",&exp);
	printf("Ingresa la calificacion: ");
	scanf("%f",&cali);
	printf("ID: %d, calificacion: %f",*pe,*pc);
	
}
