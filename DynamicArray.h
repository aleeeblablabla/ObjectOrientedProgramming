#pragma once
#include "Medication.h"

typedef Medication TElement;

typedef struct
{
	TElement* medications;
	int length; //this is the actual length of the array
	int capacity;
} DynamicArray;

TElement get(DynamicArray* arr, int pos);
DynamicArray* createDynamicArray(int capacity);
void destroy(DynamicArray* arr);
void add(DynamicArray* arr, TElement t);
int getLength(DynamicArray* arr);
TElement get(DynamicArray* arr, int pos);
void swapElementsOnPositions(DynamicArray* arr, int i, int j);
void testDynamicArray();