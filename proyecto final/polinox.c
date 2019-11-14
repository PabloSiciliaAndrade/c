#include <stdio.h>
#include "polinox.h"

Polinomio polinomio1;

void leer_monomio_mayor(polinomio polinomio1){
	scanf("%g %c %d", & polinomio1.monomio_mayor.coeficiente, & polinomio1.monomio_mayor.variable, & polinomio1.monomio_mayor.exponente);
}
void imprimir_monomio_mayor(polinomio polinomio1){
	printf("el polinomio es: %g %c^%d", polinomio1.monomio_mayor.coeficiente, polinomio1.monomio_mayor.variable, polinomio1.monomio_mayor.exponente );
}
void menu (){
	printf("1: sumar polinomios \n");
	printf("2: restar polinomios \n");
	printf("3: multiplicar polinomios \n");
	printf("4: dividir monomio entre polinomio \n");
	printf("5: salir \n");
}