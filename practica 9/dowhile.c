#include <stdio.h> 
/*     Este programa obtiene el promedio de calificaciones ingresadas por el usuario.
 Las calificaciones se leen desde la entrada estándar (teclado).
  La inserción de calificaciones termina cuando el usuario presiona
   una tecla  diferente de ‘S’ o ‘s’. */
int main () {     
	char op = 'n';     
	double sum = 0, calif = 0; 
    int veces = 0; 
    do {         
    	printf("\tSuma de calificaciones\n");         
    	printf("Ingrese la calificación:\n");         
    	scanf("%lf", &calif);         
    	veces++;         
    	sum = sum + calif;                   
    	printf("¿Desea sumar otra? S/N\n");         
    	setbuf(stdin, NULL);       
    	 // limpia el buffer del teclado         
    	scanf("%c",&op);        
    	getchar();     
    } while (op == 'S' || op == 's');          
     printf("El promedio de las calificaciones ingresadas es: %lf\n", sum/veces);