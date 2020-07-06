#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Menues.h"


int mainMenue(){
	int option;

	printf("****************************************************\n"
			"Menu:\n"
			"1. Cargar los datos de los empleados desde el archivo data.csv\n"
			"2. Cargar los datos de los empleados desde el archivo data.bin\n"
			"3. Alta de empleado\n"
			"4. Modificar datos de empleado\n"
			"5. Baja de empleado\n"
			"6. Listar empleados\n"
			"7. Ordenar empleados\n"
			"8. Guardar los datos de los empleados en el archivo data.csv\n"
			"9. Guardar los datos de los empleados en el archivo data.bin\n"
			"10. Salir\n"
			"*****************************************************\n\n"
			"Seleccione una opcion: ");
	scanf("%d", &option);

	return option;
}

int modifyMenue()
{
	int option;
	printf("Que parametro desea modificar?\n"
			"1.- Nombre\n"
			"2.- Horas trabajadas\n"
			"3.- Salario\n"
			"4.- Cancelar\n");
	scanf("%d", &option);

	return option;
}

int removeMenue(Employee* emp)
{
	int option;

	printf("Esta seguro que desea eliminar?\n");
	printEmployee(emp);
	printf( "1.- Si\n"
			"2.- No\n");
	scanf("%d", &option);

	return option;
}

int sortMenue()
{
	int option;
	printf("Ordenar por:\n"
			"1.- ID\n"
			"2.- Nombre\n"
			"3.- Horas trabajadas\n"
			"4.- Salario\n"
			"5.- Cancelar\n");
	scanf("%d", &option);
	return option;
}

int orderMenue()
{
	int option;
	printf("Modo:\n"
			"1.- Ascendente\n"
			"2.- Descentende\n");
	scanf("%d", &option);
	return option;
}

int exitMenue()
{
	int option;
	printf("Aun no se guardo el archivo\n"
			"Salir sin guardar?\n"
			"1. Si\n"
			"2. No\n");
	scanf("%d", &option);
	return option;
}
