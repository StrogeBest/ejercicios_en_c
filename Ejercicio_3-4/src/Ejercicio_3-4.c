/*
Especializar la función del punto 3.1 y 3.2 para que valide el número en un rango determinado.
 */

#include <stdio.h>
#include <stdlib.h>

// Funcion del ejercicio 1
void mostrarNumero(int numero, int numeroMin, int numeroMax);
// Funcion del ejercicio 2
float ingresarNumeroFlotante(int numeroMin, int numeroMax);

int main(void) {
	setbuf(stdout,NULL);

	mostrarNumero(-1, -11, 3);

	return 0;
}

void mostrarNumero(int numero, int numeroMin, int numeroMax){
	if(numero > numeroMin && numero < numeroMax){
		printf("El %d esta dentro del rango de %d y %d\n\n", numero, numeroMin, numeroMax);
		for(int i = numeroMin; i <= numeroMax; i++){
			if(numero == i){
				printf("|%d|, ", i);
			}else{
				if(numeroMax == i){
					printf("%d", i);
				}else{
					printf("%d, ", i);
				}
			}
		}
	}else{
		printf("El %d NO esta dentro del rango de %d y %d", numero, numeroMin, numeroMax);
	}
}

float ingresarNumeroFlotante(int numeroMin, int numeroMax){
	float numero;

	printf("Ingrese un numero: \n");
	scanf("%f", &numero);

	if(numero > numeroMin && numero < numeroMax){
		return numero;
	}else{
		return 0;
	}
}
