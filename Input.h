#ifndef INPUT_H_
#define INPUT_H_

int inputInt(char message[20], int min);
int askForInt(char message[20], int min, int max);
int askForString(char message[20], char* string, int max);
int askForIntAsString(char message[20], char* string, int max);

#endif /* INPUT_H_ */
