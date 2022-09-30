/*
 ============================================================================
 Name        : Ejercicio_5-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeros[10]; // El array es un puntero
	int cantidadNegativos = 0;
	int acumuladorImpares = 0;
	int numeroParMayor;
	int bandera = 0;

	for(int i = 0; i < 10; i++){
		printf("Ingrese el %d numero: ", i+1);
		scanf("%d", &numeros[i]);

		while(numeros[i] < -100 || numeros[i] > 100){
			printf("ERROR. Ingrese el %d numero: ", i+1);
			scanf("%d", &numeros[i]);
		}

		// PUNTO A
		if(numeros[i] < 0){
			cantidadNegativos++;
		}

		// PUNTO C
		if(numeros[i] % 2 == 0){
			if(!bandera){
				numeroParMayor = numeros[i];
				bandera = 1;
			}else{
				if(numeros[i] > numeroParMayor){
					numeroParMayor = numeros[i];
				}
			}
		}else{
			acumuladorImpares += numeros[i];
		}
	}

	printf("\na. Cantidad de numeros negativos: %d\n", cantidadNegativos);
	printf("b. Suma de los numero impares: %d\n", acumuladorImpares);
	printf("c. El numero mayor de los numero pares es: %d\n", numeroParMayor);
	printf("d. Lista de los numero ingresados: ");
	for(int i = 0; i < 10; i++){
		if(i == 9){
			printf("%d\n", numeros[i]);
		}else{
			printf("%d - ", numeros[i]);
		}
	}
	// PUNTO E
	printf("e. Lista de los numero mayores a 15: ");
	for(int i = 0; i < 10; i++){
		if(numeros[i] > 15){
			if(i == 9){
				printf("%d", numeros[i]);
			}else{
				printf("%d - ", numeros[i]);
			}
		}
	}
	// PUNTO F
	printf("\nf. Lista de los numero de las posiciones impares: ");
	for(int i = 0; i < 10; i++){
		if(i % 2 != 0){
			if(i == 9){
				printf("%d\n", numeros[i]);
			}else{
				printf("%d - ", numeros[i]);
			}
		}
	}

	return EXIT_SUCCESS;
}
