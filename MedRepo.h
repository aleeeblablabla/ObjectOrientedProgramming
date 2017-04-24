#pragma once
#include "Medication.h"
#include "DynamicArray.h"

typedef struct
{
	DynamicArray* meds;
} MedRepo;

MedRepo* createRepo();
void destroyRepo(MedRepo* repo);
int find(MedRepo* v, char name[20], int concentration);
int getLengthRepo(MedRepo* v);
int addMed(MedRepo* v, Medication m);
void initMedRepoForTests(MedRepo* v);
void testAdd();
void testMedRepo();
Medication getMedPos(MedRepo* v, int pos);
int deleted(MedRepo* v, char name[20], int concentration);
int updatePrice(MedRepo* v, char name[20], int concentration, int price);
int updateQuantity(MedRepo* v, char name[20], int concentration, int quantity);