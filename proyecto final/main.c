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
	
	int op;
	monomio polinomio1, polinomio2, monomio;

	do 
	{
		menu();
		scanf("%d", &op);

<<<<<<< Updated upstream
		switch (op){
			case 1:
				suma = suma(polinomio1, polinomio2);
				break;
			case 2:
				resta = resta(polinomio1, polinomio2);
				break;
			case 3:
				multiplicaciOn = multiplicaciOn(polinomio1, polinomio2);
				break;
			case 4:
				divisiOn = divisiOn(monomio, polinomio1);
				break;
		}
	}while (op <5);
=======
	sumar_polinomios(Lista[Cantidad_de_polinomios-2], Lista[Cantidad_de_polinomios-1], Lista[Cantidad_de_polinomios]);
	imprimir_polinomio(Lista[Cantidad_de_polinomios]);
	freeMemory(Lista[Cantidad_de_polinomios]);
	//freeMemory(polinomio2);
	//freeMemory(polinomioR);
	//HOLO
>>>>>>> Stashed changes

	return 0;
}
