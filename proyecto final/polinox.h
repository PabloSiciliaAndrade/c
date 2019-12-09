#ifndef POLINOX_H
#define POLINOX_H
//Empezamos definiendo las estructuras con un define POLINOX.H

typedef struct monomios monomio;
struct monomios {
	float coeficiente;
	int exponente;
	monomio *siguiente;
};
//Comentario sobre la estructura monomio: Usamos un decimal para definir el coeficiente, un entero para el exponente 
//y un valor monomio tipo apuntador que almacena el siguiente monomio a introducir.

typedef struct polinomios {
	monomio *Monomio_menor;
	int cantidad_de_monomios;
	int potencia;
}Polinomio;
//Comentario sobre la estructura Polinomio: Usamos una variable monomio tipo apuntador llamada monomio menor que guarda el monomio de menor grado.
//Y dos variables tipo entero para definir la cantidad de monomios y su potencia, usadas en las posteriores funciones.

void definir_polinomio_nuevo(Polinomio *polinomio);
void reservar_memoria(Polinomio *polinomio);
void leer_polinomio(Polinomio *polinomio);
void leer_monomio_mayor(Polinomio *polinomio1);
void imprimir_monomio(monomio *monomio);
void imprimir_polinomio(Polinomio *polinomio);
void leer_monomio(monomio *monomio1);
void freeMemory(Polinomio *polinomio);
void ordenar(Polinomio *polinomio);
void sumar_polinomios(Polinomio *polinomio1, Polinomio *polinomio2, Polinomio *PolinomioR);
void sumar_monomios(monomio *monomio1, monomio * monomio2, monomio *monomioR);
void restar_polinomios(Polinomio *polinomio1, Polinomio *polinomio2, Polinomio *PolinomioR);
void restar_monomios(monomio *monomio1, monomio * monomio2, monomio *monomioR);
void multiplicar_polinomios(Polinomio *polinomio1, Polinomio *polinomio2, Polinomio *PolinomioR);
void multiplicar_monomios(monomio *monomio1, monomio * monomio2, monomio *monomioR);
void dividir_monomios(monomio *monomio1, monomio * monomio2, monomio *monomioR);
void dividir_polinomios_entre_monomio(Polinomio *polinomio1, monomio *monomio1, Polinomio *PolinomioR);
void dividir_polinomio_entre_binomio();
void lectura_de_archivo();
#endif
//Prototipos de las funciones.