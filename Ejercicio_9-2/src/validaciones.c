/*
 * validaciones.c
 *
 *  Created on: 30 sep. 2022
 *      Author: Javier
 */

#include "validaciones.h"

int validarNumero(char cadena[]){
	int retorno = 1;
	int resultadoNumeroNegativo;
	int resultadoNumeroPositivo;

	resultadoNumeroNegativo = validarNumeroNegativo(cadena);
	resultadoNumeroPositivo = validarNumeroPositivo(cadena);

	if(!resultadoNumeroNegativo || !resultadoNumeroPositivo){
		retorno = 0;
	}

	return retorno;
}

int validarNumeroNegativo(char cadena[]){
	int retorno = 1;

	if(cadena[0] == '-'){
		for(int i = 1; i < strlen(cadena); i++){
			if(!isdigit(cadena[i])){
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int validarNumeroPositivo(char cadena[]){
	int retorno = 1;

	for(int i = 0; i < strlen(cadena); i++){
		if(!isdigit(cadena[i])){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int validarNumeroFlotante(char buffer[]){
	int retorno = 1;
	int a;

	for(int i = 0; i < strlen(buffer); i++){
		/* Despues del punto los caracteres deberan ser numero
		01234
		50.00
		*/
		if(isdigit(buffer[i])){
			if(buffer[i + 1] == '.'){
				a = i + 2;
				for(int j = a; j < strlen(buffer); j++){
					if(!isdigit(buffer[a])){
						retorno = 0;
						break;
					}
				}
			}
		}else{
			if(!isdigit(buffer[i])){
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int validarCadena(char mensaje[]){
	int retorno = 1;

	for(int i = 1; i < strlen(mensaje); i++){
		if(isalpha(mensaje[i]) == 0){
			retorno = 0;
			break;
		}
	}

	return retorno;
}
