/*
 ============================================================================
 Name        : Ejercicio_9-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "pedirDatos.h"

#define TAM 51
#define CANTIDAD_EMPLEADOS 5
#define CANTIDAD_SECTORES 5
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

// struct auxiliar para buscar el mayor de todos - No usar SWITCH
// Una bilioteca por cada estructura
// struct: Siempre Id y estado
typedef struct{
	int idSector;
	char descripcionSector[TAM];
	int isEmpty;
}eSector;

typedef struct{
	int id;
	char name[TAM];
	char lastName[TAM];
	float salary;
	int idSector;
	int isEmpty;
}eEmpleado;

void inicializarEmpleados(eEmpleado empleados, int cantidadEmpleados);
void crearNuevoEmpleado(eEmpleado empleados, int tam);

int main(void) {
	setbuf(stdout, NULL);

	// Creo array de estructura
	eEmpleado empleados[CANTIDAD_EMPLEADOS];
	int opcion;

	// Inicializo array de estructura
	inicializar(empleados, CANTIDAD_EMPLEADOS);

	do{
			system("cls");
			printf("\tMenu Principal\n\n1. Nuevo empleado\n2. Actualizar empleado\n3. Eliminar empleado\n4. Lista de empleados\n5. Salir\n\n");
			opcion = obtenerNumeroRango("Ingrese una opcion: ", "El numero debe estar entre 1 y 5. Intentelo de nuevo", 1, 5);

			switch(opcion){
				case 1:
					crearNuevoEmpleado(empleados, CANTIDAD_EMPLEADOS);
					break;
				case 2:
					system("cls");
					printf("\tActualizar empleado\n\n");
					break;
				case 3:
					system("cls");
					printf("\tEliminar empleado\n\n");
					break;
				case 4:
					system("cls");
					printf("\tLista de empleados\n\n");
					break;
			}
		}while(opcion != 5);

	return EXIT_SUCCESS;
}

void inicializarEmpleados(eEmpleado empleados, int cantidadEmpleados){
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (empleados != NULL && cantidadEmpleados > 0) {
		//RECORRO TODO EL ARRAY
		for (int i = 0; i < cantidadEmpleados; i++) {
			//SET ESTADO DE "LIBRE"
			empleados[i].isEmpty = LIBRE;
		}
	}
}

void crearNuevoEmpleado(eEmpleado empleados, int tam){
	// break Rompe el for mas cercano
	//printf("%20s"); https://parzibyte.me/blog/2020/04/12/rellenar-alinear-texto-printf/
	eEmpleado empleado;
	//int error;

	system("cls");
	printf("\tCrear nuevo empleado\n\n");


	printf("Se ha creado un nuevo empleado correctamente\n\n");
	system("pause");
}

eEmpleado cargarDatos(void){
	eEmpleado empleado;

	obtenerCadena("Ingrese el nombre: ", "El nombre solo puede tener letras. Intentelo de nuevo", empleado.name, TAM);
	obtenerCadena("Ingrese el apellido: ", "El apellido solo puede tener letras. Intentelo de nuevo", empleado.name, TAM);
	empleado.salary = obtenerFlotante("Ingrese el salario: ", "El salario ingresado es incorrecto. Intentelo de nuevo");
	empleado.idSector = obtenerNumeroPositivo("Ingrese el ID del sector: ", "El ID del sector es incorrecto. Intentelo de nuevo");
	validarId(empleado.idSector);

	return empleado;
}
