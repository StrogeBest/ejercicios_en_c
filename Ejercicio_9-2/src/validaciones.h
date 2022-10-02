/*
 * validaciones.h
 *
 *  Created on: 30 sep. 2022
 *      Author: Javier
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int validarNumero(char buffer[]);
int validarNumeroNegativo(char cadena[]);
int validarNumeroPositivo(char cadena[]);
int validarNumeroFlotante(char buffer[]);
int validarCadena(char buffer[]);

#endif /* VALIDACIONES_H_ */
