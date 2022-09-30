/*
 * biblioteca.c
 *
 *  Created on: 8 sep. 2022
 *      Author: Javier
 */
#include <stdio.h>
#include <stdlib.h>

int conversionTemperaturas(int grados, char temperatura, int* resultado){
	int retorno;

	switch(temperatura){
		case 'f':
		case 'F':
			*resultado = (grados - 32) * 5/9;
			retorno = 1;
			break;
		case 'c':
		case 'C':
			*resultado = (grados * 9/5) + 32;
			retorno = 1;
			break;
		default:
			retorno = 0;
			break;
	}

	return retorno;
}

int validacionTemperatura(void){
	int temperatura;

	printf("Ingrese los grados: ");
	scanf("%d", &temperatura);
	while(temperatura < 0 || temperatura > 100){
		printf("ERROR. Ingrese los grados: ");
		scanf("%d", &temperatura);
	}

	return temperatura;
}
