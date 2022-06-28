#include <stdio.h>
#include <stdlib.h>
struct empleado{
	int num_empleado;
	int antiguedad;
};

void estructura();

int main(){
	int opcion;
	do{
		printf("\nIngresa la opcio que deseas\n1. struct\n10. salir\n");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 1:estructura();
			case 10: printf("Adios");
			break;
			default: printf("Opcion invalida");
			break;
		}
	}while(opcion!=10);
}

void estructura(){
	struct empleado javier;
	struct empleado jorge;
	
	printf("Ingresa el numero de empleado: ");
	scanf("%d",&jorge.num_empleado);
	printf("Ingresa la antiguedad: ");
	scanf("%d",&jorge.antiguedad);
	printf("Ingresa el numero de empleado: ");
	scanf("%d",&javier.num_empleado);
	printf("Ingresa la antiguedad: ");
	scanf("%d",&javier.antiguedad);
	
	printf("Javier es el empleado numero %d y tiene %d en la empresa\n",javier.num_empleado, javier.antiguedad);
	printf("Jorgel empleado numero %d y tiene %d en la empresa",jorge.num_empleado, jorge.antiguedad);
}
