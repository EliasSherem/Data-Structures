#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *izq;
	struct nodo *der;
};


void insertar(struct nodo *, int);
void preorden(struct nodo *);
void postorden(struct nodo *);
void inorden(struct nodo *);
struct nodo *nuevoNodo(int);
void eliminar_nodo(struct nodo *,int *);
struct nodo *buscar_valor(struct nodo *, int);
int dif(struct nodo *,int, int);


int main(){
	struct nodo *raiz;
	int opc;
	int x;
	int i=0;
	int diferencia, min=9999, max=0;
	do{
		printf("\nPresione Enter para continuar");
		fflush(stdin);
		getchar();
		system("cls");
		printf("Menu\n1. insertar\n2. imprimir preorden\n3. imprimir postorden\n4. imprimir inorden\n5. diferencia entre maximo y minimo\n6.salir\n");
		printf("Ingrese una opcion: ");
		scanf("%d",&opc);
		switch(opc){
			case 1: 
				system("cls");
				printf("Inserte un numero: ");
				scanf("%d",&x);
				if(i==0){
					raiz=nuevoNodo(x);
					i++;
				}else{
					insertar(raiz,x);
				}
			break;
			case 2: 
				system("cls");
				printf("imprimiendo preorden\n");
				preorden(raiz);
			break;
			case 3: 
				system("cls");
				printf("imprimiendo postorden\n");
				postorden(raiz);
			break;
			case 4: 
				system("cls");
				printf("imprimiendo inorden\n");
				inorden(raiz);
				
			break;
			case 5:
				diferencia=dif(raiz,max,min);
				printf("La diferencia entre el maximo y el minimo es de %d", diferencia);
			break;
			case 6: printf("Hasta luego");
			break;
			default: printf("Opcion invalida");
			break;
		}
	}while(opc!=6);
}



void insertar(struct nodo *raiz, int x){
	if(x>=raiz->dato){
		if(raiz->der==NULL){
			raiz->der=nuevoNodo(x);
		}else{
			insertar(raiz->der,x);
		}
	}else{
		if(raiz->izq==NULL){
			raiz->izq=nuevoNodo(x);
		}else{
			insertar(raiz->izq,x);
		}
	}
}
void preorden(struct nodo *raiz){
	if(raiz!=NULL){
		printf("%d ",raiz->dato);
		preorden(raiz->izq);
		preorden(raiz->der);
	}
}
void postorden(struct nodo *raiz){
	if(raiz!=NULL){
		postorden(raiz->izq);
		postorden(raiz->der);
		printf("%d ",raiz->dato);
	}
}
void inorden(struct nodo *raiz){
	if(raiz!=NULL){
		inorden(raiz->izq);
		printf("%d ",raiz->dato);
		inorden(raiz->der);
	}
}
struct nodo *nuevoNodo(int x){
	struct nodo *raiz;
	raiz=new(nodo);
	raiz->dato=x;
	raiz->izq=NULL;
	raiz->der=NULL;
	return raiz;
}
/*void eliminar_nodo(struct nodo *arbol,int valor)	{
	struct nodo *n;
	struct nodo *padre;
	struct nodo *derecho;
	struct nodo *izquierdo;
	n = buscar_valor(arbol,valor);
	if(n)	{
 
		if(n->der == NULL && n->izq == NULL)	{
			//No tiene hijos, hay que determinar si es el hijo derecho o izquierdo de su padre y desvincularlo
			padre = n->padre;
			if(padre->der == n)	{
				padre->der = NULL;
				free(n);
			}
			else	{
				padre->izq = NULL;
				free(n);			
			}
		}
		else	{
			if(n->der != NULL && n->izq != NULL)	{
				// Tiene 2 Hijos
				padre = n->padre;
				// Detalle aqui.....
 
			}
			else	{
				if(n->der != NULL)	{	//Solo tiene al hijo derecho
					derecho = n->der;
					padre = n->padre;
					if(padre->der == n)	{ //hay que determinar si es el hijo derecho o izquierdo de su padre y vincular dicho nodo, con el nodo derecho del n actual y liberar n despues de eso
						padre->der = derecho;
						free(n);
					}
					else	{
						padre->izq = derecho;
						free(n);			
					}
				}
				else	{	//Solo tiene al hijo izquierdo
					izquierdo = n->izq;
					padre = n->padre;
					if(padre->der == n)	{ //hay que determinar si es el hijo derecho o izquierdo de su padre y vincular dicho nodo, con el nodo izquierdo del n actual y liberar n despues de eso
						padre->der = izquierdo;
						free(n);
					}
					else	{
						padre->izq = izquierdo;
						free(n);			
					}
				}
			}
		}
	}
	else	{
		printf("No existe un nodo con el valor \"%s\" en el arbol\n",valor);
	}	
}*/
struct nodo *buscar_valor(struct nodo *raiz, int valor){
	if (raiz == NULL){
        return NULL;
    }else{
        if (valor == raiz->dato){
            return raiz;
        }else{
            if (valor < raiz->dato){
                return buscar_valor(raiz->izq, valor);
            }else{
                return buscar_valor(raiz->der, valor);
            }
        }
    }
}
int dif(struct nodo *raiz,int max, int min){
	if(raiz!=NULL){
		dif(raiz->der,max,min);
		if(raiz->dato > max){
			max=raiz->dato;
			
		}else if(raiz->dato<min){
			min=raiz->dato;
			
		}else{
			return max-min;	
		}
		dif(raiz->izq,max,min);
	}

}


