#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"

#define LEN 1000

int main(void) {

	sEmployee employees[LEN];
	int nextID = 0000;
	char repeat = 's';
	int readyStep1 = 0;

	setbuf(stdout, NULL);

	initEmployees(employees, LEN);

	printf("*** BIENVENIDO ***\n\n");

	do
	{
		system("cls");
		fflush(stdin);

		switch(menue("Por favor, seleccione una opcion:\n\n"
					"1.- Alta empleado\n"
					"2.- Modificar empleado\n"
					"3.- Baja empelado\n"
					"4.- Informar\n"
					"5.- Salir\n"))
		{
			case 1:
				if(!(askData(employees, LEN, nextID)))
				{
					nextID++;
					readyStep1 = 1;
				}
				break;
			case 2:
				if(!(noEmployee(readyStep1)))
				{
					modifyEmployee(employees, LEN);
				}
				break;
			case 3:
				if (!(noEmployee(readyStep1)))
				{
					removeEmployee(employees, LEN, inputInt("ID"));
				}
				break;
			case 4:
				if(!(noEmployee(readyStep1)))
				{
					requestInfo(employees, LEN);
				}
				break;
			case 5:
				printf("Salir");
				repeat = 'n';
				break;
			default:
				printf("No es una opcion valida.\n");
		}

		system("pause");

	} while (repeat == 's');

	return EXIT_SUCCESS;
}
