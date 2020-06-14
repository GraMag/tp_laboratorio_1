#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menues.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int seguir = 0;

    LinkedList* listEmployees = ll_newLinkedList();

    initEmployees(listEmployees);

    do{
    	system("cls");
        switch(mainMenue())
        {
            case 1:
            	if(controller_loadFromText("data.csv", listEmployees))
            	{
            	   	printf("Error al cargar el archivo\n");
               	}
            	else
            	{
              		printf("Archivo cargado correctamente\n");
             	}
            	break;
			case 2:
				if (controller_loadFromBinary("data.bin", listEmployees)) {
					printf("Error al cargar el archivo\n");
				}
				else
				{
					printf("Archivo cargado correctamente\n");
				}
				break;
			case 6:
				if (controller_ListEmployee(listEmployees))
				{
					printf("No hay datos que mostrar\n");   // 1
				}
				else
				{
					printf("Listado ok\n"); // 0
				}
				break;
			case 8:
				if (controller_saveAsText("dataBackup.csv", listEmployees)) { // CAMBIAR EL NOMBRE DEL ARCHIVO
					printf("Error al guardar el archivo\n");
				}
				else
				{
					printf("Archivo guardado correctamente\n");
				}
				break;
			case 9:
				if (controller_saveAsBinary("data.bin", listEmployees)) {
					printf("Error al guardar el archivo\n");
				}
				else
				{
					printf("Archivo guardado correctamente\n");
				}
				break;
			case 10:
				exit(-1);
		}

        system("pause");
    }while(seguir == 0);

    return 0;
}

