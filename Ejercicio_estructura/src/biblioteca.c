/*
 * biblioteca.c
 *
 *  Created on: 24 sep. 2022
 *      Author: Javier
 */

int obtenerCaracteres(char cadena[], int tam){
	int retorno = 1;
	char texto[];

	for(int i = 0; i < tam; i++){
		if(!isalpha(cadena[i])){
			retorno = 0;

			break;
		}
	}

	return retorno;
}

int obtenerNumeroDeUnRango(){
	int retorno = 0;

	return retorno;
}
