#include <stdio.h>
#include <stdlib.h>

struct pila{
	int top;
	int arreglo[10];
};

void push (struct pila *, int);
void pop(struct pila *);
void imprimir(struct pila *);

int main(){
	int opcion;
	int valor;
	struct pila s;
	s.top=-1;
	do{
		printf("\nIngresa la opcion que desea\n1. push\n2. pop\n3. imprimir\n4. balanceo\n5. salir\n");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 1: printf("Dame el elemento a insertar: ");
				scanf("%d",&valor);
				push(&s,valor);
			break;
			case 2: pop(&s);
			break;
			case 3:imprimir(&s);
			break;
			case 4:
			break;
			case 5: printf("Adios");
			break;
			default: printf("Opcion invalida");
			break;
		}
	}while(opcion!=5);
	return 0;
}

void push (struct pila *ps, int x){
	int longitud=sizeof(ps->arreglo)/sizeof(ps->arreglo[0]);
	ps->top++;
	if(ps->top < longitud){
		ps->arreglo[ps->top]=x;
		printf("Se inserto el dato");	
	}else{
		printf("Hay un overflow");
		ps->top--;
	}
}
void pop(struct pila *ps){
	if(ps->top==0){
		printf("Hay un underflow");
	}else{
		ps->top--;	
	}
}
void imprimir(struct pila *ps){
	int i;
	for (i=ps->top;i>=0;i--){
		printf("%d, ",ps->arreglo[i]);
	}
}
