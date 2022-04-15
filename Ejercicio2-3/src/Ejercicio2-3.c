/*
 ============================================================================
 Name        : Ejercicio2-3.c
 Author      : Facundo Hector Berges
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas, de cada persona debemos obtener los siguientes datos:
	- número de cliente,
	- estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
	- edad (solo mayores de edad, más de 17),
	- temperatura corporal (validar por favor) y
	- genero ('f' para femenino, 'm' para masculino, 'o' para no binario).
 NOTA: El precio por pasajero es de $600.
  Se debe informar (solo si corresponde):
	a) La cantidad de personas con estado "viudo" de más de 60 años.
	b) el número de cliente y edad de la mujer soltera más joven.
	c) cuánto sale el viaje total sin descuento.
	d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que solo mostramos si corresponde.

 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL);

	char continuar, estadoCivil, genero;
	int numeroCliente, edad, precioPorPasajero, flagViudoMayorA60, contadorViudosMayoresA60, clienteSolteraMasJoven, edadSolteraMasJoven, flagPrimerMujer, totalSinDescuento, contadorPasajeros, contadorMayoresA60, precioConDescuento;
	float temperatura, descuento;

	precioPorPasajero = 600;
	contadorViudosMayoresA60 = 0;
	flagViudoMayorA60 = 1;
	flagPrimerMujer = 1;
	totalSinDescuento = 0;
	contadorPasajeros = 0;
	contadorMayoresA60 = 0;
	descuento = 0.25;

	do{
		printf("Ingrese numero de cliente: ");
		scanf("%d", &numeroCliente);
		while(numeroCliente < 1){
			printf("Error. Ingrese numero de cliente (mayor a 1): ");
			scanf("%d", &numeroCliente);
		}

		printf("Ingrese estado civil ('s' para soltero, 'c' para casado o 'v' para viudo): ");
		fflush(stdin);
		scanf("%c", &estadoCivil);
		estadoCivil = tolower(estadoCivil);
		while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v'){
			printf("ERROR. Ingrese estado civil ('s' para soltero, 'c' para casado o 'v' para viudo): ");
			fflush(stdin);
			scanf("%c", &estadoCivil);
			estadoCivil = tolower(estadoCivil);
		}

		printf("Ingrese edad (mayor a 17 anios): ");
		scanf("%d", &edad);
		while(edad < 18 || edad > 110){
			printf("Error. Ingrese edad (mayor a 17 anios y menor a 110): ");
			scanf("%d", &edad);
		}

		printf("Ingrese temperatura corporal: ");
		scanf("%f", &temperatura);
		while(temperatura < 35.5 || temperatura > 39.5){
			printf("Error. Ingrese temperatura corporal (entre 35.5 y 39.5 grados: ");
			scanf("%f", &temperatura);
		}

		printf("Ingrese genero ('f' para femenino, 'm' para masculino, 'o' para no binario): ");
		fflush(stdin);
		scanf("%c", &genero);
		genero = tolower(genero);
		while(genero != 'f' && genero != 'm' && genero != 'o'){
			printf("ERROR. Ingrese genero ('f' para femenino, 'm' para masculino, 'o' para no binario): ");
			fflush(stdin);
			scanf("%c", &genero);
			genero = tolower(genero);
		}

		// A) y D)
		if(edad > 60){
			contadorMayoresA60++;
			if(estadoCivil == 'v'){
				contadorViudosMayoresA60++;
				flagViudoMayorA60 = 0;
			}
		}

		// B)
		if(genero == 'f' && estadoCivil == 's'){
			if(flagPrimerMujer == 1){
				clienteSolteraMasJoven = numeroCliente;
				edadSolteraMasJoven = edad;
				flagPrimerMujer = 0;
			}
			else if(edad < edadSolteraMasJoven){
				clienteSolteraMasJoven = numeroCliente;
				edadSolteraMasJoven = edad;
			}
		}

		// C)
		totalSinDescuento += precioPorPasajero;

		// D)
		contadorPasajeros++;

		printf("Desea continuar ingresando datos? (S/N): ");
		fflush(stdin);
		scanf("%c", &continuar);
		continuar = tolower(continuar);
		//validacion de respuesta
		while(continuar != 's' && continuar != 'n'){
			printf("ERROR. Desea continuar ingresando numeros? (S/N): ");
			fflush(stdin);
			scanf("%c", &continuar);
			continuar = tolower(continuar);
		}
	} while (continuar == 's');

	if(flagViudoMayorA60 == 0){
		printf("Se ingresaron %d personas viudas mayores a 60 anios.\n", contadorViudosMayoresA60);
	}

	if(flagPrimerMujer == 0){
		printf("La mujer mas joven ingresada fue la cliente nro %d con una edad de %d anios.\n", clienteSolteraMasJoven, edadSolteraMasJoven);
	}

	printf("El precio final sin descuento es de $ %d.\n", totalSinDescuento);

	if(contadorPasajeros/2 < contadorMayoresA60){
		precioConDescuento = totalSinDescuento - (totalSinDescuento * descuento);
		printf("El precio final con descuento es de $ %d.\n", precioConDescuento);
	}

	return EXIT_SUCCESS;
}
