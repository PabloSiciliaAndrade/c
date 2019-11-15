#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

void leer_monomio(monomio *monomio1){
	scanf("%g %d", &monomio1->coeficiente, &monomio1->exponente);
	

}
void leer_polinomio(Polinomio *polinomio){
	scanf("%d", &polinomio->cantidad_de_monomios);
	int i;
	monomio *Monox = polinomio->Monomio_menor; 
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
		printf("%g X^%d ",monomio->coeficiente, monomio->exponente );
	}else{
		printf(" +%g X^%d ",monomio->coeficiente, monomio->exponente );
	}
}
void imprimir_polinomio(Polinomio *polinomio){
	monomio *Monox = polinomio->Monomio_menor; 
	int i;
	for (i = 0; i < polinomio->cantidad_de_monomios; ++i)
	{
		imprimir_monomio(Monox);
		Monox = Monox->siguiente;
	}
	printf("\n");
}
void ordenar(Polinomio *polinomio){
	monomio *Monoxi;
	monomio *Monoxj;
	monomio Monoxt;
	int i, j, k;
	for (i = 0; i < polinomio->cantidad_de_monomios - 1; ++i)
	{
		Monoxi = polinomio->Monomio_menor;
		Monoxj = polinomio->Monomio_menor;
		for (j = 0; j < polinomio->cantidad_de_monomios - i - 1; ++j)
		{
			if (Monoxj->exponente > Monoxj->siguiente->exponente)
			{
				Monoxt.exponente = Monoxj->siguiente->exponente, Monoxt.coeficiente = Monoxj->siguiente->coeficiente;
				Monoxj->siguiente->exponente = Monoxj->exponente, Monoxj->siguiente->coeficiente = Monoxj->coeficiente;
				Monoxj->exponente = Monoxt.exponente, Monoxj->coeficiente = Monoxt.coeficiente;
			}
			Monoxj = Monoxj->siguiente;
		}
	}
	
	
}
void freeMemory(Polinomio *polinomio){
	int i, j;
	monomio *Monox = polinomio->Monomio_menor;
	for (i = 0; i < polinomio->cantidad_de_monomios; ++i)
	{
		for (j = 0; j < polinomio->cantidad_de_monomios-i; ++j)
		{
			if (Monox->siguiente == NULL)
			{
				free(Monox);
			}
			Monox = Monox->siguiente;
		}
	}
}

void menu (){
	printf("1: sumar polinomios \n");
	printf("2: restar polinomios \n");
	printf("3: multiplicar polinomios \n");
	printf("4: dividir monomio entre polinomio \n");
	printf("5: salir \n");
}
