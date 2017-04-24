#include "MedRepo.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>

//Create the repository
MedRepo* createRepo()
{
	MedRepo* repo = (MedRepo*)malloc(sizeof(MedRepo));
	if (repo == NULL)
		return NULL;
	repo->meds = createDynamicArray(5);
	return repo;
}

//Destroy the repository
void destroyRepo(MedRepo* repo)
{
	if (repo == NULL)
		return;
	destroy(repo->meds);
	free(repo);
	repo = NULL;
}

//Search for a medication that has the same name as a given parameter
//Return the position of the medication that has the same name  and concentration as the given parameters
//or -1 if the name and concentration are not on the list
int find(MedRepo* v, char name[20], int concentration)
{
	if (v == NULL)
		return -1;
	Medication* m = NULL;
	for (int i = 0; i < getLengthRepo(v); i++)
	{
		if (strcmp(get(v->meds, i).name, name) == 0 && get(v->meds, i).concentration == concentration)
			return i;
	}
	return -1;
}

//Returns the length of the list
int getLengthRepo(MedRepo* v)
{
	if (v == NULL)
		return 0;
	return getLength(v->meds);
}

//Searches for a medication with the same characteristics as the one to be added 
//and if it already exists increases the quantity, otherwise adds it
int addMed(MedRepo* v, Medication m)
{
	if (v == NULL)
		return -1;
	if (find(v, m.name, m.concentration) != -1)
	{
		Medication n = get(v->meds, find(v, m.name, m.concentration));
		int r = deleted(v, n.name, n.concentration);
		Medication p = createMed(n.name, n.concentration, n.quantity+m.quantity, n.price);
		add(v->meds, p);
		return 0;
	}
	add(v->meds, m);
	return 1;
}

//Getter for the medication on a given position pos
Medication getMedPos(MedRepo* v, int pos)
{
	if (pos < 0 || pos >= getLengthRepo(v))
		return createMed("", -1, -1, -1);
	return get(v->meds, pos);
}

//Delete a medication given by name and concentration
int deleted(MedRepo* v, char name[20],int concentration)
{
	if (v == NULL)
		return -1;
	int pos = find(v, name, concentration);
	if (pos == -1)
		return 0;
	for (int i = pos; i < getLengthRepo(v); i++)
	{
		swapElementsOnPositions(v->meds, i, i + 1);
	}
	v->meds->length--;
	return 1;
}

//Update the quantity of a medication given by name and concentration
int updateQuantity(MedRepo* v, char name[20], int concentration, int quantity)
{
	if (v == NULL)
		return -1;
	int pos = find(v, name, concentration);
	if (pos == -1)
		return 0;
	Medication n = get(v->meds, find(v, name, concentration));
	int r = deleted(v, n.name, n.concentration);
	Medication p = createMed(n.name, n.concentration, quantity, n.price);
	add(v->meds, p);
	return 1;
}

//Update the price of a medication given by name and concentration
int updatePrice(MedRepo* v, char name[20], int concentration, int price)
{
	if (v == NULL)
		return -1;
	int pos = find(v, name, concentration);
	if (pos == -1)
		return 0;
	Medication n = get(v->meds, find(v, name, concentration));
	int r = deleted(v, n.name, n.concentration);
	Medication p = createMed(n.name, n.concentration, n.quantity, price);
	add(v->meds, p);
	return 1;
}


//_________________________________________TESTS__________________________________________

void initMedRepoForTests(MedRepo* v)
{
	Medication m = createMed("algo", 20, 3, 10);
	addMed(v, m);
}

void testAdd()
{
	Medication m = createMed("algo", 40, 2, 15);
	MedRepo* v = createRepo();
	initMedRepoForTests(v);
	assert(getLengthRepo(v) == 1);
	assert(addMed(v, m) == 1);
	assert(getLengthRepo(v) == 2);
	assert(addMed(v, m) == 0);
	assert(getLengthRepo(v) == 2);
}

void testDelete()
{
	MedRepo* v = createRepo();
	initMedRepoForTests(v);

	assert(deleted(v, "algo", 20) == 1);
	assert(getLengthRepo(v) == 0);

	assert(deleted(v, "algo",40) == 0);
}

void testUpdate()
{
	MedRepo* v = createRepo();
	initMedRepoForTests(v);

	assert(updateQuantity(v, "algo", 20, 30)==1);
	assert(updatePrice(v, "asdf", 20, 4) == 0);

}
void testMedRepo()
{
	testAdd();
	testDelete();
	testUpdate();
}