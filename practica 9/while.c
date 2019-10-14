#include <stdio.h> 
 
/*     Este programa genera la tabla de multiplicar de un número dado. 
       El número se lee desde la entrada estándar (teclado). */ 
 
int main(){ 
    int num, cont = 0; 
    printf("\a----- Tabla de multiplicar -----\n");     
    printf("Ingrese un número: \n");     scanf("%d", &num);           
    printf("La tabla de multiplicar del %d es:\n", num);     
    while (++cont <= 10)         
    	printf("%d x %d = %d\n", num, cont, num*cont);

    return 0; } 