#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main(void) {

	int num1;
	int num2;
	int num1ready = 0; //flag
	int num2ready = 0; //flag
	int step3 = 0; // flag
	int option;

	setbuf(stdout,NULL);

	do {
		// Limpiar pantalla
		system("cls");

		// Menu
		printf("\n--- Menu --- \n\n");
		printf("Por favor, seleccione una opcion:\n");
		if (num1ready == 0)
		{
			printf("1- Ingrese el primer operando. (A = X) \n");
		}
		else
		{
			printf("1- Ingrese el primer operando. (A = %d) \n", num1);
		}
		if (num2ready == 0)
		{
			printf("2- Ingrese el segundo operando. (B = Y) \n");
		}
		else
		{
			printf("2- Ingrese el segundo operando. (B = %d) \n", num2);
		}
		printf("3- Calcular todas las operaciones.\n");
		printf("4- Informar resultados.\n");
		printf("5- Salir.\n");

		fflush(stdin);

		scanf("%d", &option);

		switch (option) {
			case 1:
				if (num1ready == 0) {
					num1 = addNum("Ingrese un numero", "Valor invalido. Ingrese un numero");
					num1ready++;
				} else {
					printf("Ya se ha ingresado el numero %d", num1);
				}
				break;
			case 2:
				if (num2ready == 0) {
					num2 = addNum("Ingrese un numero", "Valor invalido. Ingrese un numero");
					num2ready++;
				} else {
					printf("Ya se ha ingresado el numero %d", num2);
				}
				break;
			case 3:
				if (num1ready == 0 && num2ready == 0)
				{
					printf("Aun no ha ingresado ningun operando.\n\n");
				}
				else if (num1ready == 0) {
					printf("Aun no ha ingresado el primer operando\n\n");
				}
				else if (num2ready == 0)
				{
					printf("Aun no ha ingresado el segundo operando.\n\n");
				}
				else
				{
					printf("Realizando operaciones\n... ... ... \n"
							"Operaciones realizadas con exito.\n\n");
					step3++;
				}
				break;
			case 4:
				if (num1ready == 0 && num2ready == 0)
				{
					printf("Aun no ha ingresado ningun operador.\n\n");
				}
				else if (num1ready == 0)
				{
					printf("Aun no ha ingresado el primer operando\n\n");
				}
				else if (num2ready == 0)
				{
					printf("Aun no ha ingresado el segundo operando.\n\n");
				}
				else if (step3 == 0)
				{
					printf("Aun no se han calculado las operaciones.\n\n");
				}
				else
				{
					message(num1, num2);
					// Reset
					num1ready = 0;
					num2ready = 0;
					step3 = 0;
				}
				break;
			case 5:
				exit(-1);
				break;
			default:
				printf("Opcion invalida.\n\n");
				break;
		}

		// Evita que el mensaje se borre antes de que el usuario lo vea
		if (option != 5)
		{
			system("pause");
		}
	} while (option != 5);

	return EXIT_SUCCESS;
}
