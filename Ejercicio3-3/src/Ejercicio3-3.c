/*
 ============================================================================
 Name        : Ejercicio3-3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Crear una función que pida el ingreso de un entero y lo retorne.


 Facundo Berges
 */

#include <stdio.h>
#include <stdlib.h>

int pedirNumEntero(void);

int main(void) {
	int numIngresado = pedirNumEntero();
	printf("\nEl numero entero ingresado es %d", numIngresado);

	return EXIT_SUCCESS;
}


int pedirNumEntero(void){
	int numIngresado;
	float aux;

	printf("Ingrese un numero entero: ");
	scanf("%f", &aux);
	numIngresado = aux;
	while(aux - numIngresado != 0){
		printf("Error. Numero ingresado no es un numero entero. Ingrese un numero entero (sin decimales): ");
		scanf("%f", &aux);
		numIngresado = aux;
	}

	return numIngresado;
}
