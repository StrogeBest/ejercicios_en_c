#include "empleados.h"

static int obtenerId(void);
static int obtenerId(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eGen_ObtenerID();
	static int idIncrementable = 0;
	return idIncrementable++;
}

void inicializarEmpleados(eEmpleado empleados[], int cantidadEmpleados){
	/* Si existe el arreglo y el limite es valido */
	if (empleados != NULL && cantidadEmpleados > 0) {
		/* Recorro todo el arreglo */
		for (int i = 0; i < cantidadEmpleados; i++) {
			/* Pongo el estado en LIBRE */
			empleados[i].isEmpty = LIBRE;
		}
	}
}

void crearNuevoEmpleado(eEmpleado empleados[], eSector sectores[] ,int tam, int id){
	eEmpleado empleado;

	system("cls");
	/* Titulo del menu */
	printf("\tCrear nuevo empleado\n\n");

	/* Pido los datos y lo guardo el la struct empleado */
	empleado = cargarDatos(empleados, sectores);
	/* ID del empleado incrementable */
	empleado.idEmpleado = id;
	/* Cambio el estado a OCUPADO */
	empleado.isEmpty = OCUPADO;

	/* Guardo el empleado en el arreglo de empleados */
	empleados[id] = empleado;
}

eEmpleado cargarDatos(eEmpleado empleados[], eSector sectores[]){
	eEmpleado empleado;

	int resultado;

	obtenerCadena("Ingrese el nombre: ", "El nombre solo puede tener letras. Intentelo de nuevo", empleado.name, TAM);
	obtenerCadena("Ingrese el apellido: ", "El apellido solo puede tener letras. Intentelo de nuevo", empleado.lastName, TAM);
	empleado.salary = obtenerFlotantePositivo("Ingrese el salario: ", "El salario ingresado es incorrecto. Intentelo de nuevo");
	do
	{
		empleado.idSector = obtenerNumeroPositivo("Ingrese el ID del sector: ", "El ID del sector es incorrecto. Intentelo de nuevo");
		/* Me devuelve un 0 si el id no existe */
		resultado = validarId(sectores, empleado.idSector);

		if(!resultado){
			printf("El ID ingresado no existe. Intentelo de nuevo\n\n");
			system("pause");
		}
	}
	while(!resultado);

	return empleado;
}

int validarId(eSector sectores[], int id){
	int retorno = 0;

	if(sectores != NULL){
		for(int i = 0; i < 10; i++){
			if(sectores[i].idSector == id){
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int validarIdEmpleado(eEmpleado empleados[], int cantidadEmpleados, int id){
	int retorno = 0;

	if(empleados != NULL){
		for(int i = 0; i < cantidadEmpleados; i++){
			if(empleados[i].idEmpleado == id){
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

void actualizarEmpleadoPorId(){
	// eEmpleado empleado;

	printf("\tActualizar empleado\n\n");

	printf("Ingrese el ID del empleado: ");
}

void eliminarEmpleadoPorId(eEmpleado empleados[], int cantidadEmpleados){
	system("cls");
	printf("\tEliminar empleado\n\n");

	int id = obtenerNumeroPositivo("Ingrese el ID del empleado: ", "El ID del empleado es incorrecto. Intentelo de nuevo");
	int resultado = validarIdEmpleado(empleados, cantidadEmpleados, id);

	if(resultado){
		validarSalir("Esta seguro de borrar al empleado? S/N: ", "Ingrese una letra valida");
		for(int i = 0; i < cantidadEmpleados; i++){
			if(empleados[i].idEmpleado == id){
				empleados[i].isEmpty = BAJA;
				break;
			}
		}
	}
}

void mostrarEmpleado(eEmpleado empleado, eSector sector[], int tamSector){
	char nombreSector[50];

	/* Recorro todo el arreglo de sector */
	for(int i = 0; i < tamSector; i++){
		/* Si el ID de sector del empleado coincide con el ID del sector entonces lo que tenga la descripcionSector lo pongo en la variable nombreSector */
		if(empleado.idSector == sector[i].idSector){
			strcpy(nombreSector, sector[i].descripcionSector);
			break;
		}
	}

	printf("| %-4d| %-25s| %-25s| %-20.2f| %-25s|\n", empleado.idEmpleado, empleado.name, empleado.lastName, empleado.salary, nombreSector);
}

void mostrarListaEmpleados(eEmpleado empleados[], eSector sectores[], int cantidadEmpleados, int tamSector){
	system("cls");

	printf("\t\tLista de empleados\n\n");

	printf("+-----+--------------------------+--------------------------+---------------------+--------------------------+\n");
	printf("| ID  | Nombre                   | Apellido                 | Salario             | Sector                   |\n");
	printf("+-----+--------------------------+--------------------------+---------------------+--------------------------+\n");
	for(int i = 0; i < cantidadEmpleados; i++){
		if(empleados[i].isEmpty == OCUPADO){
			mostrarEmpleado(empleados[i], sectores, tamSector);
		}
	}
	printf("+-----+--------------------------+--------------------------+---------------------+--------------------------+\n");

	system("pause");
}
