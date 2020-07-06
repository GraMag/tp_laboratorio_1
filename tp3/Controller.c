#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int [-1] NULL file or list [0] OK
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
 * \return int [-1] NULL file or list [0] OK
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int error = -1;
	FILE* file;

	if(path != NULL && (ll_isEmpty(pArrayListEmployee)))
	{
		file = fopen(path, "rb");
		if(file != NULL)
		{
			parser_EmployeeFromBinary(file, pArrayListEmployee);

		}
		fclose(file);
		error = 0;
	}
	return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int [-1] NULL list or invalid employee [0] OK
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;

	if(pArrayListEmployee != NULL){
		error = employee_ask(pArrayListEmployee);
	}
    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int [-1] NULL list [0] OK
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;

	if(pArrayListEmployee != NULL){
		employee_modify(pArrayListEmployee);
		error = 0;
	}

	return error;
}
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int [-1] NULL list[0] OK
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;
	int index;

	if(pArrayListEmployee != NULL)
	{
		printf("Ingrese ID: ");
		scanf("%d", &index);
		employee_remove(pArrayListEmployee, index);
		error = 0;
	}

    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int [-1] NULL list[0] OK
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
 * \return int [-1] NULL list[0] OK
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int error = -1;

	if(pArrayListEmployee != NULL)
	{
		if(employee_Sortby(pArrayListEmployee))
		{
			error = -1;
		}
		else
		{
			error = 0;
		}
	}
    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int [-1] NULL list or File [0] OK
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
			fprintf(file, "id,nombre,horasTrabajadas,sueldo");
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
 * \return int [-1] NULL list or File [0] OK
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int error = -1;
	FILE* file;
	Employee* emp;
	int len = ll_len(pArrayListEmployee);

	if(path != NULL && !(ll_isEmpty(pArrayListEmployee))) {
		file = fopen(path, "wb");

		if(file != NULL)
		{
			for(int i = 0; i < len; i++)
			{
				emp = (Employee*) ll_get(pArrayListEmployee, i);
				fwrite(emp, sizeof(Employee), 1, file);
			}
		}
		fclose(file);
		error = 0;
	}
    return error;
}

