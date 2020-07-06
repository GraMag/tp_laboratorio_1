#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"

/**
 * @brief checks if number is inside a range
 *
 * @param num
 * @param min
 * @param max
 * @return int [-1] out of rage [num] ok
 */
int getInt(int num, int min, int max)
{
	if(num < min || num > max)
	{
		num = -1;
	}
	return num;
}
/**
 * @brief Ask user for an int
 *
 * @param message
 * @param min
 * @param max
 * @return int [-1] out of rage [num] ok
 */
int askForInt(char message[20], int min, int max)
{
	int num;

	printf("Ingrese %s: ", message);
	scanf("%d", &num);

	if(getInt(num, min, max) == -1)
	{
		printf("ERROR: %s fuera de rango.\n", message);
		num = -1;
	}
	return num;
}

/** \brief gets a char array to check lenght, when it's ok everything turn to lower case,
 * then the first letter of each word is change to upper case
* \param char message[20]
* \param char* string
*/
int askForString(char message[20], char* string, int max)
{
	int error = -1;
	printf("Ingrese %s: ", message);
	fflush(stdin);
	gets(string);
	int noNum = 0;

	if (strlen(string) > max)
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

/**
 * @brief ask user for a char array of numbers
 *
 * @param message
 * @param string
 * @param max
 * @return int [-1] if the char[] has letters, [0] if all the char array contains numbers
 */
int askForIntAsString(char message[20], char* string, int max)
{
	int error = -1;
	printf("Ingrese %s: ", message);
	fflush(stdin);
	gets(string);

	if (strlen(string) > max)
	{
		printf("ERROR: %s demasiado largo.\n", message);
	}
	else
	{
		for (int i = 0; i < strlen(string); i++)
		{
			if(!isdigit(string[i]))
			{
				printf("Error: no es un numero\n");
				break;
			}
			else
			{
				error = 0;
			}
		}
	}
	return error;
}
