/*
 ============================================================================
 Name        : Ejercicio_4-3.c
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

	int temperatura = validacionTemperatura();
	int resultadoTemperatura;
	int resultado;

	resultado = conversionTemperaturas(temperatura, 'd', &resultadoTemperatura);

	if(resultado){
		printf("El resultado es: %d", resultadoTemperatura);
	}else{
		printf("Ha ocurrido un error");
	}

	return 0;
}
