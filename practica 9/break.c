#include <stdio.h> 
 
/*  
* Este programa hace una suma de números. Si la suma rebasa la cantidad  
* de 50 el programa se detiene.  
* 
*/ 
 
#define VALOR_MAX 5 
 
int main (){         
	int enteroSuma = 0;        
	int enteroNumero = 0;         
	int enteroContador = 0;         
	while (enteroContador < VALOR_MAX){                 
		printf("Ingrese un número:");                 
		scanf("%d", &enteroNumero);                 
		enteroSuma += enteroNumero;                 
		enteroContador++;                 
		if (enteroSuma > 50){                         
			printf("Se rebasó la cantidad límite.\n");                         
			break;                 
		}         
	}         
	printf("El valor de la suma es: %d\n", enteroSuma); 
 	return 0; 
 }