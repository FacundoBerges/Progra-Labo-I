/*
 ============================================================================
 Name        : ApoyoEjercicio2-0.c
 Author      : Facundo Berges
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Facundo Berges


 Crear una función que reciba como parámetro dos números enteros,
 que realice el promedio de los números y que retorne dicho valor.
 */

#include <stdio.h>
#include <stdlib.h>

float PromediarEnteros(int numero1, int numero2);

int main(void) {
	float promedioNums;

	setbuf(stdout, NULL);

	promedioNums = PromediarEnteros(4, 7);
	printf("El numero promedio es %.2f.", promedioNums);

	return EXIT_SUCCESS;
}


float PromediarEnteros(int numero1, int numero2){
	float promedio;

	promedio = (float) (numero1 + numero2)/ 2;

	return promedio;
}
