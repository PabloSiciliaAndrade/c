#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//subida numero 2

int main(int argc, char *argv[]) {
	Polinomio *polinomio_inicial;
	polinomio_inicial = (Polinomio *) malloc(sizeof(Polinomio));
	polinomio_inicial->monomio_mayor = (monomio*) malloc(sizeof(monomio));
	leer_monomio(polinomio_inicial->monomio_mayor);
	
	//leer_monomio_mayor(*polinomio_inicial);
	imprimir_monomio_mayor(*polinomio_inicial);
	return 0;
}
