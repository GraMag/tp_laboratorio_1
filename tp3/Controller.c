#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int error = -1;
	FILE* file;

	if(path != NULL && (ll_isEmpty(pArrayListEmployee))) {
		file = fopen(path, "r");
		if(file != NULL){
			parser_EmployeeFromText(file,pArrayListEmployee);
		}
		fclose(file);
		error = 0;
	}
    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int error = -1;
	FILE* file;

	if(path != NULL && !(ll_isEmpty(pArrayListEmployee)))
	{
		file = fopen(path, "rb");
		parser_EmployeeFromBinary(file, pArrayListEmployee);
		fclose(file);
		error = 0;
	}
	return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;

//	if(pArrayListEmployee != NULL){
	//	ll_add(pArrayListEmployee,pepe);
	//}
    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{	int error = -1;
	int index;
	int option;
	Employee* auxEmp;
	char name[50];
	char auxName[50];
	int hours;
	int auxHours;
	int salary;
	int auxSalary;
	if(pArrayListEmployee != NULL){
		printf("Ingrese ID: ");
		scanf("%d", &index);
		auxEmp = ll_get(pArrayListEmployee, (index-1));
		if(ll_indexOf(pArrayListEmployee, auxEmp) != -1)
		{
			printf("Que parametro desea modificar?\n"
					"1.- Nombre\n"
					"2.- Horas trabajadas\n"
					"3.- Salario\n"
					"4.- Cancelar\n");
			scanf("%d", &option);

			switch(option)
			{
				case 1:

					printf("Ingrese nuevo nombre: ");
					fflush(stdin);
					gets(name);
					employee_getNombre(auxEmp, auxName);
					printf("Esta seguro que desea cambiar %s por %s?\n", auxName, name);
					printf( "1.- Si\n"
							"2.- No\n");
					scanf("%d", &option);
					if(option == 1)
					{
						employee_setNombre(auxEmp, name);
						printf("Nombre modificado con exito\n");
					}
					else
					{
						printf("No se realizaron cambios\n");
					}
					break;

				case 2:

					printf("Ingrese nueva cantidad de horas trabajadas: ");
					scanf("%d", &hours);
					employee_getHorasTrabajadas(auxEmp, &auxHours);
					printf("Esta seguro que desea cambiar %dhs por %dhs?\n", auxHours, hours);
					printf( "1.- Si\n"
							"2.- No\n");
					scanf("%d", &option);
					if(option == 1)
					{
						employee_setHorasTrabajadas(auxEmp, hours);
						printf("Horas trabajadas modificadas con exito\n");
					}
					else
					{
						printf("No se realizaron cambios\n");
					}
					break;

				case 3:

					printf("Ingrese nuevo salario: ");
					scanf("%d", &salary);
					employee_getSueldo(auxEmp, &auxSalary);
					printf("Esta seguro que desea cambiar $%d.00 por $%d.00?\n", auxSalary, salary);
					printf( "1.- Si\n"
							"2.- No\n");
					scanf("%d", &option);
					if(option == 1)
					{
						employee_setSueldo(auxEmp, salary);
						printf("Salario modificado con exito\n");
					}
					else
					{
						printf("No se realizaron cambios\n");
					}
					break;
				default:
					printf("No se realizaron cambios");
			}
		}
		error = 0;
	}

	return error;
}
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;
	int index;
	int option;
	Employee* auxEmp;

	if(pArrayListEmployee != NULL){
		printf("Ingrese ID: ");
		scanf("%d", &index);
		auxEmp = ll_get(pArrayListEmployee, (index-1));
		if(ll_indexOf(pArrayListEmployee, auxEmp) != -1)
		{
			printf("Esta seguro que desea eliminar?\n");
			printEmployee(auxEmp);
			printf( "1.- Si\n"
					"2.- No\n");
			scanf("%d", &option);
			if(option == 1)
			{
					ll_remove(pArrayListEmployee, index-1);
					printf("Empleado eliminado con exito\n");
			}
			else
			{
					printf("No se realizaron cambios\n");
			}
		}
		error = 0;
	}

    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;
	if(!ll_isEmpty(pArrayListEmployee)){
		printEmployees(pArrayListEmployee);
		error = 0;
	}
    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int error = -1;
	Employee* emp;
	Employee auxEmp;

	int len = ll_len(pArrayListEmployee);
	FILE* file;

	if(path != NULL && !(ll_isEmpty(pArrayListEmployee))) {
		file = fopen(path, "w");

		if(file != NULL)
		{
			printf("id,nombre,horasTrabajadas,sueldo");
			for(int i = 0; i < len; i++)
			{
				emp = (Employee*) ll_get(pArrayListEmployee, i);
				employee_getId(emp, &auxEmp.id);
				employee_getNombre(emp, auxEmp.name);
				employee_getHorasTrabajadas(emp, &auxEmp.workedHours);
				employee_getSueldo(emp, &auxEmp.salary);

				fprintf(file, "%d, %s, %d, %d\n", auxEmp.id, auxEmp.name, auxEmp.workedHours, auxEmp.salary);
			}

		}
		fclose(file);
		error = 0;
	}
    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int error = -1;
	FILE* file;
	//Employee* emp;

	if(path != NULL && !(ll_isEmpty(pArrayListEmployee))) {
		file = fopen(path, "wb");
	//	fwrite(emp, sizeof(Employee), 1, file);
		fclose(file);
		error = 0;
	}
    return error;
}

