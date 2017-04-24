#pragma once
#include "Operations.h"
#include "MedRepo.h"

typedef struct
{
	MedRepo* repo;
	OperationsStack* undoStack;
	OperationsStack* redoStack;
}Controller;

Controller* createController(MedRepo* r, OperationsStack* s, OperationsStack* p);
void destroyController(Controller* c);
MedRepo* getRepo(Controller* c);
int addMedication(Controller* c, char name[20], int concentration, int quantity, int price);
int deleteMedication(Controller* c, char name[20], int concentration);
int updQuantity(Controller* c, char name[20], int concentration, int quantity);
int updPrice(Controller* c, char name[20], int concentration, int price);
MedRepo* filterByName(Controller* c, char name[20]);
MedRepo* sortByName(MedRepo* repo);
MedRepo* sortByConcentration(MedRepo* repo);
MedRepo* filterByQuantity(Controller* c, int quantity);
void testsCtrl();
void testAdds();
void testUpdates();
void testDeletes();
int undo(Controller* c);
int redo(Controller* c);