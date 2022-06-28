#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int codigo;
	float precio;
	int cantidad;
	struct nodo *sig;
	struct nodo *ant;
};


void insertar(struct nodo *, int ,float, int );
void imprime(struct nodo *);
void eliminar(struct nodo *, int );
void borrar(struct nodo *);
void imprimeR(struct nodo*);
void buscar(struct nodo *, int);

int main(){
	struct nodo *lista=NULL;
	lista=new(nodo);
	lista->sig=NULL;
	int dato,opcion,cantidad;
	float precio;
	do{
		system("cls");
		printf("Menu\n1. Insertar\n2. Imprimir\n3. borrar dato\n4. imprime desde el final\n5. Buscar producto\n6. salir\n");
		printf("Ingrese una opcion: ");
		fflush(stdin);
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				system("cls");
				printf("Ingrese el codigo del poducto: ");
				scanf("%d",&dato);
				printf("Ingrese el precio: ");
				scanf("%f",&precio);
				printf("Ingrese la cantidad: ");
				scanf("%d",&cantidad);
				insertar(lista,dato,precio,cantidad);
			break;
			case 2:
				imprime(lista);
			break;
			case 3:
				printf("Ingrese el codigo del producto a borrar: ");
				scanf("%d",&dato);
				eliminar(lista,dato);
			break;
			case 4:
				system("cls");
				imprimeR(lista);
			break;
			case 5:
				system("cls");
				printf("Ingrese el codigo del producto a revisar: ");
				scanf("%d",&dato);
				buscar(lista,dato);
			break;
			case 6:
				borrar(lista);
				printf("Adios");
			break;
			default:
				printf("Opcion invalida");
				break;
		}
	}while(opcion!=6);
}


void insertar(struct nodo *inicio, int x, float precio, int cantidad){
	struct nodo *temp, *p, *q;
	p=inicio;
	temp=new(nodo);
	temp->codigo=x;
	temp->precio=precio;
	temp->cantidad=cantidad;
	if(p->sig==NULL){
		inicio->sig=temp;
		inicio->ant=NULL;
		temp->ant=inicio;
		temp->sig=NULL;
	}else{
		while(p!=NULL){
			q=p;
			p=p->sig;
		}
		q->sig=temp;
		temp->ant=q;
		temp->sig=NULL;	
	}
	system("cls");
}
void imprime(struct nodo *inicio){
	struct nodo *p;
	p=inicio;
	system("cls");
	p=p->sig;
	printf("Inventario\n");
	printf("Codigo | Precio | Cantidad\n");
	while(p!=NULL){
		printf("%d      | %.2f\t| %d\n",p->codigo, p->precio,p->cantidad);
		p=p->sig;
	}
	fflush(stdin);
	getchar();
	system("cls");
}
void eliminar(struct nodo *inicio, int x){
	struct nodo *p,*q,*aux;
	p=inicio;
	q=p;
	aux=p;
	aux=aux->sig;
	p=p->sig;
	while(aux->codigo!=x && aux!=NULL) {
		q=q->sig;
		p=p->sig;
		aux=aux->sig;
	}
	if(aux->sig==NULL && aux->codigo==x){
		q->sig=NULL;
		free(aux);
	}else{
		p=p->sig;
		q->sig=p;
		p->ant=q;
		free(aux);
	}
}
void borrar(struct nodo *inicio){
	struct nodo *temp;
	temp=inicio;
	while(temp!=NULL){
		inicio=inicio->sig;
		free(temp);
		temp=inicio;
	}
	system("cls");
}

void imprimeR(struct nodo *inicio){
	struct nodo *p;
	p=inicio;
	p=p->sig;
	while(p->sig!=NULL){
		p=p->sig;
	}
	while(p!=inicio){
		printf("%d      | %.2f\t| %d\n",p->codigo, p->precio,p->cantidad);
		p=p->ant;
	}
	printf("\n");
	fflush(stdin);
	getchar();
}
void buscar(struct nodo *inicio, int codigo){
	struct nodo *p,*q,*aux;
	system("cls");
	p=inicio;
	q=p;
	aux=p;
	aux=aux->sig;
	p=p->sig;
	while(aux->codigo!=codigo && aux!=NULL) {
		q=q->sig;
		p=p->sig;
		aux=aux->sig;
	}
	printf("El producto buscado tiene de codigo: %d\n",aux->codigo);
	printf("el producto tiene un costo de: %.2f y quedan %d en inventario\n",aux->precio,aux->cantidad);
	fflush(stdin);
	getchar();
}
