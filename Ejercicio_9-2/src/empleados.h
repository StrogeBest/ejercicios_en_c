#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

#include "pedirDatos.h"
#include <string.h>

#define TAM 51
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

// struct auxiliar para buscar el mayor de todos - No usar SWITCH
typedef struct{
	int idSector;
	char descripcionSector[TAM];
	int isEmpty;
}eSector;

typedef struct{
	int idEmpleado;
	char name[TAM];
	char lastName[TAM];
	float salary;
	int idSector;
	int isEmpty;
}eEmpleado;

void inicializarEmpleados(eEmpleado empleados[], int cantidadEmpleados);
void crearNuevoEmpleado(eEmpleado empleados[], eSector sectores[] ,int tam, int id);
eEmpleado cargarDatos(eEmpleado empleados[], eSector sectores[]);
int validarId(eSector sectores[], int id);
int validarIdEmpleado(eEmpleado empleados[], int cantidadEmpleados, int id);
void actualizarEmpleadoPorId();
void eliminarEmpleadoPorId(eEmpleado empleados[], int cantidadEmpleados);
void mostrarEmpleado(eEmpleado empleado, eSector sector[], int tamSector);
void mostrarListaEmpleados(eEmpleado empleados[], eSector sectores[], int cantidadEmpleados, int tamSector);

#endif /* EMPLEADOS_H_ */
