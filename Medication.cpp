#include <stdio.h>
#include <string.h>
#include "Medication.h"

//Create the medication
//name(the name of medication), concentration(of medication), quantity and price
//return the medication
Medication createMed(char name[20], int concentration, int quantity, int price)
{
	Medication m;
	strcpy(m.name, name);
	m.concentration = concentration;
	m.quantity = quantity;
	m.price = price;

	return m;
}

//Getter for name
char* getName(Medication* m)
{
	return m->name;
}

//Getter for concentration
int getConcentration(Medication* m)
{
	return m->concentration;
}

//Getter for quantity
int getQuantity(Medication* m)
{
	return m->quantity;
}

//Getter for price
int getPrice(Medication* m)
{
	return m->price;
}

//Setter for concentration
void setConcentration(Medication m, int concentration)
{
	m.concentration = concentration;
}

 //Setter for quantity
void setQuantity(Medication m, int quantity)
{
	m.quantity = quantity;
}

//Setter for price
void setPrice(Medication m, int price)
{
	m.price = price;
}

//Tranform in a string the whole medication
void toString(Medication m, char str[])
{
	sprintf(str, "Name:%s Concentration:%.d. Quantity:%.d. Price:%.d.", m.name, m.concentration, m.quantity, m.price);
}