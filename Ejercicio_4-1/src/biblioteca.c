/*
 * biblioteca.c
 *
 *  Created on: 7 sep. 2022
 *      Author: Javier
 */

#include <stdio.h>
#include <stdlib.h>

int pedirNumero(void){
	int numero;

	printf("Ingrese un numero: ");
	scanf("%d", &numero);

	return numero;
}

int factorial(int numero){
	int resultado = 1;

	for(int i = numero; i > 0; i--){
		resultado *= i;
	}

	return resultado;
}
