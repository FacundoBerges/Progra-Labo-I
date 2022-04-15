/*
 ============================================================================
 Name        : ApoyoEjercicio1-2.c
 Author      : Facundo Berges
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en qué orden fue ingresado.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int i, numIngresado, numMax, numMin, posMax, posMin, total;
	total = 5;

	for(i = 0; i < total; i++){
		printf("Ingrese un numero: ");
		scanf("%d", &numIngresado);

		if(i != 0){
			if(numIngresado > numMax){
				numMax = numIngresado;
				posMax = i+1;
			}
			if(numIngresado < numMin){
				numMin = numIngresado;
				posMin = i+1;
			}
		}
		else {
			numMax = numIngresado;
			numMin = numIngresado;
			posMax = i+1;
			posMin = i+1;
		}
	}

	printf("\nEl mayor valor ingresado fue %d y se ingreso como %d de los %d numeros.\nEl menor valor ingresado fue %d y se ingreso como %d de los %d numeros.\n\n", numMax, posMax, total, numMin, posMin, total);

	return EXIT_SUCCESS;
}
