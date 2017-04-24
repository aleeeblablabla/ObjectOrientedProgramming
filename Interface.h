#pragma once
#include "MedContr.h"

typedef struct
{
	Controller* ctrl;
}UI;

UI*createUI(Controller* c);
void startUI(UI* ui);
void printMenu();
int readIntegerNumber(const char* message);
int readConcentration();
void addMedUI(UI* ui);
void delMedUI(UI* ui);
void updQuantityUI(UI* ui);
void updPriceUI(UI* ui);
void searchMeds(UI* ui);
void byConcentration(UI* ui);
void searchMedsByQuantity(UI* ui);
void undoUI(UI* ui);
void redo(UI* ui);