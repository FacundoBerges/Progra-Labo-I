/*
 ============================================================================
 Name        : Ejercicio3-1.c
 Author      : Facundo Hector Berges
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Crear una funci�n que muestre por pantalla el n�mero flotante  que recibe como par�metro.


 */

#include <stdio.h>
#include <stdlib.h>

void MostrarNumFlotante(float numero);

int main(void) {
	float pi = 3.1416;

	MostrarNumFlotante(pi);

	return EXIT_SUCCESS;
}

//Funcion
void MostrarNumFlotante(float numero){
	printf("El numero flotante recibido es %f", numero);
}
