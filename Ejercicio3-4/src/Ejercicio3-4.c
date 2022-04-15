/*
 ============================================================================
 Name        : Ejercicio3-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Crear una función que pida el ingreso de un entero y lo retorne. 3-3

 Especializar la función anterior para que permita validar el entero ingresado en un rango determinado.


 Facundo Berges
 */

#include <stdio.h>
#include <stdlib.h>

int pedirNumEntero(int, int);

int main(void) {
	int numIngresado;

	setbuf(stdout, NULL);

	numIngresado = pedirNumEntero(-5, 9);

	printf("\nEl numero entero ingresado es %d.", numIngresado);

	return EXIT_SUCCESS;
}


int pedirNumEntero(int limiteMenor, int limiteMayor){
	int numIngresado;
	float aux;

	printf("Ingrese un numero entero: ");
	scanf("%f", &aux);
	numIngresado = aux;
	while((aux - numIngresado != 0) || numIngresado < limiteMenor || numIngresado > limiteMayor){
		printf("Error. Numero ingresado no es un numero entero o se encuentra fuera del rango. Ingrese un numero entero (sin decimales y dentro del rango %d a %d): ", limiteMenor, limiteMayor);
		scanf("%f", &aux);
		numIngresado = aux;
	}


	return numIngresado;
}
