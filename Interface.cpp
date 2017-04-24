#include <stdio.h>
#include "MedContr.h"
#include <stddef.h>
#include <stdlib.h>
#include "Interface.h"

UI* createUI(Controller* c)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	if (ui == NULL)
		return NULL;
	ui->ctrl = c;
	return ui;
}

void destroyUI(UI* ui)
{
	if (ui == NULL)
		return;
	free(ui);
	ui = NULL;
}

//Prints the available menu
void printMenu()
{
	printf("Available commands:\n");
	printf("1: Add medication\n");
	printf("2: Delete medication\n");
	printf("3: Update quantity of medication\n");
	printf("4: Update price of medication\n");
	printf("5: Search for available medications\n");
	printf("6: See medications that are in short supply\n");
	printf("7: Undo\n");
	printf("8: Redo\n");
	printf("9: See all the available medications\n");
	printf("L: Lab activity:Search by name and see ordered by concentration\n");
	printf("0: Exit\n");
}



void addMedUI(UI* ui)
{
	char name[20];
	int concentration, quantity, price, x;
	printf("Give medication name: \n");
	scanf("%s", name);
	concentration = readConcentration();
	printf("Give quantity: \n");
	scanf("%d", &quantity);
	printf("Give price: \n");
	scanf("%d", &price);
	x = addMedication(ui->ctrl, name, concentration, quantity, price);
	if (x == 1)
		printf("Medication successfully added! \n");
	if (x == 0)
		printf("Quantity was increased! \n");
}

void delMedUI(UI* ui)
{
	char name[20];
	int concentration;
	int x;
	printf("Give medication name: \n");
	scanf("%s", name);
	concentration = readConcentration();
	x = deleteMedication(ui->ctrl, name, concentration);
	if (x == 1)
		printf("Medication successfully removed! \n");
	if (x == 0)
		printf("Medication not found! \n");
}
//Reads a number from the keyboard until the given number is an integer
int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

//Read an integer number from the keyboars and does not return it until it is a valid concentration.
//A concentration is valid if it represents an integer number between 1 and 100.
int readConcentration()
{
	int x;
	
	do
	{
		x = readIntegerNumber("Give concentration: \n");
		if (x <= 0 || x>100)
		{
			printf("Concentration must be an integer between 1 and 100\n");
		}
	} while (x <= 0 || x > 100);
	return x;
}

void updPriceUI(UI* ui)
{
	char name[20];
	int concentration, price, x;
	printf("Give medication name: \n");
	scanf("%s", name);
	concentration = readConcentration();
	printf("Give price: \n");
	scanf("%d", &price);
	x = updPrice(ui->ctrl, name, concentration, price);
	if (x == -1)
		printf("Something is not ok!");
	if (x == 0)
		printf("This medication in not available!");
	if (x == 1)
		printf("Price updated!");
}

void updQuantityUI(UI* ui)
{
	char name[20];
	int concentration, quantity, x;
	printf("Give medication name: \n");
	scanf("%s", name);
	concentration = readConcentration();
	printf("Give quantity: \n");
	scanf("%d", &quantity);
	x = updQuantity(ui->ctrl, name, concentration, quantity);
	if (x == -1)
		printf("Something is not ok!");
	if (x == 0)
		printf("This medication in not available!");
	if (x == 1)
		printf("Quantity updated!");
}

void listAllMeds(UI* ui)
{
	MedRepo* rep = getRepo(ui->ctrl);
	int length, i;
	length = getLengthRepo(rep);
	if (length == 0)
	{
		char* str = "There are no stored meds";
		printf("%s \n", str);
	}
	i = 0;
	for (i; i < length; i++)
	{
		char str[200];
		toString(getMedPos(rep, i), str);
		printf("%s\n", str);
	}
}

void searchMeds(UI* ui)
{
	char name[20];
	printf("Search: ");
	scanf("%s", name);
	MedRepo* res = sortByName(filterByName(ui->ctrl, name));
	int length = getLengthRepo(res);
	if (length == 0)
		printf("No medication found!");
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(getMedPos(res, i), str);
			printf("%s\n", str);
		}
	}
}

void searchMedsByQuantity(UI* ui)
{
	int quantity;
	printf("Search for meds in quantity less than: ");
	scanf("%d", &quantity);
	MedRepo* res = sortByName(filterByQuantity(ui->ctrl, quantity));
	int length = getLengthRepo(res);
	if (length == 0)
		printf("No medication found!");
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(getMedPos(res, i), str);
			printf("%s\n", str);
		}
	}
}

void byConcentration(UI* ui)
{
	char name[20];
	printf("Search: ");
	scanf("%s", name);
	MedRepo* res = sortByConcentration(filterByName(ui->ctrl, name));
	int length = getLengthRepo(res);
	if (length == 0)
		printf("No medication found!");
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(getMedPos(res, i), str);
			printf("%s\n", str);
		}
	}
}

void undoUI(UI* ui)
{
	int res = undo(ui->ctrl);
	if (res == 0)
		printf("Undo cannot be done.\n");
	else
		printf("Done!\n");
}

void redoUI(UI* ui)
{
	int res = redo(ui->ctrl);
	if (res == 0)
		printf("Redo cannot be done.\n");
	else
		printf("Done!\n");
}

void startUI(UI* ui)
{
	char cmd;
	do
	{
		printMenu();
		printf("Give command: ");
		scanf("%c", &cmd);
		if (cmd == '1')
			addMedUI(ui);
		if (cmd == '2')
			delMedUI(ui);
		if (cmd == '3')
			updQuantityUI(ui);
		if (cmd == '4')
			updPriceUI(ui);
		if (cmd == '5')
			searchMeds(ui);
		if (cmd == '6')
			searchMedsByQuantity(ui);
		if (cmd == '7')
			undoUI(ui);
		if (cmd == '8')
			redoUI(ui);
	    if (cmd=='9')
			listAllMeds(ui);
		if (cmd == 'L')
			byConcentration(ui);
	} while (cmd != '0');
	
}