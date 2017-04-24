#include <stdlib.h>
#include <assert.h>
#include "DynamicArray.h"

//Creates a dynamic array of medications with a given capacity
//Returns a pointer to the created dynamic array
DynamicArray* createDynamicArray(int capacity)
{
	DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
	//make sure the space was allocated
	if (da == NULL)
		return NULL;
	da->capacity = capacity;
	da->length = 0;
	//allocate space for the medications
	da->medications = (TElement*)malloc(capacity * sizeof(TElement));
	if (da->medications == NULL)
	{
		return NULL;
	}
	return da;
}

//Destroys the dynamic array arr
void destroy(DynamicArray* arr)
{
	if (arr == NULL)
	{
		return;
	}
	//free the allocated space
	free(arr->medications);
	arr->medications = NULL;
	//free the space allocated for the dynamic array
	free(arr);
	arr = NULL;
}

//Resize the array, allocate more space
void resize(DynamicArray* arr)
{
	if (arr == NULL)
		return;
	arr->capacity *= 2;
	arr->medications = (TElement*)realloc(arr->medications, arr->capacity * sizeof(TElement));
}

//Adds a medication to the dynamic array
void add(DynamicArray* arr, TElement t)
{
	if (arr == NULL) 
		return;
	if (arr->medications == NULL)
		return;
	//resize the array if necessary
	if (arr->length == arr->capacity)
		resize(arr);
	arr->medications[arr->length] = t;
	arr->length++;
}
// Getter for the length of the array
int getLength(DynamicArray* arr)
{
	if (arr == NULL)
		return 0;
	return arr->length;
}

//Returns the element on a given position pos
TElement get(DynamicArray* arr, int pos)
{
	return arr->medications[pos];
}

//Swaps 2 element given by their positions i and j
void swapElementsOnPositions(DynamicArray* arr, int i, int j)
{
	if (arr == NULL)
		return;
	if (arr->medications == NULL)
		return;
	TElement aux = arr->medications[i];
	arr->medications[i] = arr->medications[j];
	arr->medications[j] = aux;
}


//__________________________________________TESTS:_________________________________________


void testsDynamicArray()
{
	DynamicArray* da = createDynamicArray(2);
	if (da == NULL)
		assert(0);
	assert(da->capacity == 2);
	assert(da->length == 0);
	Medication m1 = createMed("Elmi", 20, 2, 10);
	add(da, m1);
	assert(da->length == 1);
	Medication m2 = createMed("Algo", 10, 4, 5);
	add(da, m2);
	assert(da->length == 2);
	//here capacity must double:
	Medication m3 = createMed("Tea", 5, 6, 2);
	add(da, m3);
	assert(da->length == 3);
	assert(da->capacity == 4);
	destroy(da);
}

