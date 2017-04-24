#pragma once

typedef struct
{
	char name[20];
	int concentration;
	int quantity;
	int price;
} Medication;

Medication createMed(char name[20], int concentration, int quantity, int price);
char* getName(Medication* m);
int getConcentration(Medication* m);
int getQuantity(Medication* m);
int getPrice(Medication* m);

void setConcentration(Medication m, int concentration);
void setQuantity(Medication m, int quantity);
void setPrice(Medication m, int price);
void toString(Medication m, char str[]);

