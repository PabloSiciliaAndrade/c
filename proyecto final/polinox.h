#ifndef POLINOX_H
#define POLINOX_H

typedef struct monomios monomio;
struct monomios {
	float coeficiente;
	char variable;
	int exponente;
	monomio *siguiente;
};

typedef struct polinomios {
	monomio *monomio_mayor;
	int termino_independiente;
}Polinomio;

void leer_polinomio();
void leer_monomio_mayor(Polinomio *polinomio1);
void imprimir_monomio_mayor(Polinomio polinomio1);
void leer_monomio(monomio *monomio1);

#endif
