/*
 ============================================================================
 Name        : ApoyoEjercicio1-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
a. El promedio de los números positivos.
b. El promedio de los números negativos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL);

	char continuar = 's';
	int totalPos, totalNeg, contadorPos, contadorNeg, numIngresado;
	contadorPos = 0;
	contadorNeg = 0;
	totalPos = 0;
	totalNeg = 0;

	do {
		printf("Ingrese un numero: ");
		scanf("%d", &numIngresado);

		if (numIngresado < 0) {
			totalNeg = totalNeg + numIngresado;
			contadorNeg++;
		}
		else if (numIngresado > 0){
			totalPos = totalPos + numIngresado;
			contadorPos++;
		}

		printf("Desea continuar ingresando numeros? (S/N): ");
		fflush(stdin);
		scanf("%c", &continuar);
		continuar = tolower(continuar);

		while(continuar != 's' && continuar != 'n'){
			printf("ERROR. Desea continuar ingresando numeros? (S/N): ");
			fflush(stdin);
			scanf("%c", &continuar);
			continuar = tolower(continuar);
		}
	} while (continuar == 's');

	printf("\n\nTotal de numeros positivos: %d", totalPos);
	if(contadorPos != 0){
		float promedioPos;
		promedioPos = (float)totalPos / contadorPos;
		printf(" (promedio %.2f)", promedioPos);
	}

	printf("\nTotal de numeros negativos: %d", totalNeg);
	if(contadorNeg != 0){
		float promedioNeg;
		promedioNeg = (float)totalNeg / contadorNeg;
		printf(" (promedio %.2f)", promedioNeg);
	}

	printf("\n\nFin del programa\n");
	system("pause");

	return EXIT_SUCCESS;
}
