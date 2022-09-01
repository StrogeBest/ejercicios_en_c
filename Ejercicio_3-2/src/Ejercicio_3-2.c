/*
Crear una función que pida el ingreso de un flotante y lo retorne.
 */

#include <stdio.h>
#include <stdlib.h>

float ingresarNumeroFlotante();

int main(void) {
	setbuf(stdout,NULL);

	float resultado = ingresarNumeroFlotante();

	printf("El numero ingresado es %f", resultado);

	return 0;
}

float ingresarNumeroFlotante(){
	float numero;

	printf("Ingrese un numero: \n");
	scanf("%f", &numero);

	return numero;
}
