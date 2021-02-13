#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct
{
	char* name;
	char* number;
} Contact;

Contact createContact(char* name, char* number)
{
	Contact person;
	person.name = malloc(sizeof(char) * (strlen(name) + 1));
	person.number = malloc(sizeof(char) * (strlen(number) + 1));
	if (person.name == NULL || person.number == NULL)
	{
		exit(1);
	}
	if (person.name && person.number)
	{
		strcpy(person.name, name);
		strcpy(person.number, number);
	}
	return person;
}

int inputComand();

void printMenu();

void savePhoneNumber(Contact phone, int phonesCount);

void printContacts(Contact* phones, int phonesCount);

int loadContacts(Contact phones[100]);

void addAnEntry(Contact* phones, int* phonesCount);

void searchByName(Contact* phones, int phonesCount);

void searchByNumber(Contact* phones, int phonesCount);

int main()
{
	printMenu();

	Contact phones[100];
	int phonesCount = loadContacts(phones);

	while (true)
	{
		int cmd = inputComand();

		switch (cmd)
		{
		case 0: 
		{
			return;
		}
		case 1:
		{
			addAnEntry(phones, &phonesCount);
			break;
		}
		case 2:
		{
			printContacts(phones, phonesCount);
			break;
		}
		case 3:
		{
			searchByName(phones, &phonesCount);
			break;
		}
		case 4:
		{
			searchByNumber(phones, &phonesCount);
			break;
		}
		default:
		{
			printf("Enter the correct comand!\n");
		}
		}
	}
}

void printMenu()
{
	printf("Menu:\n");
	printf("0 - exit\n");
	printf("1 - add an entry(name and phone number)\n");
	printf("2 - print all available entries\n");
	printf("3 - find phone by name\n");
	printf("4 - find name by phone\n");
}

int inputComand()
{
	printf("\nType the command: ");
	char cmd[100];
	gets_s(cmd, 99);
	if (isdigit((unsigned char)cmd[0]))
	{
		return cmd[0] - '0';
	}
	else
		return 5;
}

void printContacts(Contact* phones, int phonesCount)
{
	printf("------------------\n");
	for (int i = 0; i < phonesCount; i++)
	{
		printf("Name: %s\n", phones[i].name);
		printf("Phone: %s\n", phones[i].number);
		printf("------------------\n");
	}
}

void savePhoneNumber(Contact phone, int phonesCount)
{
	FILE* file = fopen("DATA.txt", "a");
	if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (phonesCount > 0)
	{
		fputs("\n", file);
	}
	fputs(phone.name, file);
	fputs("\n", file);
	fputs(phone.number, file);
	fclose(file);
	printf("Saved\n");
}

int loadContacts(Contact phones[100])
{
	FILE* file = fopen("DATA.txt", "r");
	if (file == NULL)
	{
		printf("File not found!");
		exit(EXIT_FAILURE);
	}

	int phoneCount = 0;
	while (!feof(file))
	{
		char name[50];
		char number[50];
		int read = fscanf(file, "%s", name);
		if (read <= 0)
		{
			printf("Didn't read anything!");
		}
		read = fscanf(file, "%s", number);
		if (read <= 0)
		{
			printf("Didn't read anything!");
			exit(EXIT_FAILURE);
		}
		phones[phoneCount] = createContact(name, number);
		phoneCount++;
	}
	fclose(file);
	return phoneCount;
}

void addAnEntry(Contact* phones, int* phonesCount)
{
	if (*phonesCount == 99)
	{
		printf("Contact limit exceeded!\n");
		exit(EXIT_FAILURE);
	}

	char name[50];
	printf("Name: ");
	if (!scanf("%s", name))
	{
		printf("Error!");
		exit(EXIT_FAILURE);
	}

	char number[50];
	printf("Phone: ");
	if (!scanf("%s", number))
	{
		printf("Error!");
		exit(EXIT_FAILURE);
	}

	Contact person = createContact(name, number);
	phones[*phonesCount] = person;
	(*phonesCount)++;

	savePhoneNumber(person, *phonesCount);
}

void searchByName(Contact* phones, int phonesCount)
{
	char name[50] = { 0 };
	printf("Enter a name to search for: ");
	if (!scanf("%s", name))
	{
		printf("Error!");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < phonesCount; i++)
	{
		if (!strcmp(phones[i].name, name))
		{
			printf("------------------\n");
			printf("Name: %s\n", phones[i].name);
			printf("Phone: %s\n", phones[i].number);
			printf("------------------\n");
			break;
		}
		if (i == phonesCount - 1)
		{
			printf("Contact not found\n");
		}
	}
}

void searchByNumber(Contact* phones, int phonesCount)
{
	char number[50] = { 0 };
	printf("Enter the number to search for: ");
	if (!scanf("%s", number))
	{
		printf("Error!");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < phonesCount; i++)
	{
		if (!strcmp(phones[i].number, number))
		{
			printf("------------------\n");
			printf("Name: %s\n", phones[i].name);
			printf("Phone: %s\n", phones[i].number);
			printf("------------------\n");
			break;
		}
		if (i == phonesCount - 1)
		{
			printf("Contact not found\n");
		}
	}
}