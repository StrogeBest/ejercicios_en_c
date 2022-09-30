/*
 * biblioteca.c
 *
 *  Created on: 22 sep. 2022
 *      Author: Javier
 */
#include "biblioteca.h"

int validarNumero(char numero[]){
	int retorno = 1;

	// Numero negativo
	if(numero[0] == '-'){
		for(int i = 1; i < strlen(numero); i++){
			if(!isdigit(numero[i])){
				retorno = 0;
			}
		}
	}else{
		// Numero positivo
		for(int i = 0; i < strlen(numero); i++){
			if(!isdigit(numero[i])){
				retorno = 0;
			}
		}
	}

	return retorno;
}

int obtenerNumero(int* pResultado, char mensaje[]){
	int retorno = 0;
	char numeroIngresado[50];
	int resultado;
	int numeroValidado;

	if(pResultado != NULL){
		printf("%s", mensaje);
		scanf("%s", numeroIngresado);

		resultado = validarNumero(numeroIngresado);

		if(resultado){
			numeroValidado = atoi(numeroIngresado);
			*pResultado = numeroValidado;

			retorno = 1;
		}else{
			printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
			system("pause");
		}
	}

	return retorno;
}

int obtenerNumeroPositivo(int* pResultado, char mensaje[], char mensajeError[]){
	int retorno = 0;
	char numeroIngresado[50];
	int resultado;
	int numeroValidado;

	if(pResultado != NULL){
		printf("%s", mensaje);
		scanf("%s", numeroIngresado);

		resultado = validarNumero(numeroIngresado);

		if(resultado){
			numeroValidado = atoi(numeroIngresado);

			if(numeroValidado > 0){
				*pResultado = numeroValidado;

				retorno = 1;
			}else{
				printf("%s\n\n", mensajeError);
				system("pause");
			}
		}else{
			printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
			system("pause");
		}
	}

	return retorno;
}

int obtenerNumeroNegativo(int* pResultado, char mensaje[], char mensajeError[]){
	int retorno = 0;
	char numeroIngresado[50];
	int resultado;
	int numeroValidado;

	if(pResultado != NULL){
		printf("%s", mensaje);
		scanf("%s", numeroIngresado);

		resultado = validarNumero(numeroIngresado);

		if(resultado){
			numeroValidado = atoi(numeroIngresado);

			if(numeroValidado < 0){
				*pResultado = numeroValidado;

				retorno = 1;
			}else{
				printf("%s\n\n", mensajeError);
				system("pause");
			}
		}else{
			printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
			system("pause");
		}
	}

	return retorno;
}

int validarRangoNumero(int numero, int minimo, int maximo, char mensajeError[]){
	int retorno = 1;

	if(numero < minimo || numero > maximo){
		printf("%s\n\n", mensajeError);
		system("pause");

		retorno = 0;
	}

	return retorno;
}

int obtenerEnteroRango(int* pResultado, char mensaje, ,char mensajeError, int minimo, int maximo){
	int retorno = 0;
	char numeroIngresado[50];
	int resultado;
	int numeroValidado;

	printf("%s", mensaje);
	scanf("%s", numeroIngresado);

	resultado = validarNumero(numeroIngresado);

	if(resultado){
		numeroValidado = atoi(numeroIngresado);

		if(numeroValidado < minimo || numeroValidado > maximo){
			printf("El numero supero el rango\n\n");
			system("pause");
		}else{
			*pResultado = numeroValidado;
		}
	}else{
		printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
		system("pause");
	}

	return retorno;
}

int obtenerCadena(){
	int retorno = 0;



	return retorno;
}
