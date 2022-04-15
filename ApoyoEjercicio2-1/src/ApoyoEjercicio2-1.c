/*
 ============================================================================
 Name        : ApoyoEjercicio2-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Facundo Berges


 Crear una función que reciba como parámetro un número entero.
 La función retorna 1 en caso de que sea positivo, -1 en caso de que sea negativo y 0 en caso de que sea 0.
 Realizar la prueba lógica de la función en el main.
 */

#include <stdio.h>
#include <stdlib.h>

int ValidarPositivo(int numero);

int main(void) {
	setbuf(stdout, NULL);

	int positividad;

	positividad = ValidarPositivo(-2);
	if(positividad == 0){
		printf("El numero ingresado es 0 (retorno de funcion %d)", positividad);
	}
	else if(positividad == 1){
		printf("El numero ingresado es positivo (retorno de funcion %d)", positividad);
	}
	else {
		printf("El numero ingresado es negativo (retorno de funcion %d)", positividad);
	}

	return EXIT_SUCCESS;
}


int ValidarPositivo(int numero){
	int esPositivo;

	if(numero == 0){
		esPositivo = 0;
	}
	else if(numero > 0){
		esPositivo = 1;
	}
	else {
		esPositivo = -1;
	}

	return esPositivo;
}
