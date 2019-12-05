#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

void leer_monomio(monomio *monomio1){
	printf("introduzca los valores de su monomio:\n" );
	scanf("%g %d", &monomio1->coeficiente, &monomio1->exponente);
}


void leer_polinomio(Polinomio *polinomio){
	printf("introduzca la cantidad de monomios que tiene su polinomio\n");
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
	for (i = 0; i <  polinomio->cantidad_de_monomios; ++i)
	{
		imprimir_monomio(Monox);
		Monox = Monox->siguiente;
	}
	printf("\n");
}


void ordenar(Polinomio *polinomio){

	int potencia, i, j;
	monomio *Monox = polinomio->Monomio_menor;

	for (i = 0; i < polinomio->cantidad_de_monomios; ++i)
	{
		if (Monox->exponente > potencia)
		{
			potencia = Monox->exponente;
		}
		Monox = Monox->siguiente;
	}
	polinomio->potencia = potencia;
	// obtenemos el valor de la potencia mas grande
	
	Polinomio *polinomioT;
	polinomioT = (Polinomio *) malloc(sizeof(Polinomio));
	polinomioT->Monomio_menor = (monomio*) malloc(sizeof(monomio));
	monomio *Monoxt = polinomioT->Monomio_menor;
	
	for (i = 0; i <= polinomio->potencia; ++i)
	{
		Monoxt->exponente = i;
		Monoxt->coeficiente = 0;
		Monoxt->siguiente = (monomio*) malloc(sizeof(monomio));
		Monoxt = Monoxt->siguiente;
	}
	//creamos un polinomio temporal ordenado de menor a mayor

	Monox = polinomio->Monomio_menor;
	for (i = 0; i < polinomio->cantidad_de_monomios; ++i)
	{
		Monoxt = polinomioT->Monomio_menor;
		for (j = 0; j <= polinomio->potencia; ++j)
		{
			if (Monoxt->exponente == Monox->exponente)
			{
				Monoxt->coeficiente = Monox->coeficiente;
			}
			Monoxt = Monoxt->siguiente;
		}
		Monox = Monox->siguiente;
	}

	Monox = polinomio->Monomio_menor;
	Monoxt = polinomioT->Monomio_menor;

	for (i = 0; i <= polinomio->potencia; ++i)
	{

		Monox->coeficiente = Monoxt->coeficiente;
		Monox->exponente = Monoxt->exponente;

		Monoxt = Monoxt->siguiente;
		Monox->siguiente = (monomio*) malloc(sizeof(monomio));
		Monox = Monox->siguiente;
	}
	polinomio->cantidad_de_monomios = polinomio->potencia;
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


void sumar_polinomios(Polinomio *polinomio1, Polinomio *polinomio2, Polinomio *polinomioR){

	monomio *Monox, *Monox1, *Monox2;
	Monox = polinomioR->Monomio_menor;
	Monox1 = polinomio1->Monomio_menor;
	Monox2 = polinomio2->Monomio_menor;
	int i, j;
	for (i = 0; i <= polinomio1->cantidad_de_monomios; ++i)
	{
		Monox = polinomioR->Monomio_menor;
		Monox2 = polinomio2->Monomio_menor;
		
		for (j = 0; j <= polinomio2->cantidad_de_monomios; ++j)
		{
			Monox->siguiente = ((monomio*)malloc(sizeof(monomio)));
			sumar_monomios(Monox1, Monox2, Monox);
			Monox = Monox->siguiente;
			Monox2 = Monox2->siguiente;
		}
		Monox1 = Monox1->siguiente;
	}
}


void sumar_monomios(monomio *monomio1, monomio *monomio2, monomio *monomioR){
	if (monomio1->exponente = monomio2->exponente)
	{
	monomioR->coeficiente = monomio1->coeficiente + monomio2->coeficiente;
	monomioR->exponente = monomio1->exponente;
	}
}


void menu (){
	printf("1: sumar polinomios \n");
	printf("2: restar polinomios \n");
	printf("3: multiplicar polinomios \n");
	printf("4: dividir monomio entre polinomio \n");
	printf("5: salir \n");
}


void definir_polinomio_nuevo(Polinomio *polinomio){
	polinomio = ((Polinomio*)malloc(sizeof(Polinomio)));
	polinomio->Monomio_menor = ((monomio*)malloc(sizeof(monomio))); 
	leer_polinomio(polinomio);
	ordenar(polinomio);
}


void reservar_memoria(Polinomio *polinomio){
	polinomio = ((Polinomio*)malloc(sizeof(Polinomio)));
	polinomio->Monomio_menor = ((monomio*)malloc(sizeof(monomio)));
}