/*============================================================================
Ejercicio 1-3:
ingresar 3 números y mostrar el número del medio, sólo si existe. En
caso de que no exista también informarlo.
Ejemplo:
1 5 3 el 3 es del medio
5 1 5 no hay número del medio
3 5 1 el 3 es del medio
3 1 5 el 3 es del medio
5 3 1 el 3 es del medio
============================================================================*/

/*
1 > 5 | false
1 > 3 | false

!(1 > 5 && 1 > 3) = 1

1 < 5 | true
1 < 3 | true

!(1 < 5 && 1 < 3) = 0

!(1 > 5 && 1 > 3) && !(1 < 5 && 1 < 3) == 0
-------------
5 > 1 | true
5 > 3 | true

!(5 > 1 && 5 > 3) = 0

5 < 1 | false
5 < 3 | false

!(5 < 5 && 5 < 3) = 1

!(5 > 1 && 5 > 3) && !(5 < 5 && 5 < 3) = 0
-------------
3 > 1 | true
3 > 5 | false

!(3 > 1 && 3 > 5) = 1

3 < 1 | false
3 < 5 | true

!(3 < 1 && 3 < 5) = 1

!(3 > 1 && 3 > 5) && !(3 < 1 && 3 < 5) = 1
=============
3 > 5 | false
3 > 1 | true

3 < 5 | true
3 < 1 | false
-------------
5 > 1 | true
5 > 3 | true

5 < 1 | false
5 < 3 | false
-------------
1 > 5 | false
1 > 3 | false

1 < 5 | true
1 < 3 | true
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	int numeroMedio;
	int numeroUno;
	int numeroDos;
	int numeroTres;

	printf("Ingrese el primer numero: ");
	scanf("%d", &numeroUno);

	printf("Ingrese el segundo numero: ");
	scanf("%d", &numeroDos);

	printf("Ingrese el tercer numero: ");
	scanf("%d", &numeroTres);

	if(!(numeroUno > numeroDos && numeroUno > numeroTres) && !(numeroUno < numeroDos && numeroUno < numeroTres)){
		numeroMedio = numeroUno;
	}

	if(!(numeroDos > numeroUno && numeroDos > numeroTres) && !(numeroDos < numeroUno && numeroDos < numeroTres)){
		numeroMedio = numeroDos;
	}

	if(!(numeroTres > numeroUno && numeroTres > numeroDos) && !(numeroTres < numeroUno && numeroTres < numeroDos)){
		numeroMedio = numeroTres;
	}

	printf("El numero del medio es: %d", numeroMedio);

	return 0;
}
