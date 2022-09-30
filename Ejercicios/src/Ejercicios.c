/*
Escribir un programa que realice lea por teclado 20 caracteres. Luego de la lectura indicar cuantas "a" se
ingresaron, cuantas "e, i, o, u"
*/

#include <stdio.h>
#include <stdlib.h>
/*
valor copia, referencia - direccion de memoria | * y [] es lo mismo son punteros

https://www.onlinegdb.com/fM80wkGAL
*/

void inicializarVector(int vector[], int tam, int valorInicial);

int main(void) {
	setbuf(stdout, NULL);

	int vectorNumeros[5];

	inicializarVector(vectorNumeros, 5, 0);

	printf("Lista de numeros: ");

	for(int i = 0; i < 5; i++){
		printf("%d - ", vectorNumeros[i]);
	}

	// Carga secuencial
	int numeros[5]; // 4 bits para cada elemento
	for(int i = 0; i < 5; i++){
		printf("Ingrese un numero");
		scanf("%d", &numeros[i]);
	}



	return 0;
}

void inicializarVector(int vector[], int tam, int valorInicial){
	for(int i = 0; i < tam; i++){
		vector[i] = valorInicial;
	}
}
