#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Polinomio *polinomio_inicial;

int main(int argc, char *argv[]) {
	leer_monomio_mayor(*polinomio_inicial);
	imprimir_monomio_mayor(*polinomio_inicial);
	return 0;
}
