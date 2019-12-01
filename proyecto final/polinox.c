#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

void leer_monomio(monomio *monomio1){
	printf("introdusca los valores de su monomio:\n" );
	scanf("%g %d", &monomio1->coeficiente, &monomio1->exponente);
}


void leer_polinomio(Polinomio *polinomio){
	printf("introdusca la cantidad de monomios que tiene su polinomio\n");
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
	// obtenemos el valor de la potencia del polinimio mas grande
	printf("%d\n",polinomio->potencia);
	
	Polinomio *polinomioT;
	polinomioT = (Polinomio *) malloc(sizeof(Polinomio));
	polinomioT->Monomio_menor = (monomio*) malloc(sizeof(monomio));
	monomio *Monoxt = polinomioT->Monomio_menor;
	
	for (i = 0; i <= polinomio->potencia; ++i)
	{
		Monoxt->exponente = i;
		printf("%d\n",i);
		Monoxt = Monoxt->siguiente;
	}
	printf("polinomio temporal creado...\n");
	//creamos un polinomio temporal ordenado de menor a mayor

	Monox = polinomio->Monomio_menor;
	Monoxt = polinomioT->Monomio_menor;

	for (i = 0; i < polinomio->cantidad_de_monomios; ++i)
	{
		for (j = 0; i < polinomio->potencia; ++i)
		{
			if (Monoxt->exponente = Monox->exponente)
			{
				Monoxt->coeficiente = Monox->coeficiente;
			}
			else{
				Monoxt->coeficiente = 0;
			}
			Monoxt = Monoxt->siguiente;
		}
		Monox = Monox->siguiente;
	}
	printf("pasando datos a temporal...\n");

	Monox = polinomio->Monomio_menor;
	Monoxt = polinomioT->Monomio_menor;

	

	for (i = 0; i < polinomio->potencia; ++i)
	{
		Monox->coeficiente = Monoxt->coeficiente;
		Monox->exponente = Monoxt->exponente;

		Monoxt = Monoxt->siguiente;
		Monox = Monox->siguiente;
	}
	polinomio->cantidad_de_monomios = polinomio->potencia;
	printf("datos guardados en polinomio original \n");

	freeMemory(polinomioT);
	/*
	monomio *Monoxi;
	monomio *Monoxj;
	
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
	*/
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
	int i;
	if (polinomio1->cantidad_de_monomios <= polinomio2->cantidad_de_monomios)
	{
		polinomioR->cantidad_de_monomios = polinomio2->cantidad_de_monomios;
		for (i = 0; i < polinomio2->cantidad_de_monomios; ++i)
		{

			sumar_monomios(Monox1, Monox2, Monox);
			Monox = Monox->siguiente;
			Monox1 = Monox1->siguiente;
			Monox2 = Monox2->siguiente;

		}
	}else{
		polinomioR->cantidad_de_monomios = polinomio1->cantidad_de_monomios;
		for (i = 0; i < polinomio1->cantidad_de_monomios; ++i)
		{
			sumar_monomios(Monox1, Monox2, Monox);
			Monox = Monox->siguiente;
			Monox1 = Monox1->siguiente;
			Monox2 = Monox2->siguiente;
		}
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
