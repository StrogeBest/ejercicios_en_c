/*
 ============================================================================
 Name        : Ejercicio_5-5.c
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

	int numeros[10];
	int cantidadPositivos = 0;
	int acumuladorPositivos = 0;
	int cantidadNegativos = 0;
	int negativoMayor;
	int bandera = 0; // Inicializacion
	int promedio;

	int numero; // Declaracion
	int posicion;
	char seguir;

	for(int i = 0; i < 10; i++){
		numeros[i] = 0;
	}
	// sizeof() = cantidad de bytes
	// strlen() = length de javascript
	//
	do
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numero);
		printf("Ingrese en que posicion (1 a 10): ");
		scanf("%d", &posicion);

		numeros[posicion-1] = numero;

		printf("Quiere ingresar otro numero? S/N: ");
		fflush(stdin);
		scanf("%c", &seguir);
	}
	while(seguir == 's');

	for(int i = 0; i < 10; i++){
		if(numeros[i] > 0){
			acumuladorPositivos += numeros[i];
			cantidadPositivos++;
		}else{
			if(!bandera){
				negativoMayor = numeros[i];
				bandera = 1;
			}else{
				if(numeros[i] > negativoMayor){
					negativoMayor = numeros[i];
				}
			}
			cantidadNegativos++;
		}
	}

	promedio = acumuladorPositivos / cantidadPositivos;
	printf("\nPromedio de los numero positivos: %d\n", promedio);
	printf("Lista de numeros del numero negativo mayor hasta cero: ");
	for(int i = negativoMayor; i < 0; i++){
		if(!i){
			printf("%d", i);
		}else{
			printf("%d, ", i);
		}
	}

	return EXIT_SUCCESS;
}

/*
if(res != NULL){ PUNTERO
	return 1;
}

if(vector != NULL && tamaño > 0){ VECTOR
	return 1;
}
// Carga aleatoria
	int numero;
	int posicion;
	char seguir;

	do
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numero);
		printf("Ingrese en que posicion: ");
		scanf("%d", &posicion);

		numeros[posicion-1] = numero;

		printf("Quiere ingresar otro numero? S/N: ");
		fflush(stdin);
		scanf("%c", &seguir);
	}
	while(seguir == 's');
*/
