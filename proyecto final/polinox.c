#include <stdio.h>
#include <stdlib.h>
#include "polinox.h"
//Incluimos POLINOX.H para traer las estructuras monomio y polinomio.

void leer_monomio(monomio *monomio1){
	printf("introduzca los valores de su monomio:\n" );
	scanf("%g %d", &monomio1->coeficiente, &monomio1->exponente);
}
//La funci? leer monomio le pide al usuario que introduzca los valores del monomio, coeficiente y exponente, para despues escanearlos.

void leer_polinomio(Polinomio *polinomio){
	printf("introduzca la cantidad de monomios que tiene su polinomio\n");
	scanf("%d", &polinomio->cantidad_de_monomios);
	int i;
	monomio *Monox = polinomio->Monomio_menor; 
	for (i = 0; i < polinomio->cantidad_de_monomios; ++i)
	{
		Monox->siguiente = (monomio*) malloc(sizeof(monomio));
		leer_monomio(Monox);
		Monox = Monox->siguiente;
	}
}
//En la funci? leer polinomio, utilizamos la subvariable de la estructura polinomio "cantidad de monomios" y el entero i
//para compararlos en un ciclo for, donde despues de declarar una variable monomio tipo apuntador (llamada Monox) e igualarla a la subvariable polinomio.monomio_menor,
//asignamos memoria por medio de malloc para cada monomio, llamamos la funcion leer monomio para escanear los valores de Monox y recorremos monox al monomio siguiente (que es un apuntador).

void imprimir_monomio(monomio *monomio){
	if (monomio->coeficiente < 0)
	{
		printf("%g X^%d ",monomio->coeficiente, monomio->exponente );
	}else{
		printf(" +%g X^%d ",monomio->coeficiente, monomio->exponente );
	}
}
//En la funci? imprimir monomio, no solo imprimimos el monomio en si, sino que por medio de un if buscamos si su coeficiente es positivo o negativo
//para imprimirlo con su signo correspondiente.

void imprimir_polinomio(Polinomio *polinomio){
	monomio *Monox = polinomio->Monomio_menor; 
	int i;
	for (i = 0; i <  polinomio->cantidad_de_monomios; ++i)
	{
		imprimir_monomio(Monox);
		Monox = Monox->siguiente;
	}
	printf("\n");
}
//En la funci? imprimir polinomio, utilizamos un monomio temporal tipo apuntador (Monox) que lo dirigimos a la subvariable monomio_menor,
//donde usando la cantidad de monomios antes especificada y una entero (i), generamos un for que llame la funci? imprimir monomio
//la cantidad de veces que sean la cantidad de monomios especificados, para despues recorrer Monox a monox_siguiente.

void ordenar(Polinomio *polinomio){
//La funci? ordenar polinomios se divide en 3 partes:
	int potencia, i, j;
	monomio *Monox = polinomio->Monomio_menor;

	for (i = 0; i < polinomio->cantidad_de_monomios; ++i)
	{
		if (Monox->exponente > potencia)
		{
			potencia = Monox->exponente;
		}
		Monox = Monox->siguiente;
	}
	polinomio->potencia = potencia;
	// Donde por el primer ciclo for, obtenemos el valor de la potencia mas grande comparando los exponentes de los monomios.
	
	Polinomio *polinomioT;
	polinomioT = (Polinomio *) malloc(sizeof(Polinomio));
	polinomioT->Monomio_menor = (monomio*) malloc(sizeof(monomio));
	monomio *Monoxt = polinomioT->Monomio_menor;
	
	for (i = 0; i <= polinomio->potencia; ++i)
	{
		Monoxt->exponente = i;
		Monoxt->coeficiente = 0;
		Monoxt->siguiente = (monomio*) malloc(sizeof(monomio));
		Monoxt = Monoxt->siguiente;
	}
	//En esta parte, creamos un polinomio temporal y le reservamos memoria con malloc.
	//Tambien creamos su subvariable  monomio menor, asignandole memoria con malloc y despues asignandole el monomio temporal Monoxt.
	//Finalmente, con el siguiente for, creamos una lista de monomios con los exponentes restantes desde exponente 0 hasta la potencia mas grande.

	Monox = polinomio->Monomio_menor;
	for (i = 0; i < polinomio->cantidad_de_monomios; ++i)
	{
		Monoxt = polinomioT->Monomio_menor;
		for (j = 0; j <= polinomio->potencia; ++j)
		{
			if (Monoxt->exponente == Monox->exponente)
			{
				Monoxt->coeficiente = Monox->coeficiente;
			}
			Monoxt = Monoxt->siguiente;
		}
		Monox = Monox->siguiente;
	}

	Monox = polinomio->Monomio_menor;
	Monoxt = polinomioT->Monomio_menor;

	for (i = 0; i <= polinomio->potencia; ++i)
	{

		Monox->coeficiente = Monoxt->coeficiente;
		printf("%f ",Monox->coeficiente);
		Monox->exponente = Monoxt->exponente;
		printf("%i\n",Monox->exponente);

		Monoxt = Monoxt->siguiente;
		Monox->siguiente = (monomio*) malloc(sizeof(monomio));
		Monox = Monox->siguiente;
	}
	polinomio->cantidad_de_monomios = polinomio->potencia;
}
//Concluimos esta funci? con 2 ciclos for, donde el primero se encarga de comparar la lista de monomios anterior creada con los monomios introducidos.
//Si los exponentes del monomio real como el monomio temporal de la lista coincidian, se asignaban el coeficiente real al coeficiente del monomio temporal, asi pasando datos a la lista.


void freeMemory(Polinomio *polinomio){
	int i, j;
	monomio *Monox = polinomio->Monomio_menor;
	for (i = 0; i < polinomio->cantidad_de_monomios; ++i)
	{
		for (j = 0; j < polinomio->cantidad_de_monomios-i; ++j)
		{
			if (Monox->siguiente == NULL)
			{
				free(Monox);
			}
			Monox = Monox->siguiente;
		}
	}
}
//En la funci? freeMemory, liberamos memoria al momento de recorrer el conjunto polinomio, donde buscariamos que el monox siguiente equivaliera a 0.
//Una vez que encontraramos el monomio 0, a partir de ahi podriamos empezar a liberar memoria para limpiar completamente el polinomio.

void sumar_polinomios(Polinomio *polinomio1, Polinomio *polinomio2, Polinomio *polinomioR){

	monomio *Monox;
	monomio *Monox1;
	monomio *Monox2;
	Monox = polinomioR->Monomio_menor;
	Monox1 = polinomio1->Monomio_menor;
	Monox2 = polinomio2->Monomio_menor;
	printf("definicion de monomios\n");
	int i, j;
	for (i = 0; i <= polinomio1->cantidad_de_monomios; ++i)
	{
		Monox = polinomioR->Monomio_menor;
		Monox2 = polinomio2->Monomio_menor;
		printf("definicion de monomios %d\n",i);
		
		for (j = 0; j <= polinomio2->cantidad_de_monomios; ++j)
		{
			Monox->siguiente = ((monomio*)malloc(sizeof(monomio)));
			sumar_monomios(Monox1, Monox2, Monox);
			Monox = Monox->siguiente;
			Monox2 = Monox2->siguiente;
		}
		Monox1 = Monox1->siguiente;
	}
}


void sumar_monomios(monomio *monomio1, monomio *monomio2, monomio *monomioR){
	if (monomio1->exponente = monomio2->exponente)
	{
	monomioR->coeficiente = monomio1->coeficiente + monomio2->coeficiente;
	monomioR->exponente = monomio1->exponente;
	}
}
//Funci? sumar monomios, donde solamente compara los exponentes de los monomios a sumar y si estos coinciden, se suma sus coeficientes.

void menu (){
	printf("1: agregar polinomios\n");
	printf("2: sumar polinomios \n");
	printf("3: restar polinomios \n");
	printf("4: multiplicar polinomios \n");
	printf("5: dividir polinomio entre monomio\n");
	printf("6: dividir polinomio entre binomio\n");
	printf("7: cargar polinomio\n");
	printf("8: guardar polinomio\n");
	printf("9: salir \n");
}
//Funci? menu, que despliega las opciones que indican las diferentes funciones que la calculadora puede realizar.

void definir_polinomio_nuevo(Polinomio *polinomio){
	polinomio = ((Polinomio*)malloc(sizeof(Polinomio)));
	polinomio->Monomio_menor = ((monomio*)malloc(sizeof(monomio))); 
	leer_polinomio(polinomio);
	ordenar(polinomio);
}
//Funci? definir polinomio nueva: Esta funci? genera la memoria necesaria para el polinomio y subvariable monomio menor, para despues llamar a
//la funci? leer polinomio y ordenar polinomio.

void reservar_memoria(Polinomio *polinomio){
	polinomio = ((Polinomio*)malloc(sizeof(Polinomio)));
	polinomio->Monomio_menor = ((monomio*)malloc(sizeof(monomio)));
}
//La funci? resevar memoria, genera memoria para los polinomios y sus monomios con malloc.
