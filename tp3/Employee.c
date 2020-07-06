#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Input.h"
#include "Menues.h"


/**
 * @brief creates a new employee without parameters
 *
 * @return Employee
 */

Employee* employee_new(){

	Employee* newEmployee = (Employee*) malloc (sizeof(Employee));
	if(newEmployee != NULL)
	{
		newEmployee->id = 0;
		strcpy(newEmployee->name, "");
		newEmployee->workedHours = 0;
		newEmployee->salary = 0;
	}
	else
	{
		free(newEmployee);
		newEmployee = NULL;
	}
	return newEmployee;
}

/**
 * @brief creates a new employee with parameters
 *
 * @param idStr
 * @param nameStr
 * @param workedHoursStr
 * @param salaryStr
 * @return Employee
 */

Employee* employee_newParametros(char* idStr, char* nameStr, char* workedHoursStr, char* salaryStr){

	Employee* newEmployee = (Employee*) malloc (sizeof(Employee));
	newEmployee = employee_new();
	if(newEmployee != NULL)
	{
		employee_setId(newEmployee, atoi(idStr));
		employee_setNombre(newEmployee, nameStr);
		employee_setHorasTrabajadas(newEmployee, atoi(workedHoursStr));
		employee_setSueldo(newEmployee, atoi(salaryStr));
	}
	else
	{
		free(newEmployee);
		newEmployee = NULL;
	}
	return newEmployee;
}

/**
 * @brief set employee's ID
 *
 * @param this
 * @param id
 * @return int [-1] if the list is NULL or ID is lower than 0. [0] OK
 */

int employee_setId(Employee* this,int id){
	int error = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		error = 0;
	}
	return error;
}

/**
 * @brief get employee's ID
 *
 * @param this
 * @param id
 * @return int [-1] if the list is NULL or ID is NULL. [0] OK
 */
int employee_getId(Employee* this, int* id){
	int error = -1;
	if(this != NULL && id != NULL){
		*id = this->id;
		error = 0;
	}
	return error;
}

/**
 * @brief set employee's name
 *
 * @param this
 * @param name
 * @return int [-1] if the list is NULL or name is NULL. [0] OK
 */
int employee_setNombre(Employee* this,char* name){
	int error = -1;
	if(this != NULL && name != NULL)
	{
		strcpy(this->name, name);
		error = 0;
	}
	return error;
}

/**
 * @brief gets employee's name
 *
 * @param this
 * @param name
 * @return int [-1] if the list is NULL or name is NULL. [0] OK
 */
int employee_getNombre(Employee* this,char* name){
	int error = -1;
	if(this != NULL && name != NULL)
	{
		strcpy(name, this->name);
		error = 0;
	}
	return error;
}

/**
 * @brief set employee's worked hours
 *
 * @param this
 * @param workedHours
 * @return int [-1] if the list is NULL or worked hours NULL. [0] OK
 */
int employee_setHorasTrabajadas(Employee* this,int workedHours){
	int error = -1;
	if(this != NULL && workedHours > 0)
	{
		{
			this->workedHours = workedHours;
			error = 0;
		}
	}
	return error;
}

/**
 * @brief gets employee's worked hours
 *
 * @param this
 * @param workedHours
 * @return int [-1] if the list is NULL or worked hours is NULL. [0] OK
 */
int employee_getHorasTrabajadas(Employee* this,int* workedHours){
	int error = 1;
	if(this != NULL && workedHours != NULL){
		*workedHours = this->workedHours;
		error = 0;
	}
	return error;
}

/**
 * @brief set employee's salary
 *
 * @param this
 * @param salary
 * @return int [-1] if the list is NULL or salary is NULL. [0] OK
 */
int employee_setSueldo(Employee* this,int salary){
	int error = 1;
	if(this != NULL && salary > 0){
		this->salary = salary;
		error = 0;
	}
	return error;
}

/**
 * @brief get's employee's salary
 *
 * @param this
 * @param salary
 * @return int [-1] if the list is NULL or salary is NULL. [0] OK
 */
int employee_getSueldo(Employee* this,int* salary){
	int error = 1;
	if(this != NULL && salary > 0){
		*salary = this->salary;
		error = 0;
	}
	return error;
}

/**
 * @brief initialize employees as NULL
 *
 * @param list
 * @return [0] ok
 */
int initEmployees(LinkedList* list)
{
	int len = ll_len(list);
	Employee* emp;
	if(!(ll_isEmpty(list)))
	{
		for (int i = 0; i < len; i++)
		{
			emp = NULL;
			ll_set(list, i, emp);
		}
	}
	return 0;
}

/**
 * @brief increase id by 1
 *
 * @return int id
 */
int nextID(LinkedList* list)
{
	int id = ll_len(list)+1;
	return id;
}

/**
 * @brief ask user the info for the new employee, if ok its added to the list
 *
 * @param list
 * @return int [-1] Invalid information. [0] OK
 */
int employee_ask(LinkedList* list)
{
	int error = -1;
	char auxID[10];
	char auxName[128];
	char auxHours[10];
	char auxSalary[10];

	if(!askForString("nombre", auxName, 127) && !askForIntAsString("horas trabajadas", auxHours, 10) && !askForIntAsString("salario", auxSalary, 10))
	{
		Employee* emp;
		emp = employee_newParametros(itoa(nextID(list), auxID, 10), auxName, auxHours, auxSalary);
		ll_add(list, emp);
		error = 0;
	}
	return error;
}

/**
 * @brief modifies a parameter of an employee
 *
 * @param listint [-1]
 * @return int [-1] Null list [0] ok
 */
int employee_modify(LinkedList* list)
{
	int error = -1;
	int index;
	int option;
	Employee* auxEmp;
	char name[50];
	char auxName[50];
	int hours;
	int auxHours;
	int salary;
	int auxSalary;
	if(list != NULL){
		printf("Ingrese ID: ");
		scanf("%d", &index);
		auxEmp = ll_get(list, (index-1));
		if(ll_indexOf(list, auxEmp) != -1)
		{
			switch(modifyMenue())
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

/**
 * @brief removes an employee
 *
 * @param list
 * @param index
 * @return int [-1] Null list [0] ok
 */
int employee_remove(LinkedList* list, int index)
{
	int error = -1;
	Employee* auxEmp;

	if(list != NULL){
		auxEmp = ll_get(list, (index-1));
		if(ll_indexOf(list, auxEmp) != -1)
		{
			if(removeMenue(auxEmp) == 1)
			{
				ll_remove(list, index-1);
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

/**
 * @brief list employees
 *
 * @param list
 * @return int [-1] Null list [0] ok
 */
int printEmployees(LinkedList* list){
	int error = 1;
	int len = ll_len(list);
	Employee* auxEmp;

	if(!ll_isEmpty(list)){
		error = 0;
		printf("id,nombre,horasTrabajadas,sueldo\n");
		for (int i = 0; i < len; i++)
		{
			auxEmp = (Employee*) ll_get(list, i);
			if ( auxEmp != NULL)
			{
				printEmployee(auxEmp);
			}
		}
	}

	return error;
}

/**
 * @brief prints employee
 *
 * @param this
 * @return int [-1] Null list [0] ok
 */
int printEmployee(Employee* this){
	int error = 1;

	Employee emp;
	employee_getId(this, &emp.id);
	employee_getNombre(this, emp.name);
	employee_getHorasTrabajadas(this, &emp.workedHours);
	employee_getSueldo(this, &emp.salary);


	if(this != NULL){
		printf("%d, %-s, %d, %d\n", emp.id, emp.name, emp.workedHours, emp.salary);
		error = 0;
	}

	return error;
}

/**
 * @brief compares employees names
 *
 * @param name1
 * @param name2
 * @return int [0] are equals, [1] name1 goes before name 2, [-1] name1 goes after name2
 */
int sortByName(void *name1, void* name2)
{
	char auxName1[128];
	char auxName2[128];

	employee_getNombre(name1, auxName1);
	employee_getNombre(name2, auxName2);

	int order = 0;
	if(strcmp(auxName1, auxName2) > 0)
	{
		order = 1;
	}
	else if (strcmp(auxName1, auxName2) < 0)
	{
		order = -1;
	}

	return order;
}

/**
 * @brief compares employees salaries
 *
 * @param salary1
 * @param salary2
 * @return int [0] are equals, [1] salary1 is higher than salary2, [-1] salary1 is lower than salary2
 */
int sortBySalary(void *salary1, void* salary2)
{
	int auxsalary1;
	int auxsalary2;
	int order = 0;

	employee_getSueldo(salary1, &auxsalary1);
	employee_getSueldo(salary2, &auxsalary2);

	if(auxsalary1 > auxsalary2)
	{
		order = 1;
	}
	else if (auxsalary1 < auxsalary2)
	{
		order = -1;
	}

	return order;
}

/**
 * @brief compares employees worked hours
 *
 * @param hours1
 * @param hours2
 * @return int [0] are equals, [1] hours1 is higher than hours2, [-1] hours1 is lower than hours2
 */
int sortByHours(void *hours1, void* hours2)
{
	int auxhours1;
	int auxhours2;
	int order = 0;

	employee_getHorasTrabajadas(hours1, &auxhours1);
	employee_getHorasTrabajadas(hours2, &auxhours2);

	if(auxhours1 > auxhours2)
	{
		order = 1;
	}
	else if (auxhours1 < auxhours2)
	{
		order = -1;
	}

	return order;
}

/**
 * @brief compares employees worked hours
 *
 * @param id1
 * @param id2
 * @return int [1] id1 is higher than id2, [-1] id1 is lower than id2
 */
int sortById(void *id1, void* id2)
{
	int auxID1;
	int auxID2;
	int order;
	employee_getId(id1, &auxID1);
	employee_getId(id2, &auxID2);

	if(auxID1 > auxID2)
	{
		order = 1;
	}
	else if (auxID1 < auxID2)
	{
		order = -1;
	}

	return order;
}

/**
 * @brief sort employees by id, name, salary or hours
 *
 * @param list
 * @return int[-1] null list, [0] ok.
 */
int employee_Sortby(LinkedList* list)
{
	int error = -1;
	int order;
	if(list != NULL)
	{
		error = 0;
		switch (sortMenue()) {
			case 1:
				order = orderMenue();
				if(order == 1)
				{
					printf("Ordenando...\n");
					ll_sort(list, sortById, 1);
				}
				else if(order == 2)
				{
					printf("Ordenando...\n");
					ll_sort(list, sortById, 0);
				}
				break;
			case 2:
				order = orderMenue();
				if(order == 1)
				{
					printf("Ordenando...\n");
					ll_sort(list, sortByName, 1);
				}
				else if(order == 2)
				{
					printf("Ordenando...\n");
					ll_sort(list, sortByName, 0);
				}
				break;
			case 3:
				order = orderMenue();
				if(order == 1)
				{
					printf("Ordenando...\n");
					ll_sort(list, sortByHours, 1);
				}
				else if(order == 2)
				{
					printf("Ordenando...\n");
					ll_sort(list, sortByHours, 0);
				}
				break;
			case 4:
				order = orderMenue();
				if(order == 1)
				{
					printf("Ordenando...\n");
					ll_sort(list, sortBySalary, 1);
				}
				else if(order == 2)
				{
					printf("Ordenando...\n");
					ll_sort(list, sortBySalary, 0);
				}
				break;
			default:
				error = -1;
		}
		if (order != 1 && order != 2)
		{
			printf("Opcion invalida. ");
			error = -1;
		}
	}
	return error;
}
