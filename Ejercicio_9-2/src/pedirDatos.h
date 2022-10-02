/*
 * pedirDatos.h
 *
 *  Created on: 30 sep. 2022
 *      Author: Javier
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PEDIRDATOS_H_
#define PEDIRDATOS_H_

int obtenerNumeroRango(char mensaje[], char mensajeError[], int minimo, int maximo);
float obtenerFlotante(char mensaje[], char mensajeError[]);
void obtenerCadena(char mensaje[], char mensajeError[], char cadena[], int largoCadena);
int obtenerNumeroPositivo(char mensaje[], char mensajeError[]);

#endif /* PEDIRDATOS_H_ */
