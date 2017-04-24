#include "Interface.h"
#include "MedRepo.h"
#include <stdio.h>
#include "MedContr.h"

int main()
{
	testMedRepo();
	MedRepo* repo = createRepo();
	if (repo == NULL)
	{
		printf("Repository cannot be created.");
		return 1;
	}
	OperationsStack undoStack = createStack();
	OperationsStack redoStack = createStack();
	Controller* ctrl = createController(repo, &undoStack, &redoStack);
	if (ctrl == NULL)
	{
		printf("Controller cannot be created.");
		return 1;
	}
	
	addMedication(ctrl, "Algocalmin", 2, 10, 10);
	addMedication(ctrl, "AphtaPlus", 4, 13, 5);
	addMedication(ctrl, "AphtaPlus", 10, 6, 10);
	addMedication(ctrl, "AcneaidGel", 2, 8, 8);
	addMedication(ctrl, "Theraflu", 12, 16, 3);
	addMedication(ctrl, "Nurofen", 30, 12, 20);
	addMedication(ctrl, "Zynerit", 50, 22, 40);
	addMedication(ctrl, "Nalgesin", 13, 40, 30);
	addMedication(ctrl, "EucerinCream",15,14,50);
	addMedication(ctrl, "Paduden",24,13,25);
	addMedication(ctrl, "TantumVerde",3,40,15); 
	
	UI* ui = createUI(ctrl);
	if (ui == NULL)
	{
		printf("UI cannot be created!");
		return 1;
	}
	startUI(ui);
	destroyController(ctrl);
	destroyRepo(repo);
	return 0;
}