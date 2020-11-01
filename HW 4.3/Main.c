#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
	if (person.name && person.number)
	{
		strcpy(person.name, name);
		strcpy(person.number, number);
	}
	return person;
}

int inputComand()
{
	printf("\nType the command: ");
	int num = 0;
	scanf_s("%d", &num);
	return num;
}

void savePhoneNumber(Contact phone, int phonesCount);

int loadContacts(Contact phones[100]);

void addAnEntry(int* phonesCount, Contact* phones);

void searchByName(int* phonesCount, Contact* phones);

void searchByNumber(int* phonesCount, Contact* phones);

void printMenu()
{
	printf("Menu:\n");
	printf("0 - exit\n");
	printf("1 - add an entry(name and phone number)\n");
	printf("2 - print all available entries\n");
	printf("3 - find phone by name\n");
	printf("4 - find name by phone\n");
}

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
			addAnEntry(&phonesCount, phones);
			break;
		}
		case 2:
		{
			printf("------------------\n");
			for (int i = 0; i < phonesCount; i++)
			{
				printf("Name: %s\n", phones[i].name);
				printf("Phone: %s\n", phones[i].number);
				printf("------------------\n");
			}
			break;
		}
		case 3:
		{
			searchByName(&phonesCount, phones);
			break;
		}
		case 4:
		{
			searchByNumber(&phonesCount, phones);
			break;
		}
		default:
		{
			printf("Enter the correct comand!\n");
		}
		}
	}
}

void savePhoneNumber(Contact phone, int phonesCount)
{
	FILE* file = fopen("DATA.txt", "a");
	if (file == NULL)
	{
		return;
	}

	if (phonesCount > 0)
	{
		fputs("\n", file);
	}
	fputs(phone.name, file);
	fputs("\n", file);
	fputs(phone.number, file);
	fclose(file);
}

int loadContacts(Contact phones[100])
{
	FILE* file = fopen("DATA.txt", "r");
	if (file == NULL)
	{
		printf("File not found!");
		return EXIT_FAILURE;
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
		}
		phones[phoneCount] = createContact(name, number);
		phoneCount++;
	}
	fclose(file);
	return phoneCount;
}

void addAnEntry(int* phonesCount, Contact* phones)
{
	if (*phonesCount == 99)
	{
		printf("Contact limit exceeded!\n");
		return;
	}

	char name[50];
	printf("Name: ");
	if (!scanf("%s", name))
	{
		printf("Error!");
		exit(1);
	}

	char number[50];
	printf("Phone: ");
	if (!scanf("%s", number))
	{
		printf("Error!");
		exit(1);
	}

	Contact person = createContact(name, number);
	phones[*phonesCount] = person;
	(*phonesCount)++;

	savePhoneNumber(person, *phonesCount);
	printf("Conserved\n");
}

void searchByName(int* phonesCount, Contact* phones)
{
	char name[50] = { 0 };
	printf("Enter a name to search for: ");
	if (!scanf("%s", name))
	{
		printf("Error!");
		exit(1);
	}

	for (int i = 0; i < *phonesCount; i++)
	{
		if (!strcmp(phones[i].name, name))
		{
			printf("------------------\n");
			printf("Name: %s\n", phones[i].name);
			printf("Phone: %s\n", phones[i].number);
			printf("------------------\n");
			break;
		}
		if (i == *phonesCount - 1)
		{
			printf("Contact not found\n");
		}
	}
}

void searchByNumber(int* phonesCount, Contact* phones)
{
	char number[50] = { 0 };
	printf("Enter the number to search for: ");
	if (!scanf("%s", number))
	{
		printf("Error!");
		exit(1);
	}

	for (int i = 0; i < *phonesCount; i++)
	{
		if (!strcmp(phones[i].number, number))
		{
			printf("------------------\n");
			printf("Name: %s\n", phones[i].name);
			printf("Phone: %s\n", phones[i].number);
			printf("------------------\n");
			break;
		}
		if (i == *phonesCount - 1)
		{
			printf("Contact not found\n");
		}
	}
}