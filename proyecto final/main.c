#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//subida numero 2

int main(int argc, char *argv[]) {
	int op;
	monomio *monomio1;
	monomio1=(monomio*)malloc(sizeof(monomio));
	int Cantidad_de_polinomios = 0;
	Polinomio *Lista[] = {(Polinomio*)malloc(sizeof(Polinomio)),(Polinomio*)malloc(sizeof(Polinomio))};	
	
	while (op!= 0){
		menu ();
		scanf("%d", &op);
		switch(op){
			case 1:	
			Cantidad_de_polinomios+= 1;
			definir_polinomio_nuevo(Lista[1]);
			imprimir_polinomio(Lista[1]);
			break;
			//agregar aqui la funcion agregar_polinomio
			case 2:
			Cantidad_de_polinomios += 1;
			definir_polinomio_nuevo(Lista[1]);
			Cantidad_de_polinomios += 1;
			definir_polinomio_nuevo(Lista[2]);
			sumar_polinomios(Lista[Cantidad_de_polinomios-2], Lista[Cantidad_de_polinomios-1], Lista[Cantidad_de_polinomios]);
			imprimir_polinomio(Lista[Cantidad_de_polinomios]);
	
			break;
			//agregar aqui la funcion suma_polinomio
			case 3:
			Cantidad_de_polinomios += 1;
			definir_polinomio_nuevo(Lista[1]);
			Cantidad_de_polinomios += 1;
			definir_polinomio_nuevo(Lista[2]);
			break;
			//agregar aqui la funcion restar_polinomio
			case 4:
			Cantidad_de_polinomios += 1;
			definir_polinomio_nuevo(Lista[1]);
			Cantidad_de_polinomios += 1;
			definir_polinomio_nuevo(Lista[2]);
			break;
			//agregar aqui la funcion multiplicación polinomio
			case 5:
			Cantidad_de_polinomios += 1;
			definir_polinomio_nuevo(Lista[1]);
			leer_monomio(monomio1);
			division_polinomio_entre_monomio(Lista[1],monomio1,Lista[Cantidad_de_polinomios]);
			imprimir_polinomio(Lista[Cantidad_de_polinomios]);
			break;
			//agregar aqui la funcion división polinomio entre monomio
			case 6:
			break; 
			//agregar aqui la funcion división polinomio entre binomio
			case 7:
			break;
			//agregar aqui la funcion cargar polinomio
			case 8:
			break;
			//agregar aqui la funcion guardar polinomio
			case 9:
			freeMemory(Lista[Cantidad_de_polinomios]);
			printf("Gracias por usar la calculadora de polinomios, hasta luego\n");
			break; 
			//salir
			default:
				printf("Opcion no valida, intente de nuevo\n"); 
		}
	}

	sumar_polinomios(Lista[Cantidad_de_polinomios-2], Lista[Cantidad_de_polinomios-1], Lista[Cantidad_de_polinomios]);
	imprimir_polinomio(Lista[Cantidad_de_polinomios]);
	
	//freeMemory(polinomio2);
	//freeMemory(polinomioR);

	return 0;
}
