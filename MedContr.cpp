#include "MedContr.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>
#include "Operations.h"

//Create the controller
Controller* createController(MedRepo* r, OperationsStack* s, OperationsStack* p)
{
	Controller* c = (Controller*)malloc(sizeof(Controller));
	if (c == NULL)
		return NULL;
	c->repo = r;
	c->undoStack = s;
	c->redoStack = p;
	return c;
}

//Destroy the controller
void destroyController(Controller* c)
{
	if (c == NULL)
		return ;
	free(c);
	c = NULL;
}

//Getter for repo
MedRepo* getRepo(Controller* c)
{
	return c->repo;
}

//Adds a medication into the list
int addMedication(Controller* c, char name[20], int concentration, int quantity, int price)
{
	Medication m = createMed(name, concentration, quantity, price);
	int res = addMed(c->repo, m);
	if (res == 1)
	{
		Operation o = createOperation(m, "add");
		push(c->undoStack, o);
	}
	return res;
}

//Deletes a medication from the list
int deleteMedication(Controller* c, char name[20], int concentration)
{
	Medication m = createMed("", -1, -1, -1);
	int pos = find(c->repo, name, concentration);
	if (pos != -1)
		m = getMedPos(c->repo, pos);
	int res = deleted(c->repo, name, concentration);
	if (res == 1)
	{
		Operation o = createOperation(m, "remove");
		push(c->undoStack, o);
	}
	return res;
}

//Update the quantity of a given medication with the new one
int updQuantity(Controller* c, char name[20], int concentration, int quantity)
{
	int res = updateQuantity(c->repo, name, concentration, quantity);
	return res;
}

//Update the price of a given medication with the new one
int updPrice(Controller* c, char name[20], int concentration, int price)
{
	int res = updatePrice(c->repo, name, concentration, price);
	return res;
}

//Filter the medications by name. If "null" then we return all the elements
MedRepo* filterByName(Controller* c, char name[20])
{
	if (c == NULL)
		return NULL;
	int repoLength = getLengthRepo(c->repo);
	MedRepo* res = createRepo();
	if (strcmp(name, "null") == 0)
	{
		for (int i = 0; i < repoLength; i++)
		{
			Medication m = getMedPos(c->repo, i);
			addMed(res, m);
		}
		return res;
	}
	for (int i = 0 ; i < repoLength; i++)
	{
		Medication m = getMedPos(c->repo, i);
		if (strstr(getName(&m), name) != NULL)
			addMed(res, m);
	}
	return res;
}

//Sort the medication in ascending order by name
MedRepo* sortByName(MedRepo* repo)
{
	int swapWasMade = 1;
	int i;
	while (swapWasMade)
	{
		swapWasMade = 0;
		if (getLengthRepo(repo) > 1)
		{
			for ( i = 0; i < getLengthRepo(repo)-1; i++)
			{
				if (strcmp(get(repo->meds, i).name, get(repo->meds, i + 1).name)>0)
				{
					swapElementsOnPositions(repo->meds, i, i + 1);
					swapWasMade = 1;
				}
			}
		}

	}
	return repo;
}

//Sort the medication in ascending order by concentration
MedRepo* sortByConcentration(MedRepo* repo)
{
	int swapWasMade = 1;
	int i;
	while (swapWasMade)
	{
		swapWasMade = 0;
		if (getLengthRepo(repo) > 1)
		{
			for (i = 0; i < getLengthRepo(repo) - 1; i++)
			{
				if (get(repo->meds, i).concentration > get(repo->meds, i + 1).concentration)
				{
					swapElementsOnPositions(repo->meds, i, i + 1);
					swapWasMade = 1;
				}
			}
		}

	}
	return repo;
}

//See only those medications in short supply
MedRepo* filterByQuantity(Controller* c, int quantity)
{
	if (c == NULL)
		return NULL;
	int repoLength = getLengthRepo(c->repo);
	MedRepo* res = createRepo();
	for (int i = 0; i < repoLength; i++)
	{
		Medication m = getMedPos(c->repo, i);
		if (getQuantity(&m)<=quantity)
			addMed(res, m);
	}
	return res;
}


int undo(Controller* c)
{
	int i;
	if (isEmpty(c->undoStack))
		return 0;

	Operation o = pop(c->undoStack);

	if (strcmp(getOperationType(&o), "add") == 0)
	{
		Medication m = getMedication(&o);
		char name[20];
		int concentr;
		strcpy(name, getName(&m));
		concentr = getConcentration(&m);
		i = deleted(c->repo, name, concentr);
		Operation o = createOperation(m, "add");
		push(c->redoStack, o);
	}

	if (strcmp(getOperationType(&o), "remove") == 0)
	{
		Medication m = getMedication(&o);
		i = addMed(c->repo, m);
		Operation o = createOperation(m, "remove");
		push(c->redoStack, o);
	}

	return 1;
}
int redo(Controller* c)
{
	if (isEmpty(c->redoStack))
		return 0;

	Operation o = pop(c->redoStack);

	if (strcmp(getOperationType(&o), "remove") == 0)
	{
		Medication m = getMedication(&o);
		char name[20];
		int concentr;
		strcpy(name, getName(&m));
		concentr = getConcentration(&m);
		deleted(c->repo, name, concentr);
	}

	if (strcmp(getOperationType(&o), "add") == 0)
	{
		Medication m = getMedication(&o);
		return addMed(c->repo, m);
	}

	return 1;
}
//_________________________________________TESTS__________________________________________

void initCtrlRepoForTests(Controller* cc)
{
	addMedication(cc, "algo", 20, 3, 10);
}

void testAdds()
{
	Medication m = createMed("algo", 40, 2, 15);
	MedRepo* v = createRepo();
	OperationsStack undoStack = createStack();
	OperationsStack redoStack = createStack();
	Controller* cc = createController(v,&undoStack,&redoStack);
	initCtrlRepoForTests(cc);
	assert(getLengthRepo(v) == 1);
	assert(addMedication(cc, "lala",12,23,34) == 1);
	assert(getLengthRepo(v) == 2);
	assert(addMed(v, m) == 0);
	assert(getLengthRepo(v) == 2);
	destroyController(cc);
}

void testDeletes()
{
	Medication m = createMed("algo", 40, 2, 15);
	MedRepo* v = createRepo();
	OperationsStack undoStack = createStack();
	OperationsStack redoStack = createStack();
	Controller* cc = createController(v, &undoStack, &redoStack);
	initCtrlRepoForTests(cc);

	assert(deleteMedication(cc, "algo", 20) == 1);
	assert(getLengthRepo(v) == 0);

	// try to remove the same med again
	assert(deleteMedication(cc, "algo", 40) == 0);
	destroyController(cc);
}

void testUpdates()
{
	Medication m = createMed("algo", 40, 2, 15);
	MedRepo* v = createRepo();
	OperationsStack undoStack = createStack();
	OperationsStack redoStack = createStack();
	Controller* cc = createController(v, &undoStack, &redoStack);
	initCtrlRepoForTests(cc);

	assert(updQuantity(cc, "algo", 20, 30) == 1);
	assert(updPrice(cc, "asdf", 20, 4) == 0);
	destroyController(cc);
} 

void testsCtrl()
{
	testAdds();
	testDeletes();
	testUpdates();
}  