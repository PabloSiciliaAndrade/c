#include <stdio.h>
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
void imprimir_monomio_mayor(Polinomio polinomio1){
	printf("el polinomio es: %g %c^%d",polinomio1.monomio_mayor->coeficiente, polinomio1.monomio_mayor->variable, polinomio1.monomio_mayor->exponente );
}
void menu (){
	printf("1: sumar polinomios \n");
	printf("2: restar polinomios \n");
	printf("3: multiplicar polinomios \n");
	printf("4: dividir monomio entre polinomio \n");
	printf("5: salir \n");
}
void freeMemory (Polinomio *polinomio){
	int i, j;
	monomio *Monox = polinomio->monomio_mayor;
	for (i = 0; i < polinomio->cantidad_de_monomios; ++i)
	{
		for (j = 0; j < (polinomio->cantidad_de_monomios - i); ++j)
		{
			if (Monox->siguiente == NULL)
			{
				free(Monox);
			}else{
				Monox = Monox->siguiente;
			}
		}
	}
}
