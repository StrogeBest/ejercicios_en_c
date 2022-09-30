/*
 ============================================================================
 Name        : Ejercicio_9-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "biblioteca.h"
#include <string.h>

#define TAM 51
#define CANTIDAD_EMPLEADOS 5
#define CANTIDAD_SECTORES 5
#define LIBRE 0 // Para el isEmpty
#define OCUPADO 1 // Para el isEmpty
#define BAJA -1 // Para el isEmpty

typedef struct{
	int idSector;
	char descripcionSector[TAM];
	int isEmpty;
}eSector;

typedef struct{
	int id; // Desbordamiento de enteros
	char name[TAM]; // Desbordamiento de caracteres
	char lastName[TAM];
	float salary;
	int idSector;
	int isEmpty;
}eEmpleado;

eEmpleado crearNuevoEmpleado(int idEmpleado); // eEmpleado tipo de dato al igual como int, void, float, char
void actualizarEmpleadoPorId(eEmpleado empleados[]); // Aritmetica de punteros
int validarIdEmpleado(eEmpleado empleados[], int idEmpleado);
void mostrarEmpleados(eEmpleado empleados[], int idEmpleado);
int agregarEspaciados(char mensaje[], int cantidadEspacio, char mensajee[]);

int main(void) {
	setbuf(stdout, NULL);

	eEmpleado empleados[CANTIDAD_EMPLEADOS], empleado;
	// Datos hardcodeados
	eSector sectores[CANTIDAD_SECTORES] = {
			{100, "Sistemas"},
			{200, "Recursos Humanos"},
			{300, "Administracion"},
			{400, "Gerencia"}
	};
	int opcion, resultado, idEmpleado = 0;

	// Poner 0 a todos los empleados en el isEmpty
	inicializarEmpleados();

	do{
		system("cls");
		mostrarMenu("\tMenu Principal\n\n1. Nuevo empleado\n2. Actualizar empleado\n3. Eliminar empleado\n4. Lista de empleados\n5. Salir\n\n");
		opcion = obtenerEnteroRango("Ingrese una opcion: ", 1, 5);

		/*
		 * Muestra el menu dependiendo de la opcion elegida
		 */
		if(resultado){
			switch(opcion){
				case 1:
					system("cls");
					printf("\tCrear nuevo empleado\n\n");
					// retorno de la funcion para saber si salio bien(1) o mal(0)
					empleado = crearNuevoEmpleado(idEmpleado);
					empleados[idEmpleado] = empleado;
					idEmpleado++; // Bien
					break;
				case 2:
					system("cls");
					printf("\tActualizar empleado\n\n");
					actualizarEmpleadoPorId(empleados);
					break;
				case 3:
					system("cls");
					printf("\tEliminar empleado\n\n");
					// No se borran los datos solo cambia el estado - Baja logica
					actualizarEmpleadoPorId(empleados);
					break;
				case 4:
					system("cls");
					printf("\tLista de empleados\n\n");
					mostrarEmpleados(empleados, idEmpleado);
					break;
			}
		}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}

// Lista, max lista, id
eEmpleado crearNuevoEmpleado(int idEmpleado){
	eEmpleado empleado;

	empleado.id = idEmpleado;

	pedirCadena("Ingrese su nombre", empleado.name, TAM);

	printf("Ingrese su apellido: ");
	scanf("%s", empleado.lastName);

	printf("Ingrese su salario: ");
	scanf("%f", &empleado.salary);

	printf("Ingrese su sector: ");
	scanf("%d", &empleado.idSector);

	empleado.isEmpty = 1;

	return empleado;
}

void actualizarEmpleadoPorId(eEmpleado empleados[]){
	int idEmpleado;
	int resultado;
	int opcion;

	printf("Ingrese el ID del empleado: ");
	scanf("%d", &idEmpleado);

	resultado = validarIdEmpleado(empleados, idEmpleado);

	if(resultado){
		do{
			system("cls");
			printf("\tActualizar empleado con ID %d\n\n", idEmpleado);
			printf("1. Nombre\n");
			printf("2. Apellido\n");
			printf("3. Salario\n");
			printf("4. Sector\n");
			printf("5. Salir\n\n");

			resultado = obtenerNumero(&opcion, "Ingrese una opcion: ");

			if(resultado){
				switch(opcion){
					case 1:
						printf("Ingrese su nombre: \n\n");
						break;
					case 2:
						printf("Ingrese su apellido: \n\n");
						break;
					case 3:
						printf("Ingrese su salario: \n\n");
						break;
					case 4:
						printf("Ingrese su sector: \n\n");
						break;
				}
				system("pause");
			}
		}while(opcion != 5);
	}else{
		printf("El empleado con ID %d no existe. Intentelo de nuevo\n\n", idEmpleado);
		system("pause");
	}
}

int validarIdEmpleado(eEmpleado empleados[], int idEmpleado){
	int retorno = 0;

	for(int i = 0; i < CANTIDAD_EMPLEADOS; i++){
		if(empleados[i].id == idEmpleado){
			retorno = 1;
			break;
		}
	}

	return retorno;
}

void mostrarEmpleados(eEmpleado empleados[], int idEmpleado){
	char nombre[19];
	//char numero[3];
	//char numeroCaracter[4];

	printf("+-----+--------------------+\n");
	printf("| ID  | Nombre             |\n");
	printf("+-----+--------------------+\n");
	for(int i = 0; i < idEmpleado; i++){
		agregarEspaciados(empleados[i].name, 19, nombre);
		/*
		itoa(empleados[i].id, numero, 10);
		agregarEspaciados(numero, 4, numeroCaracter);
		*/

		printf("| 100 | %s|\n", nombre);
	}
	printf("+-----+--------------------+\n\n");
	system("pause");
}

int agregarEspaciados(char mensaje[], int cantidadEspacio, char mensajee[]){
	int retorno = 0;
	char textoConEspacios[cantidadEspacio];
	int cantidad = strlen(mensaje);

	for(int i = 0; i < cantidadEspacio; i++){
		if(i < cantidad){
			textoConEspacios[i] = mensaje[i];
		}else{
			textoConEspacios[i] = ' ';
		}
	}

	strcpy(mensajee, textoConEspacios);

	return retorno;
}
