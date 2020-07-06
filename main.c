#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menues.h"

int main()
{
	setbuf(stdout,NULL);
    int seguir = 0;
    int readytxt = 0;
    int readybin = 0;
    int savedTxt = 0;
    int savedBin = 0;
    LinkedList* listEmployees = ll_newLinkedList();

    initEmployees(listEmployees);

    do
    {
    	system("cls");
        switch(mainMenue())
        {
            case 1:
            	if(!readytxt)
				{
					if(controller_loadFromText("data.csv", listEmployees))
					{
						printf("Error al cargar el archivo\n");
					}
					else
					{
						printf("Archivo cargado correctamente\n");
						readytxt = 1;
					}
				}
            	else
            	{
            		printf("El archivo ya esta cargado\n");
            	}
            	break;
			case 2:
				if(!readybin)
				{
					if (controller_loadFromBinary("data.bin", listEmployees)) {
						printf("Error al cargar el archivo\n");
					}
					else
					{
						printf("Archivo cargado correctamente\n");
						readybin = 1;
					}
				}
				break;
			case 3:
				if(readytxt || readybin)
				{
					if (controller_addEmployee(listEmployees))
					{
						printf("No se pudo agregar al empleado.\n");
					}
					else
					{
						printf("Empleado guardado con exito\n");
						savedBin = 0;
						savedTxt = 0;
					}
				}
				else
				{
					printf("Aun no se cargo el archivo\n");
				}
				break;
			case 4:
				if(readytxt || readybin)
				{
					if (controller_editEmployee(listEmployees))
					{
						printf("No hay datos que mostrar\n");
					}
					else
					{
						savedBin = 0;
						savedTxt = 0;
					}
				}
				else
				{
					printf("Aun no se cargo el archivo\n");
				}
				break;
			case 5:
				if(readytxt || readybin)
				{
					if (controller_removeEmployee(listEmployees))
					{
						printf("No hay datos que mostrar\n");
					}
					else
					{
						savedBin = 0;
						savedTxt = 0;
					}
				}
				else
				{
					printf("Aun no se cargo el archivo\n");
				}
				break;
			case 6:
				if(readytxt || readybin)
				{
					if (controller_ListEmployee(listEmployees))
					{
						printf("No hay datos que mostrar\n");
					}
				}
				else
				{
					printf("Aun no se cargo el archivo\n");
				}
				break;
			case 7:
				if(readytxt || readybin)
				{
					if (controller_sortEmployee(listEmployees))
					{
						printf("No se realizaron cambios\n");
					}
					else
					{
						printf("Listado ok\n");
						savedBin = 0;
						savedTxt = 0;
					}
				}
				else
				{
					printf("Aun no se cargo el archivo\n");
				}
				break;
			case 8:
				if(readytxt || readybin)
				{
					if (controller_saveAsText("data.csv", listEmployees)) {
						printf("Error al guardar el archivo\n");
					}
					else
					{
						printf("Archivo guardado correctamente\n");
						savedTxt = 1;
					}
				}
				else
				{
					printf("Aun no se cargo el archivo\n");
				}
				break;
			case 9:
				if(readybin || readytxt)
				{
					if (controller_saveAsBinary("data.bin", listEmployees)) {
						printf("Error al guardar el archivo\n");
					}
					else
					{
						printf("Archivo guardado correctamente\n");
						savedBin = 1;
					}
				}
				else
				{
					printf("Aun no se cargo el archivo\n");
				}
				break;
			case 10:
				if(!savedTxt && !savedBin)
				{
					if(exitMenue() == 1)
					{
						exit(-1);
					}
				}
				else
				{
					exit(-1);
				}
				break;
			default:
				printf("Error: opcion invalida.\n");
				break;
		}
        system("pause");
    } while(seguir == 0);

    return 0;
}
