#include <stdio.h>

int main(){
	int valor[100];
	int i;
	
	for(i=0;i<100;i++){
		valor[i]=55;
	}
	for(i=0;i<100;i++){
		printf("%d\n",valor[i]);
	}
}
