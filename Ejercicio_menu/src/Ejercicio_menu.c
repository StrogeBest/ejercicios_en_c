/*
 ============================================================================
 Name        : Ejercicio_menu.c
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
	int banderaProceso = 0;

	do
	{
		system("cls");
		opcion = obtenerOpcion();

		if(opcion == 4){
			opcionSalir = salir();
		}

		switch(opcion){
			case 1:
				system("cls");
				if(!banderaInicio){
					printf("Iniciar\n");
					banderaInicio = 1;
				}else{
					printf("Ya se ha iniciado\n");
				}
				system("pause");
				break;
			case 2:
				system("cls");
				if(!banderaInicio){
					printf("Debe Iniciar antes de Procesar\n");
				}else{
					printf("Procesando\n");
				}
				system("pause");
				break;
			case 3:
				system("cls");
				if(!banderaInicio){
					printf("Debe Iniciar antes de Finalizar\n");
				}else{
					if(!banderaProceso){
						printf("Debe Procesar antes de Finalizar\n");
					}else{
						printf("Finalizar\n");
					}
				}
				system("pause");
				break;
		}
	}
	while(!(opcion == 4 && (opcionSalir == 's' || opcionSalir == 'S')));

	return EXIT_SUCCESS;
}
