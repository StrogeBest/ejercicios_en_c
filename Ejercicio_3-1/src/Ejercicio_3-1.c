/*
Crear una función que muestre por pantalla el número entero que recibe como parámetro.
*/

#include <stdio.h>
#include <stdlib.h>

// Prototipo, declaracion o firma
void mostrarNumero(int numero); // Parametros formales

int main(void) {
	setbuf(stdout,NULL);

	mostrarNumero(50); // Llamada o invocacion | parametros reales, actuales, verdaderos

	return 0;
}

void mostrarNumero(int numero){ // Desarrollo de la funcion | Paramatros formales
	printf("Numero: %d", numero);
}
