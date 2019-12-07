#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//subida numero 2

int main(int argc, char *argv[]) {
	int Cantidad_de_polinomios = 0;
	Polinomio *Lista[] = {(Polinomio*)malloc(sizeof(Polinomio)),(Polinomio*)malloc(sizeof(Polinomio))};

	Cantidad_de_polinomios += 1;
	definir_polinomio_nuevo(Lista[Cantidad_de_polinomios]);
	printf("%f\n",Lista[Cantidad_de_polinomios]->Monomio_menor->siguiente->coeficiente);
	printf("%d\n",Lista[Cantidad_de_polinomios]->Monomio_menor->siguiente->exponente);
	//imprimir_polinomio(Lista[Cantidad_de_polinomios]);

	Cantidad_de_polinomios += 1;
	definir_polinomio_nuevo(Lista[Cantidad_de_polinomios]);
	printf("definicion completa\n");

	Cantidad_de_polinomios += 1;
	reservar_memoria(Lista[Cantidad_de_polinomios]);
	printf("memoria reservada\n");

	sumar_polinomios(Lista[(Cantidad_de_polinomios-2)], Lista[(Cantidad_de_polinomios-1)], Lista[(Cantidad_de_polinomios)]);
	printf("polinomios sumados\n");
	imprimir_polinomio(Lista[Cantidad_de_polinomios]);
	freeMemory(Lista[Cantidad_de_polinomios]);
	//freeMemory(polinomio2);
	//freeMemory(polinomioR);

	return 0;
}
