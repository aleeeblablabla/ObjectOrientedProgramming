#pragma once 
#include "Medication.h"
#include <string.h>

typedef struct
{
	Medication medication;
	char operationType[30];
} Operation;

char* getOperationType(Operation* o);

Medication getMedication(Operation* o);

// ---------------------------------------------------------------

Operation createOperation(Medication m, char operationType[]);

typedef struct
{
	Operation operations[100];
	int length;
} OperationsStack;

OperationsStack createStack();
void push(OperationsStack* s, Operation o);
Operation pop(OperationsStack* s);
int isEmpty(OperationsStack* s);
int isFull(OperationsStack* s);