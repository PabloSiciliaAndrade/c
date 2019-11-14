#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Polinomio polinomio1;
polinomio1.monomio_mayor.coeficiente = 1;
polinomio1.siguiente = NULL;
int main(int argc, char *argv[]) {
	leer_monomio_mayor(polinomio1);
	imprimir_monomio_mayor(polinomio1);
	return 0;
}
