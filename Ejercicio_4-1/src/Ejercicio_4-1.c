/*
Realizar un programa en el MAIN que permita calcular y mostrar el factorial de
un número. Utilizar la función de PedirNumero de la ejercitación 3. Por ejemplo:
5! = 5*4*3*2*1 = 120
*/

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void) {
	setbuf(stdout ,NULL);

	int numeroIngresado;
	int resultado;

	numeroIngresado = pedirNumero();
	resultado = factorial(numeroIngresado);

	printf("El factorial de %d es: %d", numeroIngresado, resultado);

	return 0;
}
