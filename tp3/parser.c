#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int error = 0;
	char buffer[4][128];
	int amount;
	Employee* auxEmp;
	Employee emp;

	fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]); // Encabezado
	printf("%s, %s, %s, %s\n", buffer[0], buffer[1], buffer[2], buffer[3]);
	while (!feof(pFile))
	{
		amount = fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]", buffer[0], buffer[1], buffer[2], buffer[3]);
		if (amount == 4)
		{
			auxEmp = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
			if (auxEmp != NULL)
			{

				employee_getId(auxEmp, &emp.id);
				employee_getNombre(auxEmp, emp.name);
				employee_getHorasTrabajadas(auxEmp, &emp.workedHours);
				employee_getSueldo(auxEmp, &emp.salary);
				printf("%d, %s, %d, %d\n", emp.id, emp.name, emp.workedHours, emp.salary);
				ll_add(pArrayListEmployee, auxEmp);
			}
		}
		else
		{
			break;
		}
	}
    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int error = 0;
	Employee* auxEmp;
	char id[10];
	char hours[100];
	char salary[100];
	int theEnd;

	do{
		theEnd = fread(auxEmp, sizeof(Employee), 1, pFile);
		auxEmp = employee_newParametros(itoa(auxEmp->id, id, 2), auxEmp->name, itoa(auxEmp->workedHours, hours, 2), itoa(auxEmp->salary, salary, 2));
		if(auxEmp != NULL){
			printf("%d, %s, %d, %d", auxEmp->id, auxEmp->name, auxEmp->workedHours, auxEmp->salary);
			ll_add(pArrayListEmployee, auxEmp);
		}
	}while (theEnd != 0);

    return error;
}
