/*
 ============================================================================
 Name        : Ejercicio_7-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INGRESO 10

void FormarApellidoNombre(char* pNombre,char* pApellido,char* pCompleto);

int main(void) {
	setbuf(stdout, NULL);

	char nombre[INGRESO];
	char apellido[50];
	char nombreCompleto[50];
	int largoNombre;

	printf("Ingrese su nombre: ");
	fgets(nombre, INGRESO, stdin);
	largoNombre = strlen(nombre);
	nombre[largoNombre - 1] = '\0';

	printf("Ingrese su apellido: ");
	scanf("%s", apellido);

	FormarApellidoNombre(nombre, apellido, nombreCompleto);

	printf("Nombre completo: %s", nombreCompleto);

	return EXIT_SUCCESS;
}

void FormarApellidoNombre(char* pNombre,char* pApellido,char* pCompleto){
	strcat(pCompleto, pNombre);
	strcat(pCompleto, " ");
	strcat(pCompleto, pApellido);
}
