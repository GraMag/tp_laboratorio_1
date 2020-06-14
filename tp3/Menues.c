#include <stdio.h>
#include <stdlib.h>
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
	scanf("%d\n", &option);

	return option;
}

