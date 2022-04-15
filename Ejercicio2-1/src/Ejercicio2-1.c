/*
 ============================================================================
 Name        : Ejercicio2-1.c
 Author      : Facundo H. Berges
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la aplicación con distintos valores.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int i, numIngresado, cantidad, totalIngresado;
	totalIngresado = 0;
	cantidad = 5;
	float promedio;

	for(i = 0; i < cantidad ; i++){
		printf("Ingrese un numero: ");
		scanf("%d", &numIngresado);

		totalIngresado = totalIngresado + numIngresado;
	}

	promedio = (float)totalIngresado / cantidad;

	printf("El promedio de los numeros ingresados es %.2f", promedio);

	return EXIT_SUCCESS;
}
