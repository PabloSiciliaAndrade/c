#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//subida numero 2

int main(int argc, char *argv[]) {
	Polinomio *polinomio1;
	polinomio1 = (Polinomio *) malloc(sizeof(Polinomio));
	polinomio1->monomio_mayor = (monomio*) malloc(sizeof(monomio));
	leer_polinomio(polinomio1);
	
	//leer_monomio_mayor(*polinomio1);
	imprimir_monomio_mayor(*polinomio1);
	return 0;
}
