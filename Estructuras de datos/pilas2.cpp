#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pila{
	int top;
	char arreglo[10];
};

void push (struct pila *, char);
void pop(struct pila *);
void imprimir(char []);
void balanceo(struct pila *, char[]);

int main(){
	int opcion;
	char valor;
	struct pila s;
	int i=0;
	s.top=-1;
	char cad[10];
	do{
		printf("\nIngresa la opcion que desea\n1. push\n2. pop\n3. imprimir\n4. balanceo\n5. salir\n");
		scanf("%d",&opcion);
		system("cls");
		switch(opcion){
			case 1: 
				fflush(stdin);
				printf("Inserta un carcter: ");
				scanf("%c", &cad[i]);
				i++;
			break;
			case 2: pop(&s);
			break;
			case 3:imprimir(cad);
			break;
			case 4: balanceo(&s,cad);
			break;
			case 5: printf("Adios");
			break;
			default: printf("Opcion invalida");
			break;
		}
	}while(opcion!=5);
	return 0;
}

void push (struct pila *ps, char x){
	int longitud=sizeof(ps->arreglo)/sizeof(ps->arreglo[0]);
	ps->top++;
	if(ps->top < longitud){
		ps->arreglo[ps->top]=x;
		printf("Se inserto el dato\n");	
	}else{
		printf("Hay un overflow\n");
		ps->top--;
	}
}
void pop(struct pila *ps){
	if(ps->top==-1){
		printf("Hay un underflow\n");
	}else{
		ps->top--;	
	}
}
void imprimir(char cad[]){
	printf("%s",cad);
}

void balanceo(struct pila *ps, char cad[]){
	int i =0;
	while(i<10){
		if(cad[i]=='(' || cad[i]=='[' || cad[i]=='{'){
			push(ps,cad[i]);
		}else if(cad[i]==')' || cad[i]==']' || cad[i]=='}'){
			if(ps!=NULL){
				if(cad[i]==')'){
					if(ps->arreglo[ps->top]=='('){
						pop(ps);
					}
				}else if(cad[i]==']'){
					if(ps->arreglo[ps->top]=='['){
						pop(ps);
					}
				}else if(cad[i]=='}'){
					if(ps->arreglo[ps->top]=='{'){
						pop(ps);
					}
				}
			}else{
				push(ps,cad[i]);
			}
		}
		i++;
	}
	if(cad[0]==')' || cad[0]==']' || cad[0]=='}' ){
		printf("No esta balanceada\n");
	}else if(ps->top==-1){
		printf("Esta balanceada\n");
	}else{
		printf("No esta balanceada");
	}
}
