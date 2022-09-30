/*
 * biblioteca.h
 *
 *  Created on: 22 sep. 2022
 *      Author: Javier
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int validarNumero(char numero[]);
int obtenerNumero(int* pResultado, char mensaje[]);
int obtenerNumeroPositivo(int* pResultado, char mensaje[], char mensajeError[]);
int validarRangoNumero(int numero, int minimo, int maximo, char mensajeError[]);
int pedirEnteroRango(char mensaje, int minimo, int maximo);

#endif /* BIBLIOTECA_H_ */
