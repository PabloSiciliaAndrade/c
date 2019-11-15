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
	int i, j, k;
	monomio Monoxt;
	for (k = 0,Monoxi = polinomio->Monomio_menor; k < polinomio->cantidad_de_monomios; ++k)
	{
		for (i = 0; i < polinomio->cantidad_de_monomios -1; ++i)
		{
			for (j = 0 + i, Monoxj = polinomio->Monomio_menor; j < polinomio->cantidad_de_monomios -1; ++j)
			{

				if (Monoxj->siguiente->exponente > Monoxi->exponente)
				{
					Monoxt.coeficiente = Monoxi->coeficiente, Monoxt.exponente = Monoxi->exponente;
					Monoxi->coeficiente = Monoxj->coeficiente, Monoxi->exponente = Monoxj->exponente;
					Monoxj->coeficiente = Monoxt.coeficiente, Monoxj->exponente = Monoxt.exponente;
				}
				Monoxj = Monoxj->siguiente;

			}
		}

		Monoxi = Monoxi->siguiente;
		
	}
	
}

void menu (){
	printf("1: sumar polinomios \n");
	printf("2: restar polinomios \n");
	printf("3: multiplicar polinomios \n");
	printf("4: dividir monomio entre polinomio \n");
	printf("5: salir \n");
}
