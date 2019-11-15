#ifndef POLINOX_H
#define POLINOX_H

typedef struct monomios monomio;
struct monomios {
	float coeficiente;
	int exponente;
	monomio *siguiente;
};

typedef struct polinomios {
	monomio *Monomio_menor;
	int cantidad_de_monomios;
	int termino_independiente;
}Polinomio;

void leer_polinomio(Polinomio *polinomio);
void leer_monomio_mayor(Polinomio *polinomio1);
void imprimir_monomio(monomio *monomio);
void imprimir_polinomio(Polinomio *polinomio);
void leer_monomio(monomio *monomio1);
void freeMemory(Polinomio *polinomio);
void ordenar(Polinomio *polinomio);
void sumar_polinomios(Polinomio *polinomio1, Polinomio *polinomio2, Polinomio *PolinomioR);
void sumar_monomios(monomio *monomio1, monomio * monomio2, monomio *monomioR);
#endif
