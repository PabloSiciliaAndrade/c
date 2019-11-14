#include <stdio.h>
#include "polinox.h"

Polinomio polinomio1;

void leer_monomio_mayor(polinomio polinomio1){
	scanf("%g %c %d", & polinomio1.monomio_mayor.coeficiente, & polinomio1.monomio_mayor.variable, & polinomio1.monomio_mayor.exponente);
}
void imprimir_monomio_mayor(polinomio polinomio1){
	printf("el polinomio es: %g %c^%d", polinomio1.monomio_mayor.coeficiente, polinomio1.monomio_mayor.variable, polinomio1.monomio_mayor.exponente );
}
