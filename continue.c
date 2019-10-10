#include <stdio.h>
 /*  
 * Este programa obtiene la suma de un LIMITE de números pares ingresados  
 * 
 */ 
 
#define LIMITE 5 
 
int main (){ 
    int enteroContador = 1; 
    int enteroNumero = 0;         
    int enteroSuma = 0;         
    while (enteroContador <= LIMITE){                 
    	printf("Ingrese número par %d:", enteroContador);                 
     	scanf("%d",&enteroNumero); 
 
            if (enteroNumero%2 != 0){                         
            	printf("El número insertado no es par.\n");                         
            	continue;                 
            } 
 
        enteroSuma += enteroNumero;                 
        enteroContador++;         
    }

    printf("La suma de los números es: %d\n", enteroSuma); 
 	return 0; 
}
