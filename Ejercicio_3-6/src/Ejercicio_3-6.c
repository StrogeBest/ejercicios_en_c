/*
Realizar un programa que: asigne a la variable numero1 un valor
solicitado al usuario, valide el mismo entre 10 y 100, realice un descuento del 5% a
dicho valor a través de una función llamada realizarDescuento(). Mostrar el resultado
por pantalla.
 */

#include <stdio.h>
#include <stdlib.h>

float realizarDescuento(int numero);

int main(void) {
	setbuf(stdout,NULL);

	int numeroIngresado;
	float precioFinal;

	printf("Ingrese un numero: ");
	scanf("%d", &numeroIngresado);
	while(numeroIngresado < 10 || numeroIngresado > 100){
		printf("ERROR. Ingrese un numero: ");
		scanf("%d", &numeroIngresado);
	}

	precioFinal = realizarDescuento(numeroIngresado);

	printf("Precio final: %f", precioFinal);

	return 0;
}

float realizarDescuento(int numero){
	printf("%d\n", numero);
	float descuento = 0.57;
	printf("%f\n", descuento);
	descuento = 150 / 100;
	printf("%.7f\n", descuento);
	float precioConDescuento = numero - descuento;
	printf("%f\n", precioConDescuento);
	return precioConDescuento;
}
