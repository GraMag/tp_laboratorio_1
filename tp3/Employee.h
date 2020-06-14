#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
	  int id;
	    char name[128];
	    int workedHours;
	    int salary;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nameStr,char* workedHoursStr,char* salaryStr);

void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* name);
int employee_getNombre(Employee* this,char* name);

int employee_setHorasTrabajadas(Employee* this,int workingHours);
int employee_getHorasTrabajadas(Employee* this,int* workingHours);

int employee_setSueldo(Employee* this,int salary);
int employee_getSueldo(Employee* this,int* salary);

int initEmployees(LinkedList* list);
int printEmployees(LinkedList* list);
int printEmployee(Employee* this);
#endif // employee_H_INCLUDED
