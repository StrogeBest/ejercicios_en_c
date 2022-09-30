/*
 ============================================================================
 Name        : Ejercicio_4-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);

	int resultado;
	int numeroUno;
	int numeroDos;

	numeroUno = pedirNumero();
	numeroDos = pedirNumero();

	suma(numeroUno, numeroDos, &resultado);

	printf("El resultado es: %d", resultado);

	return 0;
}
