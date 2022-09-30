/*
 ============================================================================
 Name        : Ejercicio_4-4.c
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

	int opcion;
	char opcionSalir;
	int banderaInicio = 0;
	int banderaCompras = 0;

	do
	{
		system("cls");
		opcion = obtenerOpcion();

		if(opcion == 5){
			opcionSalir = salir();
		}

		switch(opcion){
			case 1:
				system("cls");
				if(!banderaInicio){
					printf("Iniciando sesion...\n");
					banderaInicio = 1;
				}else{
					printf("Ya se ha iniciado sesion\n");
				}
				system("pause");
				break;
			case 2:
				system("cls");
				if(!banderaInicio){
					printf("No se ha iniciado sesion\n");
				}else{
					printf("Procesando\n");
				}
				system("pause");
				break;
			case 3:
				system("cls");
				if(!banderaInicio){
					printf("No se ha iniciado sesion\n");
				}else{
					if(!banderaCompras){
						printf("No se ha realizado ninguna compra\n");
					}
				}
				system("pause");
				break;
		}
	}
	while(!(opcion == 5 && (opcionSalir == 's' || opcionSalir == 'S')));

	return EXIT_SUCCESS;
}
