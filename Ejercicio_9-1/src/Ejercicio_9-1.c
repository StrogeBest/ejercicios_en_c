/*
 ============================================================================
 Name        : Ejercicio_9-1.c
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

#define LARGO 50

typedef struct{
	char nombre[LARGO]; // Campos
	int materiasAprobadas; // Campos
	int sumaDeNotas;
	float promedio;
}eAlumno;

eAlumno cargaDatos();
void mostrarDatos(eAlumno alumno);

int main(void) {
	setbuf(stdout, NULL);

	// int numero = 5; Variable simple
	// int numeros[10]; Variables compuestas

	eAlumno alumno;

	alumno = cargaDatos();
	mostrarDatos(alumno);

	return EXIT_SUCCESS;
}

eAlumno cargaDatos(){
	eAlumno alumno;

	int largoNombre;

	printf("Ingrese su nombre: ");
	fflush(stdin);
	fgets(alumno.nombre, LARGO, stdin);

	largoNombre = strlen(alumno.nombre);
	alumno.nombre[largoNombre - 1] = '\0';

	alumno.nombre[0] = toupper(alumno.nombre[0]);

	printf("Ingrese la cantidad de materias aprobadas: ");
	scanf("%d", &alumno.materiasAprobadas);

	printf("Ingrese la suma de notas: ");
	scanf("%d", &alumno.sumaDeNotas);

	return alumno;
}

void mostrarDatos(eAlumno alumno){
	int promedio = alumno.sumaDeNotas / alumno.materiasAprobadas;

	printf("Nombre: %s\n", alumno.nombre);
	printf("Materias aprobadas: %d\n", alumno.materiasAprobadas);
	printf("Promedio: %d\n", promedio);
}

void obtenerEnteroRango(){

}
