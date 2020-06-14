#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


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
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
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
	int index;

	printf("Ingrese ID");
	scanf("%d", &index);



    return 1;
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

