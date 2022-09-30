/*
 * biblioteca.c
 *
 *  Created on: 8 sep. 2022
 *      Author: Javier
 */
#include <stdio.h>
#include <stdlib.h>

int suma(int numeroUno, int numeroDos, int* resultado){
	*resultado = numeroUno + numeroDos;

	return 1;
}

int pedirNumero(void){
	int numero;

	printf("Ingrese un numero: ");
	scanf("%d", &numero);

	return numero;
}
