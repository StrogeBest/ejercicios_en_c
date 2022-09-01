/*
Realizar un programa que: asigne a las variables numero1 y numero2
los valores solicitados al usuario, valide los mismos entre 10 y 100, asigne a la
variable operacion el valor solicitado al usuario, valide el mismo 's'-sumar, 'r'-restar,
realice la operación de dichos valores a través de una función. Mostrar el resultado
por pantalla.
 */

#include <stdio.h>
#include <stdlib.h>

int sumaResta(int numUno, int numDos, char operacion);

int main(void) {
	setbuf(stdout,NULL);

	int numeroUno;
	int numeroDos;
	char operacion;
	int resultado;

	printf("Ingrese el primer numero: ");
	scanf("%d", &numeroUno);
	while(numeroUno < 10 || numeroUno > 100){
		printf("ERROR. Ingrese el primer numero: ");
		scanf("%d", &numeroUno);
	}

	printf("Ingrese el segundo numero: ");
	scanf("%d", &numeroDos);
	while(numeroDos < 10 || numeroDos > 100){
		printf("ERROR. Ingrese el segundo numero: ");
		scanf("%d", &numeroDos);
	}

	printf("Ingrese s para la suma o r para la resta: ");
	scanf("%c", &operacion);
	while(operacion != 's' && operacion != 'r'){
		printf("ERROR. Ingrese s para la suma o r para la resta: ");
		fflush(stdin);
		scanf("%c", &operacion);
	}

	resultado = sumaResta(numeroUno, numeroDos, operacion);

	printf("El resultado es %d", resultado);

	return 0;
}

int sumaResta(int numUno, int numDos, char operacion){
	int resultado;

	switch(operacion){
		case 's':
			resultado = numUno + numDos;
			break;
		case 'r':
			resultado = numUno - numDos;
			break;
	}
	return resultado;
}
