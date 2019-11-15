#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//subida numero 2

int main(int argc, char *argv[]) {
	Polinomio *polinomio1;
	polinomio1 = (Polinomio *) malloc(sizeof(Polinomio));
	polinomio1->Monomio_menor = (monomio*) malloc(sizeof(monomio));
	leer_polinomio(polinomio1);
	ordenar(polinomio1);
	imprimir_polinomio(polinomio1);

	Polinomio *polinomio2;
	polinomio2 = (Polinomio *) malloc(sizeof(Polinomio));
	polinomio2->Monomio_menor = (monomio*) malloc(sizeof(monomio));
	//leer_polinomio(polinomio2);
	//ordenar(polinomio2);

	Polinomio *polinomioR;
	polinomioR = (Polinomio *) malloc(sizeof(Polinomio));
	polinomioR->Monomio_menor = (monomio*) malloc(sizeof(monomio));

	//sumar_polinomios(polinomio1, polinomio2, polinomioR);
	//imprimir_polinomio(polinomioR);

	freeMemory(polinomio1);
	freeMemory(polinomio2);
	freeMemory(polinomioR);

	return 0;
}
