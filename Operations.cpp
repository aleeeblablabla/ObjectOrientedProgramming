#include "Operations.h"
#include <string.h>
#include "Medication.h"
#include <assert.h>

Operation createOperation(Medication m, char operationType[])
{
	Operation o;
	o.medication = m;
	strcpy(o.operationType, operationType);

	return o;
}

char* getOperationType(Operation* o)
{
	return o->operationType;
}

Medication getMedication(Operation* o)
{
	return o->medication;
}

// ---------------------------------------------------------------

OperationsStack createStack()
{
	OperationsStack s;
	s.length = 0;

	return s;
}

void push(OperationsStack* s, Operation o)
{
	if (isFull(s))
		return;

	s->operations[s->length] = o;
	s->length++;
}

Operation pop(OperationsStack* s)
{
	Operation o = createOperation(createMed("", -1, -1, -1), "");
	if (isEmpty(s))
		return o;
	s->length--;
	return s->operations[s->length];
}

int isEmpty(OperationsStack* s)
{
	return (s->length == 0);
}

int isFull(OperationsStack* s)
{
	return s->length == 100;
}
