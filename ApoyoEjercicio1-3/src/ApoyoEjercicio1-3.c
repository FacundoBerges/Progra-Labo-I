/*
 ============================================================================
 Name        : ApoyoEjercicio1-3.c
 Author      : Facundo Berges
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de la UTN FRA, los datos solicitados son:
Legajo
Tipo cursada(L: "libre" - P: "presencial" – R: "remota")
Cantidad de materias( mas de cero y menos de 8)
Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
Nota promedio (entre 0 y 10)
Edad (validar)
Se debe informar de existir, o informar que no existe , en el caso que corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa más materias. (Sin importar su género)


 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {

	char cursada, sexo, continuar;
	int legajo, cantMaterias, edad, flagPrimerFemenino, legajoMejorPromedioFem, flagPrimerMasculinoLibre, legajoAlumnoLibreMasJoven, edadAlumnoLibreMasJoven, contadorMujeres, contadorVarones, flagPrimerIngreso, cantMasMaterias, edadMasMaterias, legajoMasMaterias;
	float notaPromedio, notaMejorPromedioFemenino, notaTotalVarones, notaTotalMujeres, promedioMasculino, promedioFemenino;

	continuar = 's';
	contadorMujeres = 0;
	contadorVarones = 0;
	flagPrimerFemenino = 1;
	flagPrimerIngreso = 1;
	flagPrimerMasculinoLibre = 1;
	notaTotalMujeres = 0;
	notaTotalVarones = 0;

	setbuf(stdout, NULL);

	while(continuar == 's'){
		printf("Ingrese legajo: ");
		scanf("%d", &legajo);

		printf("Ingrese tipo de cursada (L: 'libre' - P: 'presencial' – R: 'remota'): ");
		fflush(stdin);
		scanf("%c", &cursada);
		cursada = toupper(cursada);
		//validacion de respuesta
		while(cursada != 'L' && continuar != 'P' && continuar != 'R'){
			printf("ERROR. Ingrese tipo de cursada (L: 'libre' - P: 'presencial' – R: 'remota'): ");
			fflush(stdin);
			scanf("%c", &cursada);
			cursada = toupper(cursada);
		}

		printf("Ingrese cantidad de materias (mayor a 0 y menor a 8): ");
		scanf("%d", &cantMaterias);
		//validacion de respuesta
		while (cantMaterias >= 8 || cantMaterias <= 0){
			printf("ERROR. Ingrese cantidad de materias (mayor a 0 y menor a 8): ");
			scanf("%d", &cantMaterias);
		}

		printf("Ingrese sexo (F: 'femenino' – M: 'masculino' , O: 'no binario'): ");
		fflush(stdin);
		scanf("%c", &sexo);
		sexo = toupper(sexo);
		//validacion de respuesta
		while(sexo != 'F' && sexo != 'M' && sexo != 'O'){
			printf("ERROR. Ingrese sexo (F: 'femenino' – M: 'masculino' , O: 'no binario'): ");
			fflush(stdin);
			scanf("%c", &sexo);
			sexo = toupper(sexo);
		}

		printf("Ingrese nota promedio (entre 0 y 10): ");
		scanf("%f", &notaPromedio);
		//validacion de respuesta
		while (notaPromedio > 10 || notaPromedio < 0){
			printf("ERROR. Ingrese nota promedio (entre 0 y 10): ");
			scanf("%f", &notaPromedio);
		}

		printf("Ingrese edad: ");
		scanf("%d", &edad);
		//validacion de respuesta
		while (edad > 99 || edad < 17){
			printf("ERROR. Ingrese edad (entre 17 y 99 años): ");
			scanf("%d", &edad);
		}


		// A) y C)
		if(sexo == 'F'){
			contadorMujeres++;
			notaTotalMujeres += notaPromedio;
			if(flagPrimerFemenino == 0 && notaMejorPromedioFemenino < notaPromedio){
				notaMejorPromedioFemenino = notaPromedio;
				legajoMejorPromedioFem = legajo;
			}
			else if (flagPrimerFemenino == 1){
				flagPrimerFemenino = 0;
				notaMejorPromedioFemenino = notaPromedio;
				legajoMejorPromedioFem = legajo;
			}
		}

		// B) y C)
		if(sexo == 'M'){
			notaTotalVarones += notaPromedio;
			contadorVarones++;
			if(cursada == 'L'){
				if(flagPrimerMasculinoLibre == 1){
					flagPrimerMasculinoLibre = 0;
					edadAlumnoLibreMasJoven = edad;
					legajoAlumnoLibreMasJoven = legajo;
				}
				else if(edad < edadAlumnoLibreMasJoven){
					edadAlumnoLibreMasJoven = edad;
					legajoAlumnoLibreMasJoven = legajo;
				}
			}
		}

		// D)
		if(flagPrimerIngreso == 1){
			cantMasMaterias = cantMaterias;
			edadMasMaterias = edad;
			legajoMasMaterias = legajo;
			flagPrimerIngreso = 0;
		}
		else if (flagPrimerIngreso == 0 && cantMaterias > cantMasMaterias){
			cantMasMaterias = cantMaterias;
			edadMasMaterias = edad;
			legajoMasMaterias = legajo;
		}


		printf("Desea continuar ingresando alumnos? (S/N): ");
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
	}

	printf("\n");

	if(flagPrimerFemenino == 0){
		printf("El legajo del mejor promedio femenino es %d.\n", legajoMejorPromedioFem);
	}
	else{
		printf("No se ingresaron mujeres.\n");
	}

	if(flagPrimerMasculinoLibre == 0){
		printf("El legajo del alumno varon mas joven que da libre es %d.\n", legajoAlumnoLibreMasJoven);
	}
	else{
		printf("No se ingresaron varones que den libre.\n");
	}

	if(contadorMujeres != 0){
		promedioFemenino = (float) notaTotalMujeres / contadorMujeres;
		printf("El promedio de notas de las mujeres ingresadas es %.2f.\n", promedioFemenino);
	}
	else{
		printf("No se ingresaron mujeres.\n");
	}

	if(contadorVarones != 0){
		promedioMasculino = (float) notaTotalVarones / contadorVarones;
		printf("El promedio de notas de los varones ingresados es %.2f.\n", promedioMasculino);
	}
	else{
		printf("No se ingresaron varones.\n");
	}

	printf("El legajo de quien cursa mas materias es %d y tiene %d a%cos.\n\n", legajoMasMaterias, edadMasMaterias, 164);


	return EXIT_SUCCESS;
}
