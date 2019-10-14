#include <stdio.h> 
#define MAX 5 
 
/*  
*      Este programa define un valor por defecto para el tamaño del arreglo  
*      de tal manera que si el tamaño de éste cambia, solo se debe modificar  
*      el valor de la constante MAX.  
*      
*/ 
 
int main () { 
        int arreglo[MAX], cont; 
        for (cont=0; cont<MAX; cont++){                 
        	printf("Ingrese el valor %d del arreglo: ", cont+1);                 
        	scanf("%i", &arreglo[cont]);         
        } 
 
        printf("El valor ingresado para cada elemento del arreglo es:\n[");         
        for (cont=0; cont<MAX; cont++){                 
        	printf("%d\t", arreglo[cont]); 
        }         
        printf("]\n");         
        return 0; 
    } 