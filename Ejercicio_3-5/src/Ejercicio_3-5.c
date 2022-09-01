/*
Realizar un programa en donde se puedan utilizar los prototipos de la
función Restar en sus 4 combinaciones.
	int Restar1(int, int);
	int Restar2(void);
	void Restar3(int, int);
	void Restar4(void);
 */

#include <stdio.h>
#include <stdlib.h>

int restar1(int numeroUno, int numeroDos);
int restar2(void);
void restar3(int numeroUno, int numeroDos);
void restar4(void);

int main(void) {
	int resultado;

	resultado = restar1(50, 10);
	printf("La resta es: %d", resultado);

	resultado = resta2();
	printf("La resta es: %d", resultado);

	restar3(65, 20);

	restar4();

	return 0;
}

int restar1(int numeroUno, int numeroDos){
	int resultado = numeroUno - numeroDos;

	return resultado;
}

int restar2(void){
	int numeroUnoIngresado;
	int numeroDosIngresado;
	int resultado;

	printf("Ingrese el primer numero: ");
	scanf("%d", &numeroUnoIngresado);

	printf("Ingrese el segundo numero: ");
	scanf("%d", &numeroDosIngresado);

	resultado = numeroUnoIngresado - numeroDosIngresado;

	return resultado;
}

void restar3(int numeroUno, int numeroDos){
	int resultado = numeroUno - numeroDos;

	printf("La resta es: %d", resultado);
}

void restar4(void){
	int numeroUnoIngresado;
	int numeroDosIngresado;
	int resultado;

	printf("Ingrese el primer numero: ");
	scanf("%d", &numeroUnoIngresado);

	printf("Ingrese el segundo numero: ");
	scanf("%d", &numeroDosIngresado);

	resultado = numeroUnoIngresado - numeroDosIngresado;

	printf("La resta es: %d", resultado);
}
