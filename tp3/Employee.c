#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Input.h"

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

int employee_setId(Employee* this,int id){
	int error = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		error = 0;
	}
	return error;
}

int employee_getId(Employee* this,int* id){
	int error = -1;
	if(this != NULL && id != NULL){
		*id = this->id;
		error = 0;
	}
	return error;
}

int employee_setNombre(Employee* this,char* name){
	int error = -1;
	if(this != NULL && name != NULL)
	{
//		if(inputString("nombre",name))
	//	{
			strcpy(this->name, name);
			error = 0;
		//}
	}
	return error;
}

int employee_getNombre(Employee* this,char* name){
	int error = -1;
	if(this != NULL && name != NULL){
		strcpy(name, this->name);
		error = 0;
	}
	return error;
}

int employee_setHorasTrabajadas(Employee* this,int workedHours){
	int error = -1;
	if(this != NULL && workedHours > 0)
	{
//		if(inputInt("horas trabajadas", workedHours))
	//	{
			this->workedHours = workedHours;
			error = 0;
		//}
	}
	return error;
}

int employee_getHorasTrabajadas(Employee* this,int* workedHours){
	int error = 1;
	if(this != NULL && workedHours != NULL){
		*workedHours = this->workedHours;
		error = 0;
	}
	return error;
}

int employee_setSueldo(Employee* this,int salary){
	int error = 1;
	if(this != NULL && salary > 0){
		this->salary = salary;
		error = 0;
	}
	return error;
}

int employee_getSueldo(Employee* this,int* salary){
	int error = 1;
	if(this != NULL && salary > 0){
		*salary = this->salary;
		error = 0;
	}
	return error;
}

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

void employee_delete(Employee* this){
	if(this != NULL){
		free(this);
	}
}

int printEmployees(LinkedList* list){
	int error = 1;
	int len = ll_len(list);
	Employee* auxEmp;

	if(!ll_isEmpty(list)){
		error = 0;
		for (int i = 0; i < len; i++)
		{
			auxEmp = (Employee*) ll_get(list, i);
			if ( auxEmp != NULL)
			{
				printEmployee(auxEmp);
			}
		}
		printf("\n");
	}

	return error;
}

int printEmployee(Employee* this){
	int error = 1;

	Employee emp;
	employee_getId(this, &emp.id);
	employee_getNombre(this, emp.name);
	employee_getHorasTrabajadas(this, &emp.workedHours);
	employee_getSueldo(this, &emp.salary);


	if(this != NULL){
		printf("id,nombre,horasTrabajadas,sueldo");
		printf("%d, %10s, %d, %d\n", emp.id, emp.name, emp.workedHours, emp.salary);
		error = 0;
	}

	return error;
}
