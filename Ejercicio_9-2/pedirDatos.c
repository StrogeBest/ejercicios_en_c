#include "pedirDatos.h"

/* -----------------------------------VALIDACIONES----------------------------------- */
int validarNumero(char cadena[], int valorInicial){
	int retorno = 1;

	for(int i = valorInicial; i < strlen(cadena); i++){
		if(!isdigit(cadena[i])){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int validarNumeroFlotante(char cadena[]){
	int retorno = 1;

	if(cadena != NULL && strlen(cadena) > 0){
		for(int i = 0; i < strlen(cadena); i++){
			/* Si encuentro un punto entonces valido los decimales */
			if(cadena[i] == '.'){
				/* Verifico que el siguiente valor despues del punto sea menor al tamaño de la cadena */
				if(i + 1 < strlen(cadena)){
					/* Despues del punto recorro los decimales */
					if(!validarNumero(cadena, i + 1)){
						retorno = 0;
						break;
					}
				}else{
					retorno = 0;
					break;
				}
			}else{
				/* Si no es un numero rompe la validacion y el numero no es valido */
				if(!isdigit(cadena[i])){
					retorno = 0;
					break;
				}
			}
		}
	}else{
		retorno = 0;
	}

	return retorno;
}

int validarAlfabeto(char mensaje[]){
	int retorno = 1;

	if(strlen(mensaje) > 0){
		for(int i = 0; i < strlen(mensaje); i++){
			/* Si NO es una letra rompe la validacion y la letra no es valida */
			if(isalpha(mensaje[i]) == 0){
				retorno = 0;
				break;
			}
		}
	}else{
		retorno = 0;
	}

	return retorno;
}

int obtenerNumero(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int largoNumero = 50;
	int numeroValidado;
	int resultado = 0;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do
		{
			/* Pido un numero al usuario */
			printf("%s", mensaje);
			fflush(stdin);
			fgets(numeroIngresado, largoNumero, stdin);
			numeroIngresado[strlen(numeroIngresado) - 1] = '\0';

			/* Si tiene el simbolo "-" es un numero negativo, valido los numero y si me devuelve 0(NO es un numero valido) muestro un mensaje de error */
			if(numeroIngresado[0] == '-' && !validarNumero(numeroIngresado, 1)){
				printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else if(!validarNumero(numeroIngresado, 0)){ /* Si me devuelve un 0(NO es un numero valido) muestro un mensaje de error */
				printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else{
				resultado = 1;
			}
		}
		while(!resultado); /* Si es 0(NO es un numero valido) vuelvo a pedir un numero */
	}

	/* Transformo el numero a entero */
	numeroValidado = atoi(numeroIngresado);

	return numeroValidado;
}

int obtenerNumeroRango(char* mensaje, char* mensajeError, int minimo, int maximo){
	char numeroIngresado[50];
	int largoNumero = 50;
	int numeroValidado;
	int resultado = 0;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do{
			/* Pido un numero al usuario */
			printf("%s", mensaje);
			fflush(stdin);
			fgets(numeroIngresado, largoNumero, stdin);
			*(numeroIngresado + (strlen(numeroIngresado) - 1)) = '\0';

			/*
				Si el primer caracter es el "-" es negativo y valido el numero si me devuelve un
				0(NO es un numero negativo valido) muestro un mensaje de error.
			*/
			if(*(mensaje + 0) == '-' && !validarNumero(numeroIngresado, 1)){
				printf("%s no es una numero entero valido. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else if(!validarNumero(numeroIngresado, 1)){ /* Si me devuelve un 0(NO es un numero positivo valido) muestro un mensaje de error */
				printf("%s no es un numero entero valido. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else{
				/* Transformo el numero a entero */
				numeroValidado = atoi(numeroIngresado);

				/* Si el numero no esta entre el minimo o maximo muestro el mensaje de error */
				if(numeroValidado < minimo || numeroValidado > maximo){
					printf("%s\n\n", mensajeError);
					system("pause");
				}else{
					resultado = 1;
				}
			}

		}while(!resultado || numeroValidado < minimo || numeroValidado > maximo);
	}

	return numeroValidado;
}


int obtenerNumeroPositivo(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int largoNumero = 50;
	int numeroValidado;
	int resultado = 0;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do
		{
			/* Pido un numero al usuario */
			printf("%s", mensaje);
			fflush(stdin);
			fgets(numeroIngresado, largoNumero, stdin);
			numeroIngresado[strlen(numeroIngresado) - 1] = '\0';

			/* Si me devuelve 0(NO es un numero valido) muestro un mensaje de error */
			if(!validarNumero(numeroIngresado, 0)){
				printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else{
				/* Transformo el numero a entero */
				numeroValidado = atoi(numeroIngresado);

				/* Si el numero es menor que 0 muestro el mensaje de error */
				if(numeroValidado < 0){
					printf("%s\n\n", mensajeError);
					system("pause");
				}else{
					resultado = 1;
				}
			}
		}
		while(!resultado); /* Si es 0(NO es un numero valido) vuelvo a pedir un numero */
	}

	return numeroValidado;
}

int obtenerNumeroNegativo(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int largoNumero = 50;
	int numeroValidado;
	int resultado = 0;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do
		{
			/* Pido un numero al usuario */
			printf("%s", mensaje);
			fflush(stdin);
			fgets(numeroIngresado, largoNumero, stdin);
			numeroIngresado[strlen(numeroIngresado) - 1] = '\0';

			/* Si tiene el simbolo "-" es un numero negativo */
			if(numeroIngresado[0] == '-'){
				/* Si me devuelve 0(NO es un numero valido) muestro un mensaje de error */
				if(!validarNumero(numeroIngresado, 1)){
					printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
					system("pause");
				}else{
					/* Transformo el numero a entero */
					numeroValidado = atoi(numeroIngresado);

					/* Si el numero es mayor que 0 muestro el mensaje de error */
					if(numeroValidado > 0){
						printf("%s\n\n", mensajeError);
						system("pause");
					}else{
						resultado = 1;
					}
				}
			}
		}
		while(!resultado); /* Si es 0(NO es un numero valido) vuelvo a pedir un numero */
	}

	return numeroValidado;
}

float obtenerFlotante(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int largoNumero = 50;
	int numeroValidado;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do
		{
			/* Pido un numero al usuario */
			printf("%s", mensaje);
			fflush(stdin);
			fgets(numeroIngresado, largoNumero, stdin);
			numeroIngresado[strlen(numeroIngresado) - 1] = '\0';

			/* Si me devuelve 0(NO es un numero valido) muestro un mensaje de error */
			if(!validarNumeroFlotante(numeroIngresado)){
				printf("%s\n\n", mensajeError);
				system("pause");
			}else{
				/* Transformo el numero a flotante */
				numeroValidado = atof(numeroIngresado);
			}
		}
		while(!validarNumeroFlotante(numeroIngresado)); /* Si me devuelve 0(NO es un numero valido) vuelvo a pedir un numero */
	}

	return numeroValidado;
}

float obtenerFlotantePositivo(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int largoNumero = 50;
	int numeroValidado;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do
		{
			/* Pido un numero al usuario */
			printf("%s", mensaje);
			fflush(stdin);
			fgets(numeroIngresado, largoNumero, stdin);
			numeroIngresado[strlen(numeroIngresado) - 1] = '\0';

			/* Si me devuelve 0(NO es un numero valido) muestro un mensaje de error */
			if(!validarNumeroFlotante(numeroIngresado)){
				printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else{
				/* Transformo el numero a flotante */
				numeroValidado = atof(numeroIngresado);

				/* Si el numero es menor que 0 muestro el mensaje de error */
				if(numeroValidado < 0){
					printf("%s\n\n", mensajeError);
					system("pause");
				}
			}
		}
		while(!validarNumeroFlotante(numeroIngresado)); /* Si me devuelve 0(NO es un numero valido) vuelvo a pedir un numero */
	}

	return numeroValidado;
}

void obtenerCadena(char mensaje[], char mensajeError[], char nombre[], int largoNombre){
	do
	{
		/* Pido texto al usuario */
		printf("%s", mensaje);
		fflush(stdin);
		fgets(nombre, largoNombre, stdin);
		nombre[strlen(nombre) - 1] = '\0';

		/* Si me devuelve 0(NO es una cadena valida) muestro el mensaje de error */
		if(!validarAlfabeto(nombre)){
			printf("%s\n\n", mensajeError);
			system("pause");
		}
	}
	while(!validarAlfabeto(nombre)); /* Si me devuelve 0(NO es un numero valido) vuelvo a pedir texto */
}
