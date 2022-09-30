/*
 * biblioteca.c
 *
 *  Created on: 8 sep. 2022
 *      Author: Javier
 */

#include <stdio.h>
#include <stdlib.h>

int obtenerOpcion(){
	int opcion;

	printf("\tMenu Principal\n\n1. Loguearse\n2. Comprar\n3. Ver mis compras\n4. Vender\n5. Salir\n\nIngrese una opcion: ");
	scanf("%d", &opcion);

	while(opcion < 1 || opcion > 5){
		system("cls");
		printf("\tMenu Principal\n\n1. Loguearse\n2. Comprar\n3. Ver mis compras\n4. Vender\n5. Salir\n\nERROR. Ingrese una opcion: ");
		scanf("%d", &opcion);
	}

	return opcion;
}

char salir(){
	char salir;

	printf("\nEsta seguro que desea salir? S/N: ");
	fflush(stdin);
	scanf("%c", &salir);
	while(salir != 's' && salir != 'n' && salir != 'S' && salir != 'N'){
		printf("\nERROR. Esta seguro que desea salir? S/N: ");
		fflush(stdin);
		scanf("%c", &salir);
	}

	return salir;
}
