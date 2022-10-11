/*
 * pedirDatos.h
 *
 *  Created on: 30 sep. 2022
 *      Author: Javier
 */


#ifndef PEDIRDATOS_H_
#define PEDIRDATOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>

int validarSalir(char mensaje[], char mensajeError[]);
int validarNumero(char* buffer);
int validarNumeroFlotante(char buffer[]);
int validarCadena(char buffer[]);

int obtenerNumeroRango(char mensaje[], char mensajeError[], int minimo, int maximo);
int obtenerNumeroNegativo(char mensaje[], char mensajeError[]);
int obtenerNumeroPositivo(char mensaje[], char mensajeError[]);
float obtenerFlotante(char mensaje[], char mensajeError[]);
float obtenerFlotanteNegativo(char mensaje[], char mensajeError[]);
float obtenerFlotantePositivo(char mensaje[], char mensajeError[]);
void obtenerCadena(char mensaje[], char mensajeError[], char cadena[], int largoCadena);

#endif /* PEDIRDATOS_H_ */
