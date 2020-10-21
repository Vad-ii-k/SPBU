#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int inputComand()
{
	int num;
	printf("\nType the command: ");
	scanf("%d", &num);
	return num;
}

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
		fscanf(file, "%s", name);
		fscanf(file, "%s", number);
		phones[phoneCount] = createContact(name, number);
		phoneCount++;
	}
	fclose(file);
	return phoneCount;
}

int main()
{
	printf("Menu:\n 0 - exit\n 1 - add an entry(name and phone number)\n 2 - print all available entries\n");
	printf(" 3 - find phone by name\n 4 - find name by phone\n");

	Contact phones[100];
	int phonesCount = loadContacts(phones);

	while (true)
	{
		int cmd;
		cmd = inputComand();

		switch (cmd)
		{
		case 0: return;
		case 1:
		{
			if (phonesCount == 99)
			{
				printf("Contact limit exceeded!\n");
				break;
			}
			char name[50];
			printf("Name: ");
			scanf("%s", name);

			char number[50];
			printf("Phone: ");
			scanf("%s", number);

			Contact person = createContact(name, number);
			phones[phonesCount] = person;
			phonesCount++;

			savePhoneNumber(person, phonesCount);
			printf("Conserved\n");
			break;
		}
		case 2:
		{
			for (int i = 0; i < phonesCount; i++)
			{
				printf("Name: %s\nPhone: %s\n------------------\n", phones[i].name, phones[i].number);
			}
			break;
		}

		case 3:
		{
			char name[50];
			printf("Enter a name to search for: ");
			scanf("%s", name);
			for (int i = 0; i < phonesCount; i++)
			{
				if (!strcmp(phones[i].name, name))
				{
					printf("------------------\nName: %s\nNumber: %s\n------------------\n", phones[i].name, phones[i].number);
					break;
				}
				if (i == phonesCount - 1)
				{
					printf("Contact not found\n");
				}
			}
			break;
		}
		case 4:
		{
			char number[50];
			printf("Enter the number to search for: ");
			scanf("%s", number);
			for (int i = 0; i < phonesCount; i++)
			{
				if (!strcmp(phones[i].number, number))
				{
					printf("------------------\nName: %s\nPhone: %s\n------------------\n", phones[i].name, phones[i].number);
					break;
				}
				if (i == phonesCount - 1)
				{
					printf("Contact not found\n");
				}
			}
			break;
		}
		}
	}
}