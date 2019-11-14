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

	return 0;
}
