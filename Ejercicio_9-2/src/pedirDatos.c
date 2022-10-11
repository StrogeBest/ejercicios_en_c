#include "pedirDatos.h"

/* -----------------------------------VALIDACIONES----------------------------------- */
int validarSalir(char mensaje[], char mensajeError[]){
	int retorno = 0;
	char letra;

	do{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &letra);

		if((letra != 'n' || letra != 'N') && (letra != 's' || letra != 'S')){
			printf("%s\n\n", mensajeError);
		}else{
			retorno = 1;
		}
	}
	while((letra != 'n' || letra != 'N') && (letra != 's' || letra != 'S'));

	return retorno;
}

int validarNumero(char cadena[], int valor){
	int retorno = 1;

	for(int i = valor; i < strlen(cadena); i++){
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
		if(cadena[0] == '-'){
			for(int i = 1; i < strlen(cadena); i++){
				/* Valido que haya un punto */
				if(cadena[i] == '.'){
					/* Verifico que el siguiente valor despues del punto sea menor al tamaño de la cadena */
					if(i + 1 < strlen(cadena)){
						validarNumero(cadena, i + 1);
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
			for(int i = 0; i < strlen(cadena); i++){
				/* Valido que haya un punto */
				if(cadena[i] == '.'){
					/* Verifico que el siguiente valor despues del punto sea menor al tamaño de la cadena */
					if(i + 1 < strlen(cadena)){
						/* Despues del punto recorro los decimales */
						for(int j = i + 1; j < strlen(cadena); j++){
							/* Si no es un numero rompe la validacion y el numero no es valido */
							if(!isdigit(cadena[j])){
								retorno = 0;
								break;
							}
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
		}
	}else{
		retorno = 0;
	}

	return retorno;
}

int validarCadena(char mensaje[]){
	int retorno = 1;

	if(strlen(mensaje) > 0){
		for(int i = 0; i < strlen(mensaje); i++){
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

/* -----------------------------------OBTENER DATOS----------------------------------- */
int obtenerNumeroRango(char mensaje[], char mensajeError[], int minimo, int maximo){
	char numeroIngresado[50];
	int resultado;
	int numeroValidado;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do
		{
			printf("%s", mensaje);
			scanf("%s", numeroIngresado);

			resultado = validarNumero(numeroIngresado);

			if(!resultado){
				printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else{
				numeroValidado = atoi(numeroIngresado);

				if(numeroValidado < minimo || numeroValidado > maximo){
					printf("%s\n\n", mensajeError);
					system("pause");
				}
			}
		}
		while(!resultado || numeroValidado < minimo || numeroValidado > maximo);
	}

	return numeroValidado;
}

void obtenerCadena(char mensaje[], char mensajeError[], char nombre[], int largoNombre){
	int resultado;

	do
	{
		printf("%s", mensaje);
		fflush(stdin);
		fgets(nombre, largoNombre, stdin);
		nombre[strlen(nombre) - 1] = '\0';
		resultado = validarCadena(nombre);

		if(!resultado){
			printf("%s\n\n", mensajeError);
			system("pause");
		}
	}
	while(!resultado);
}

float obtenerFlotante(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int resultado;
	float numeroValidado;

	do
	{
		printf("%s", mensaje);
		scanf("%s", numeroIngresado);

		resultado = validarNumeroFlotante(numeroIngresado);

		if(!resultado){
			printf("%s\n\n", mensajeError);
			system("pause");
		}else{
			numeroValidado = atof(numeroIngresado);
		}
	}
	while(!resultado);

	return numeroValidado;
}

float obtenerFlotantePositivo(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int resultado;
	float numeroValidado;

	do
	{
		printf("%s", mensaje);
		scanf("%s", numeroIngresado);

		resultado = validarNumeroFlotante(numeroIngresado);

		if(!resultado){
			printf("El numero ingresado es incorrecto. Intentelo de nuevo\n\n");
			system("pause");
		}else{
			numeroValidado = atof(numeroIngresado);

			if(numeroValidado < 0){
				printf("%s\n\n", mensajeError);
				system("pause");
			}
		}
	}
	while(!resultado);

	return numeroValidado;
}

float obtenerFlotanteNegativo(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int resultado;
	float numeroValidado;

	do
	{
		printf("%s", mensaje);
		scanf("%s", numeroIngresado);

		resultado = validarNumeroFlotante(numeroIngresado);

		if(!resultado){
			printf("El numero ingresado es incorrecto. Intentelo de nuevo\n\n");
			system("pause");
		}else{
			numeroValidado = atof(numeroIngresado);

			if(numeroValidado > 0){
				printf("%s\n\n", mensajeError);
				system("pause");
			}
		}
	}
	while(!resultado);

	return numeroValidado;
}

int obtenerNumeroPositivo(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int resultado;
	int numeroValidado;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do
		{
			printf("%s", mensaje);
			scanf("%s", numeroIngresado);

			resultado = validarNumero(numeroIngresado, 0);

			if(!resultado){
				printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else{
				numeroValidado = atoi(numeroIngresado);

				if(numeroValidado < 0){
					printf("%s\n\n", mensajeError);
					system("pause");
				}
			}
		}
		while(!resultado);
	}

	return numeroValidado;
}

int obtenerNumeroNegativo(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int resultado;
	int numeroValidado;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do
		{
			printf("%s", mensaje);
			scanf("%s", numeroIngresado);

			if(numeroIngresado[0] == '-'){
				resultado = validarNumero(numeroIngresado, 1);

				if(!resultado){
					printf("%s no es un numero valido. Intentelo de nuevo\n\n", numeroIngresado);
					system("pause");
				}else{
					numeroValidado = atoi(numeroIngresado);

					if(numeroValidado > 0){
						printf("%s\n\n", mensajeError);
						system("pause");
					}
				}
			}

		}
		while(!resultado);
	}

	return numeroValidado;
}
