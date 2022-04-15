/*
 ============================================================================
 Name        : ApoyoEjercicio2-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Facundo Berges


 Ejercicio 2.2
 Realizar un programa que permita el ingreso de 10 números enteros.
 Determinar el promedio de los positivos, la cantidad de ceros y del menor de los negativos la suma de los antecesores.

 Nota:
 Utilizar la función del punto anterior y desarrollar funciones para resolver los procesos que están resaltados.

 */

#include <stdio.h>
#include <stdlib.h>

int ValidarPositivo(int numero);
float PromediarEnteros(int total, int cantidad);
int SumarNegativos(int numeroNegativo);

int main(void) {
	int numeroIngresado;
	int sumaPositivos;
	int contadorPositivos;
	int contadorCeros;
	int flagPositivos;
	int flagNegativos;
	int menorNegativo;
	int totalSumaNegativos;
	float promedioPositivos;

	sumaPositivos = 0;
	contadorPositivos = 0;
	contadorCeros = 0;
	flagPositivos = 0;
	flagNegativos = 0;

	setbuf(stdout, NULL);

	int i;
	for(i = 0; i < 10; i++){
		printf("Ingrese un numero: ");
		scanf("%d", &numeroIngresado);

		if(ValidarPositivo(numeroIngresado) == 1)
		{
			flagPositivos = 1;
			sumaPositivos += numeroIngresado;
			contadorPositivos++;
		}
		else if(!(ValidarPositivo(numeroIngresado)))
		{
			contadorCeros++;
		}
		else
		{
			if(!(flagNegativos) || (flagNegativos && numeroIngresado < menorNegativo)){
				flagNegativos = 1;
				menorNegativo = numeroIngresado;
			}
		}
	}

	if(flagPositivos)
	{
		promedioPositivos = PromediarEnteros(sumaPositivos, contadorPositivos);
		printf("\nEl promedio de los numeros positivos ingresados (%d numeros con un total de %d) es %.2f.", contadorPositivos, sumaPositivos, promedioPositivos);
	}
	else
	{
		printf("\nNo se ingresaron numeros positivos.");
	}

	if(contadorCeros)
	{
		printf("\nSe ingresaron %d ceros.", contadorCeros);
	}
	else
	{
		printf("\nNo se ingresaron ceros.");
	}

	if(flagNegativos){
		totalSumaNegativos = SumarNegativos(menorNegativo);
		printf("\nLa suma de los numeros antecesores al menor numero negativo ingresado (%d) da como total %d.", menorNegativo, totalSumaNegativos);
	}
	else{
		printf("\nNo se ingresaron numeros negativos.");
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

float PromediarEnteros(int total, int cantidad){
	float promedio;

	promedio = (float) total / cantidad;

	return promedio;
}

int SumarNegativos(int numeroNegativo){
	int sumaNegativos = 0;

	int i;
	for(i = numeroNegativo+1; i < 0; i++){
		sumaNegativos += i;
	}

	return sumaNegativos;
}
