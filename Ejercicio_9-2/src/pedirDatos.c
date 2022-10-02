/*
 * pedirDatos.c
 *
 *  Created on: 30 sep. 2022
 *      Author: Javier
 */

#include "pedirDatos.h"
#include "validaciones.h"

int obtenerNumeroRango(char mensaje[], char mensajeError[], int minimo, int maximo){
	char numeroIngresado[50];
	int resultado;
	int numeroValidado;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do
		{
			printf("%s", mensaje);
			scanf("%s", numeroIngresado);

			resultado = validarNumero(numeroIngresado);

			if(!resultado){
				printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else{
				numeroValidado = atoi(numeroIngresado);

				if(numeroValidado < minimo || numeroValidado > maximo){
					printf("%s\n\n", mensajeError);
					system("pause");
				}
			}
		}
		while(!resultado || numeroValidado < minimo || numeroValidado > maximo);
	}

	return numeroValidado;
}

void obtenerCadena(char mensaje[], char mensajeError[], char nombre[], int largoNombre){
	int resultado;

	do
	{
		printf("%s", mensaje);
		fflush(stdin);
		fgets(nombre, largoNombre, stdin);
		nombre[strlen(nombre) - 1] = '\0';
		resultado = validarCadena(nombre);

		if(!resultado){
			printf("%s\n\n", mensajeError);
			system("pause");
		}
	}
	while(!resultado);
}

float obtenerFlotante(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int resultado;
	float numeroValidado;

	do
	{
		printf("%s", mensaje);
		scanf("%s", numeroIngresado);

		resultado = validarNumeroFlotante(numeroIngresado);

		if(!resultado){
			printf("%s\n\n", mensajeError);
			system("pause");
		}else{
			numeroValidado = atof(numeroIngresado);
		}
	}
	while(!resultado);

	return numeroValidado;
}

int obtenerNumeroPositivo(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int resultado;
	int numeroValidado;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do
		{
			printf("%s", mensaje);
			scanf("%s", numeroIngresado);

			resultado = validarNumero(numeroIngresado);

			if(!resultado){
				printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else{
				numeroValidado = atoi(numeroIngresado);

				if(numeroValidado < 0){
					printf("%s\n\n", mensajeError);
					system("pause");
				}
			}
		}
		while(!resultado);
	}

	return numeroValidado;
}
