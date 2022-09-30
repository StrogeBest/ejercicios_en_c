/*
Realizar funciones para validar y obtener:
	Alfanumericos, ej. ab555gT6
	Teléfonos, ej. 4XXX-XXXX
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INGRESO 9

int validarTelefono(char vector[]);
int validarAlfanumericos(char vector[]);

int main(void) {
	setbuf(stdout, NULL);

	char telefono[INGRESO];
	int error;

	printf("Ingrese el numero de telefono: ");
	fflush(stdin); // Siempre limpiar cuando sea un caracter o una cadena string
	scanf("%s", telefono);

	/*
	fgets(telefono, INGRESO, stdin);
	largoTelefono = strlen(telefono);
	telefono[largoTelefono - 1] = '\0';
	*/

	error = validarTelefono(telefono);

	if(!error){
		printf("El numero ingresado es incorrecto. Intentelo de nuevo");
	}else{
		printf("Telefono: %s", telefono);
	}

	return EXIT_SUCCESS;
}

int validarTelefono(char vector[]){
	int retorno = 1;

	for(int i = 0; i < 8; i++){
		if(!(isdigit(vector[i]))){
			retorno =  0;
			break;
		}
	}

	return retorno;
}

int formatearTelefono(char telefono[]){

	for(int i = 0; i < 8; i++){
		if(i == 3){
			printf("%c-", telefono[i]);
		}else{
			printf("%c", telefono[i]);
		}
	}

	return 1;
}

int validarAlfanumericos(char vector[]){
	return 1;
}
