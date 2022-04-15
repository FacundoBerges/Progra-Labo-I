/*
 ============================================================================
 Name        : Ejercicio2-2.c
 Author      : Facundo H Berges
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Ingresar 10 números enteros, distintos de cero. Mostrar:

a. Cantidad de pares e impares.
b. El menor número ingresado.
c. De los pares el mayor número ingresado.
d. Suma de los positivos.
e. Producto de los negativos.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int i, numeroIngresado, contadorPares, contadorImpares, flagPrimerNum, menorIngresado, flagPrimerPar, mayorPar, sumaPositivos, productoNegativos, flagPrimerPositivo, flagPrimerNegativo;
	contadorPares = 0;
	contadorImpares = 0;
	sumaPositivos = 0;
	productoNegativos = 1;
	flagPrimerNum = 1;
	flagPrimerPar = 1;
	flagPrimerPositivo = 1;
	flagPrimerNegativo = 1;

	for(i = 0; i < 10; i++){
		printf("Ingrese un numero entero (distinto de 0): ");
		scanf("%d", &numeroIngresado);
		while (numeroIngresado == 0){
			printf("ERROR. Ingrese un numero (distinto de 0): ");
			scanf("%d", &numeroIngresado);
		}

		// Punto A y C
		if((numeroIngresado % 2) == 0){
			contadorPares++;
			if(flagPrimerPar == 1){
				mayorPar = numeroIngresado;
				flagPrimerPar = 0;
			}
			else{
				if(numeroIngresado > mayorPar){
					mayorPar = numeroIngresado;
				}
			}
		}
		else {
			contadorImpares++;
		}

		// Punto B
		if(flagPrimerNum == 1){
			menorIngresado = numeroIngresado;
			flagPrimerNum = 0;
		}
		else {
			if(numeroIngresado < menorIngresado){
				menorIngresado = numeroIngresado;
			}
		}

		// Punto D
		if(numeroIngresado > 0){
			sumaPositivos += numeroIngresado;
			flagPrimerPositivo = 0;
		} //Punto E
		else if (numeroIngresado < 0){
			productoNegativos *= numeroIngresado;
			flagPrimerNegativo = 0;
		}

	}

	printf("\nSe ingresaron %d numero/s pare/s y %d numero/s impar/es.\nEl menor numero ingresado fue %d.\n", contadorPares, contadorImpares, menorIngresado);

	if(contadorPares == 0){
		printf("No hay mayor numero par ya que no se ingresaron numeros pares.\n");
	}
	else {
		printf("El mayor numero par ingresado fue %d.\n", mayorPar);
	}

	if(flagPrimerPositivo == 0){
		printf("La suma de los numeros positivos ingresados da como resultado %d.\n", sumaPositivos);
	}
	else {
		printf("No se ingresaron numeros positivos.\n");
	}

	if(flagPrimerNegativo == 0){
		printf("El producto de los numeros negativos ingresados da como resultado %d.\n", productoNegativos);
	}
	else {
		printf("No se ingresaron numeros negativos.\n");
	}

	printf("\nFin del programa...\n\n");
	system("pause");
	return EXIT_SUCCESS;
}
