#include "pedirDatos.h"
#include "empleados.h"

#define CANTIDAD_EMPLEADOS 5
#define CANTIDAD_SECTORES 5

int main(void) {
	setbuf(stdout, NULL);

	eEmpleado empleados[CANTIDAD_EMPLEADOS];
	eSector sectores[CANTIDAD_SECTORES] = {
			{100, "Sistemas", 1},
			{200, "Recursos Humanos", 1},
			{300, "Administracion", 1},
			{400, "Gerencia", 1}
	};

	int opcion;
	int idEmpleado = 0;

	inicializarEmpleados(empleados, CANTIDAD_EMPLEADOS);

	do{
			system("cls");
			printf("+==================================+\n");
			printf("¦          Menu Principal          ¦\n");
			printf("+==================================+\n");
			printf("¦                                  ¦\n");
			printf("¦   1. Nuevo empleado              ¦\n");
			printf("¦   2. Actualizar empleado         ¦\n");
			printf("¦   3. Eliminar empleado           ¦\n");
			printf("¦   4. Lista de empleados          ¦\n");
			printf("¦   5. Salir                       ¦\n");
			printf("¦                                  ¦\n");
			opcion = obtenerNumeroRango("¦   Ingrese una opcion: ", "El numero debe estar entre 1 y 5. Intentelo de nuevo", 1, 5);

			switch(opcion){
				case 1:
					crearNuevoEmpleado(empleados, sectores, CANTIDAD_EMPLEADOS, idEmpleado);
					idEmpleado++;
					break;
				case 2:
					//actualizarEmpleadoPorId();
					break;
				case 3:
					eliminarEmpleadoPorId(empleados, CANTIDAD_EMPLEADOS);
					break;
				case 4:
					mostrarListaEmpleados(empleados, sectores, CANTIDAD_EMPLEADOS, CANTIDAD_SECTORES);
					break;
			}
		}while(opcion != 5);

	return EXIT_SUCCESS;
}
