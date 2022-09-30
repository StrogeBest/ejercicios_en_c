/*
 ============================================================================
 Name        : Ejercicio_10-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int idProveedor; // Clave primaria
	char razonSocial[50];
}eProveedor;

typedef struct{
	int idProducto; // Clave primaria
	char descripcion[50];
	float precio;
	int idProveedor; // Clave foranea
}eProducto;

int isNumber(char numero[]);

int main(void) {
	setbuf(stdout, NULL);

	char numero[] = "-100";
	int resultado;

	resultado = isNumber(numero);

	if(resultado){
		printf("Es un numero");
	}

	return EXIT_SUCCESS;
}

int validarNumero(char numero[]){
	int retorno = 1;

	if(numero[0] == '-'){
		for(int i = 1; i < strlen(numero); i++){
			if(!isdigit(numero[i])){
				retorno = 0;
				break;
			}
		}
	}else{
		for(int i = 1; i < strlen(numero); i++){
			if(!isdigit(numero[i])){
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

void obtenerNumeroFlotante(){
	char numero[50];
}

void obtenerNumeroPositivo(char mensaje[]){
	char numero[50];

	printf("%s", mensaje);

}

void obtenerNumeroNegativo(){

}

void obtenerNumero(){

}

void obtenerCadena(){

}
