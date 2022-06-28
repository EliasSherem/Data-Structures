#include <stdio.h>
#include <stdlib.h>

void cambio(int *, int *);
float comprueba(float *, float*);
int main(){
	int opcion;
	int x,y;
	float i=10.5,j=5.5;
	float mayor;
	float cali;
	int exp;
	float *pc;
	int *pe;
	pc=&cali;
	pe=&exp;
	do{
		printf("\nIngrese una opcion\n1. cambio\n2. tarea1\n3. tarea2\n10. salir\n");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 1:
				x=10;
				y=127;
				cambio(&x,&y);
				printf("%d %d\n",x,y);
			break;
			case 2: 
				mayor=comprueba(&i,&j);
				printf("El mayor es: %.2f", mayor);
			break;
			case 3: 
				printf("Ingresa el expediente: ");
				scanf("%d",&exp);
				printf("Ingresa la calificacion: ");
				scanf("%f",&cali);
				printf("ID: %d, calificacion: %f",*pe,*pc);
			break;
			case 10: printf("Adios");
			break;
			default: printf("Opcion ivalida");
			break;
		}
	}while(opcion!=10);
}

void cambio(int *a, int *b){
	int i;
	i=*a;
	*a=*b;
	*b=i;
}

float comprueba(float *a, float *b){
	if(*a>*b){
		return *a;
	}else{
		return *b;
	}
}
