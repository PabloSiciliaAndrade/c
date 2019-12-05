#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//subida numero 2

int main(int argc, char *argv[]) {
	int Cantidad_de_polinomios = 0;
	Polinomio *Lista[] = {(Polinomio*)malloc(sizeof(Polinomio)),(Polinomio*)malloc(sizeof(Polinomio))};

	Cantidad_de_polinomios += 1;
	definir_polinomio_nuevo(Lista[1]);

	Cantidad_de_polinomios += 1;
	definir_polinomio_nuevo(Lista[2]);

	Cantidad_de_polinomios += 1;
	reservar_memoria(Lista[Cantidad_de_polinomios]);

	sumar_polinomios(Lista[Cantidad_de_polinomios-2], Lista[Cantidad_de_polinomios-1], Lista[Cantidad_de_polinomios]);
	imprimir_polinomio(Lista[Cantidad_de_polinomios]);
	freeMemory(Lista[Cantidad_de_polinomios]);
	//freeMemory(polinomio2);
	//freeMemory(polinomioR);

	return 0;
}
