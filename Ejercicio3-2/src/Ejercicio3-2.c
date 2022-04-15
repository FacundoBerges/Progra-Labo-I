/*
 ============================================================================
 Name        : Ejercicio3-2.c
 Author      : Facundo H. Berges
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Crear una función que permita determinar si un número es par o no. La función retorna 1 en caso afirmativo y 0 en caso contrario. Probar en el main.


 Facundo Berges
 */

#include <stdio.h>
#include <stdlib.h>

int calcularPar(int);

int main(void) {

	int num = 3;
	int esPar = calcularPar(num);

	setbuf(stdout, NULL);
	if(esPar == 1){
		printf("El numero %d es un numero par.\n", num);
	}
	else{
		printf("El numero %d es un numero impar.\n", num);
	}


	return EXIT_SUCCESS;
}


int calcularPar(int numero){
	int numPar;

	if(numero % 2 == 0){
		numPar = 1;
	}
	else{
		numPar = 0;
	}

	return numPar;
}
