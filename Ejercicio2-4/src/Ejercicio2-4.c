/*
 ============================================================================
 Name        : Ejercicio2-4.c
 Author      : Facundo Berges
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Ingresar 5 caracteres e informar cuantas letras p (minúsculas) se ingresaron.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	char caracterIngresado;
	int i, contador_p;

	contador_p = 0;

	for(i = 0; i < 5; i++){
		printf("Ingrese un caracter: ");
		fflush(stdin);
		scanf("%c", &caracterIngresado);

		if(caracterIngresado == 'p'){
			contador_p++;
		}
	}

	if(contador_p == 0){
		printf("\nNo se ingresaron p minusculas.\n");
	}
	else{
		printf("\nSe ingresaron %d p minusculas.\n", contador_p);
	}

	return EXIT_SUCCESS;
}
