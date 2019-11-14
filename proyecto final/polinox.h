#ifndef POLINOX_H
#define POLINOX_H

typedef struct monomios {
	float coeficiente;
	char variable;
	int exponente;
}monomio;

typedef struct polinomios {
	monomio monomio_mayor;
	monomio *siguiente;
	int termino_independiente;
}Polinomio;

void leer_polinomio();
void leer_monomio_mayor(Polinomio polinomio1);
void imprimir_monomio_mayor(Polinomio polinomio1);

#endif
