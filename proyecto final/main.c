#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//subida numero 2

int main(int argc, char *argv[]) {
	int Cantidad_de_polinomios = 0;
	Polinomio *Lista[] = {(Polinomio*)malloc(sizeof(Polinomio))};


	Cantidad_de_polinomios ++;
	Lista[Cantidad_de_polinomios] = ((Polinomio*)malloc(sizeof(Polinomio)));
	Lista[Cantidad_de_polinomios]->Monomio_menor = ((monomio*)malloc(sizeof(monomio))); 
	//Polinomio*) realloc(Lista, Cantidad_de_polinomios * sizeof(Polinomio)
 	
 	lectura_de_archivo();
 	
	
	//freeMemory(polinomio1);
	//freeMemory(polinomio2);
	//freeMemory(polinomioR);

	return 0;
}
