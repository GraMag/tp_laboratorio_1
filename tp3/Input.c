#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"

int askForInt(char message[20], int min)
{
	int num;

	printf("Ingrese %s: ", message);
	scanf("%d", &num);

	if(num < min)
	{
		printf("ERROR: %s fuera de rango.\n", message);
	}
	return num;
}

/** \brief gets a char array to check lenght, when it's ok everything turn to lower case,
 * then the first letter of each word is change to upper case
* \param char message[20]
* \param char* string
*/
int askForString(char message[20], char* string)
{
	int error = -1;
	printf("Ingrese %s: ", message);
	fflush(stdin);
	gets(string);
	int noNum = 0;

	if (strlen(string) > 127)
	{
		printf("ERROR: %s es demasiado largo.\n", message);
	}
	else
	{
		for (int i = 0; i < strlen(string); i++)
		{
			if(isdigit(string[i]))
			{
				printf("ERROR: No se aceptan numeros.\n");
				noNum = 1;
				break;
			}
		}
	}

	if (noNum == 0)
	{
		strlwr(string);
		for(int i = 0; i < strlen(string); i++)
		{
			string[0] = toupper(string[0]);
			if(string[i] == ' ')
			{
				string[i+1] = toupper(string[i+1]);
			}
		}
		error = 0;
	}
	return error;
}


