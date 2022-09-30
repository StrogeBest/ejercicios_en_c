/*
Puntero: Una variable que va a almacenar la direccion de una memoria.

&a = Para saber la direccion de memoria de a.
*a = La variable cuya direccion de memoria esta almacenada a.
%d = Mascara o reseteo

https://www.onlinegdb.com/yPO1aw8se

1. Crear el vector legajo de 5 elementos y cargar los valores preguntando por consola. Mostrar los valores e indice.
2. Calcular el mayor legajo.
3. Crear vector notas y asignarlo a un legajo
4. Mostra legajo de la nota maxima
*/

#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5 // Macro
//#include "funciones.h" Las llaves dobles indica que esta dentro de la carpeta src

int dividir(int, int, float*);
int suma(int numeroUno, int numeroDos, int* resultado);

int main(void) {
	setbuf(stdout,NULL);

	float resultado;
	int resultadoSuma;
	int error;

	error = dividir(3, 2, &resultado);

	if(!error){
		printf("No se puede dividir por 0\n");
	}else{
		printf("El resultado es: %f\n", resultado);
	}

	error = suma(3, 2, &resultadoSuma);
	printf("El resultado de la suma es: %d\n", resultadoSuma);

	return 0;
}

int dividir(int divisor, int dividendo, float* resultado){
	int retorno;

	if(dividendo != 0){
		*resultado = (float)divisor / dividendo; // Casteo implicito y explicito

		retorno = 1;
	}else{
		retorno = 0;
	}

	return retorno;
}

int suma(int numeroUno, int numeroDos, int* resultado){
	*resultado = numeroUno + numeroDos;

	return 1;
}
