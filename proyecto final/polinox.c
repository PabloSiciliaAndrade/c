#ifndef "polinox.h"
#define "polinox.h"


typedef struct monomios{
	float coeficiente;
	char variable;
	int exponente;
}monomio;

typedef struct polinomio{
	monomio monomio_mayor;
	monomio siguiente;
}polinomio;