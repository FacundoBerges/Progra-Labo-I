/*
 ============================================================================
 Name        : Ejercicio3-5.c
 Author      : Facundo H. Berges
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4 combinaciones.
 (Apunta a que entiendan el concepto de independencia del código)

	int Sumar1(int, int);
	int Sumar2(void);
	void  Sumar3(int, int);
	void Sumar4(void);


 Facundo Berges

 */

#include <stdio.h>
#include <stdlib.h>

int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);

int main(void) {
	setbuf(stdout, NULL);


	return EXIT_SUCCESS;
}


int Sumar1(int num1, int num2){
	int result = num1 + num2;

	return result;
}

int Sumar2(void){
	int result
	printf("Ingrese un numero");

	return result;
}
