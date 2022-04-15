/*
 ============================================================================
 Name        : clase7.c
 Author      : Facundo Berges
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN 5

int main(void) {
	int vector[LEN] = {5, 8, 2, 9, 3};

	int i, j, aux;
	for (i=0; i < LEN-1; i++){
		for(j=i+1; j < LEN; j++){
			if(vector[j] < vector[i]){
				aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;
			}
		}
	}

	for(i=0; i < LEN; i++){
		printf("%d ", vector[i]);

	}

	return EXIT_SUCCESS;
}

/*
 * https://www.onlinegdb.com/nWsSADmQm
 *
 *
 * Array de caracteres
 *
 * No existe el tipo de dato string en C.
 * La unica forma de simularlo es a traves de un vector de caracteres.
 * Las funciones se encuentran en la biblioteca <string.h>
 *
 * char caracter; //--> caracter
 * char cadena[cantidadDeCaracteres] = "Programacion"; //--> string
 * // char cadenaZ[] = "programacion" //debemos intentar de declarar siempre cantidad de numeros, o hacerl ode forma pseudodinamica declarandolo ni bien lo inicializamos.
 * //cadena = "programacion"; --> no se puede poner ya que C no conoce el concepto de palabra o cadena de caracteres.
 *
 *
 * printf("%s", cadenas);
 * puts(cadena);  //putString
 *
 *
 * //Forma de pedir una cadena al usuario
 * printf("Ingrese una cadena: ");
 * fflush(stdin);
 * scanf("%s", cadena); //Sin & ya que el nombre de un array representa la direccion de memoria del primer elemento.
 *
 * Si ingresamos espacios al ingresar una cadena, el scanf toma solo la informacion hasta el primer espacio (palabra).
 * La secuencia de escape o bandera que provoca esto es \0
 * Esta secuencia separa del array la informacion real cargada de lo que resta como basura.
 * Esto significa que el \0 ocupa un lugar del array, por lo que teniendo un array de 10 caracteres, 9 son utiles realmente ya que si colocaramos 10, desbordariamos el array.
 *
 * Se puede solucionar el problema del scanf reemplazandolo por gets (get string o get cadena).
 *
 * printf("Ingrese una cadena: ");
 * fflush(stdin);
 * gets(cadena);
 *
 * Sin embargo, esto tiene un problema. Solo funciona para WINDOWS. LINUX usa fgets.
 *
 * Podemos crear nuestra propia mascara escribiendo:
 * scanf("%[^\n]", cadena); //--> de esta forma le decimos al sistema que omita el \0.
 *
 *
 * Para conocer la cantidad de caracteres utiles en una cadena, utilizamos la funcion strlen.
 *
 * strlen(nombreArray); //una variable = char* || char[]
 * o
 * int len;
 * len = strlen("una cadena"); // un literal = const char*
 * Sirve para validar que el usuario se paso de datos en un array de char.
 * Tambien se puede utilizar para
 *
 *
 * char otraCadena[20];
 * // otraCadena = cadenas; --> no existe ya que no sabe asignar un vector a otro.
 * Debemos utilizar la funcion strcpy (string copy).
 *
 * strcpy(otraCadena, cadenas);
 * strcpy(otraCadena, "Un literal"); //strcpy(char*, const char*)
 *
 * puts(otraCadena);
 *
 * strcmp sirve para comparar strings y ordenarlos segun la comparacion de ascii de sus valores en letra.
 * devuelve como resultado la cantidad de letras de diferencia entre un caracter y otro.
 *
 * int comp;
 * comp = strcmp("zapallo", "Zapallo");
 * printf("%d", comp);
 *
 * stricmp o strcmpi comparan la letra sin importar la diferencia ascii entre las mayusculas y minusculas.
 * Ignora el case sensitive.
 *
 * comp = strcmpi("zapallo", "Zapallo");
 * printf("%d", comp);
 *
 *
 * para convertir todo a mayuscula o minuscula:
 * char otraCadena[20] = "laboratorio I";
 * puts(otraCadena);
 *
 * strupr(otraCadena); //--> SOLO EXISTE PARA WINDOWS. Funciona como el ToUpper (edita sobre la cadena de caracteres original);
 * puts(otraCadena);
 *
 * strlwr(otraCadena); //--> SOLO EXISTE PARA WINDOWS. Funciona como el ToLower (edita sobre la cadena de caracteres original);
 * puts(otraCadena);
 *
 *
 * strcat es la funcion para concatenar.
 *
 * strcat(otraCadena, cadena); //solo contatena de a pares: destino, origen.
 * puts(otraCadena);
 *
 * averiguar las funciones isspace, isdigit e isalpha.
 * hasta ejercicio 6.3
 *
 *
 */
