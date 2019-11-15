#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

void leer_monomio(monomio *monomio1){
	scanf("%g %c %d", &monomio1->coeficiente, &monomio1->variable, &monomio1->exponente);
	

}
void leer_polinomio(Polinomio *polinomio){
	scanf("%d", &polinomio->cantidad_de_monomios);
	int i;
	monomio *Monox = polinomio->monomio_mayor; 
	for (i = 0; i < polinomio->cantidad_de_monomios; ++i)
	{
		Monox->siguiente = (monomio*) malloc(sizeof(monomio));
		leer_monomio(Monox);
		Monox = Monox->siguiente;
	}
	
	
}
void imprimir_monomio(monomio *monomio){
	if (monomio->coeficiente < 0)
	{
		printf("%g %c^%d ",monomio->coeficiente, monomio->variable, monomio->exponente );
	}else{
		printf(" +%g %c^%d ",monomio->coeficiente, monomio->variable, monomio->exponente );
	}
}
void imprimir_polinomio(Polinomio *polinomio){
	monomio *Monox = polinomio->monomio_mayor; 
	int i;
	for (i = 0; i < polinomio->cantidad_de_monomios; ++i)
	{
		imprimir_monomio(Monox);
		Monox = Monox->siguiente;
	}
	
}
void menu (){
	printf("1: sumar polinomios \n");
	printf("2: restar polinomios \n");
	printf("3: multiplicar polinomios \n");
	printf("4: dividir monomio entre polinomio \n");
	printf("5: salir \n");
}
