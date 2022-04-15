/*
 ============================================================================
 Name        : Ejercicio5-1.c
 Author      : Facundo Berges
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Pedir el ingreso de 5 números. Mostrarlos y calcular y mostrar la sumatoria de los mismos.

 Facundo Berges
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int vNumeros[5];
	int i;
	int sumaTotal = 0;

	setbuf(stdout, NULL);

	for(i = 0; i<5; i++){
		printf("Ingrese un numero entero: ");
		scanf("%d", &vNumeros[i]);
	}

	printf("\nLos numeros ingresados son: \n");

	for(i = 0; i<5; i++){
		printf("%d\n", vNumeros[i]);
	}

	for(i = 0; i<5; i++){
		sumaTotal += vNumeros[i];
	}

	printf("La suma total de los numeros ingresados da como resultado %d.\n", sumaTotal);


	return EXIT_SUCCESS;
}
