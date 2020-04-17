#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"


/**
 * @brief Pide al usuario un numero y validad que lo sea.
 *
 * @param something mensaje personalizado sobre el numero que se desea pedir
 * @param error mensaje personalizado de error en caso de que no se ingrese un numero
 * @return
 */

int addNum (char something[], char error[]) {

	int num;
	int checknum;

	setbuf(stdout,NULL);
	printf("%s: \n", something);
	checknum = scanf("%d", &num);
	fflush(stdin);

	while(checknum == 0) {
		printf("%s: \n", error);
		checknum = scanf("%d", &num);
		fflush(stdin);
	}
	return num;
}


/** @brief suma dos numeros enteros
 *
 * 	@param num1 primer numero ingresado por el usuario
 *  @param num2 segundo numero ingresado por el usuario
 *  @return devuelve la suma de los numeros
 *
 */

int sum (int num1, int num2) {

	return num1 + num2;
}


/** @brief resta de dos numeros enteros
 *
 *  @param num1 primer numero ingresado por el usuario
 *  @param num2 segundo numero ingresado por el usuario
 *  @return devuelve la resta de los numeros
 *
 */

int substrac (int num1, int num2) {

	return num1 - num2;
}


/** @brief multiplicacion de dos numeros enteros
 *
 *  @param  num1 primer numero ingresado por el usuario
 *  @param  num2 segundo numero ingresado por el usuario
 *  @return devuelve la multiplicacion de los numeros
 */

int multiply (int num1, int num2) {

	return num1 * num2;
}


/** @brief division de dos numeros enteros
 *
 *  @param  num1 primer numero ingresado por el usuario
 *  @param  num2 segundo numero ingresado por el usuario
 *  @return devuelve la division de los numeros
 */

float divide (int num1, int num2) {

	return (float) num1 / num2;;
}


/** @brief factorial de un numero
 *
 * @param num toma el numero ingresado por el usuario
 * @return devuelve el factorial del numero
 */

int factorial (int num) {

	int fact;
	int i;
	fact = 1;

	for (i = 1; i <= num; ++i) {
			fact =  fact * i;
		}

	return fact;
}


/**	@brief muestra el resultado de todas las operaciones
 *
 *  @param  num1 primer numero ingresado por el usuario
 *  @param  num2 segundo numero ingresado por el usuario
 */

void message (int num1, int num2) {

	printf("El resultado de %d mas %d es igual a %d\n", num1, num2, sum(num1, num2));
	printf("El resultado de %d menos %d es igual a %d\n", num1, num2, substrac(num1, num2));
	printf("El resultado de %d multiplicado %d es igual a %d\n", num1, num2, multiply(num1, num2));

	if (num2 == 0)
	{
		printf("Error. No se puede dividir %d por 0\n", num1);
	} else {
		printf("El resultado de %d dividido %d es igual a %.2f\n", num1, num2, divide(num1, num2));
	}

	if (num1 < 0)
	{
		printf("Error. No se puede calcular el factorial de un numero negativo (%d)\n", num1);
	}
	else
	{
		printf("El factorial de %d es %d\n", num1, factorial(num1));
	}

	if (num2 < 0)
	{
		printf("Error. No se puede calcular el factorial de un numero negativo (%d)\n", num2);
	}
	else
	{
		printf("El factorial de %d es %d\n", num2, factorial(num2));
	}

	printf("\nLos operadores se han reiniciado.\n\n");
}

