#include <stdio.h>
#include <windows.h>

typedef struct
{
	int arr[100];
	int length;
} vector;

char* menu()
{
	return "\n1. Generate all the prime numbers smaller than n.\n2. Find the longest increasing contiguous subsequence\n3.Lab activity\n";
}

//Reads a vector of numbers different than 0
vector read()
{
	vector a;
	a.length = 0;
	int element = 1;

	printf("Give numbers:\n");
	while (element != 0)
	{
		scanf("%d", &element);
		if (element)
		{
			a.arr[a.length++] = element;
		}
	}
	return a;
}


//Check if t is a prime number. We return 1 if it s prime, 0 otherwise.
int prime(int t)
{
	int c;
	for (c = 2; c <= t-1; c++)
	{
		if (t%c == 0)
			return 0;
	}
	if (c == t) 
		return 1;
}

//We find the prime numbers smaller than n, and we print them.
int primesBeforeN()
{
	int p = 1;
	int* n;

	printf("Give number:");
	scanf("%d", &n);
	for (p = 1; p <= n; p++)
	{
		if (prime(p) == 1)
		{
			printf(" %d ", p);
		}
	}
	return 0;
}


//We read a vector and we search for the longest increasing subsequence in it.
//We will return the vector, and also the start(st) and the end(en) of the sequence.
//In case there is no such sequence in the vector, en will be 0.
vector findSubseq(int* st,int* en)
{
	int i;
	*st = 0;
	*en = 0;
	int max = 1;
	int e;
	vector v=read();
	for (i = 1; i <= v.length; i++)
	{
		e = i;
		do
		{
			e = e + 1;
		} while (v.arr[e] > v.arr[e - 1]);
		if (max < e - i)
		{
			max = e - i;
			*en= e-1;
			*st = i;
		}
	}
	return v;
}

// Prints the elements of a vector between the given positions (start and end).
void printVector(vector a, int *start, int *end)
{
	int i = 0;
	for (i = *start; i <= *end; i++)
	{
		printf("%d ", a.arr[i]);
	}
	printf("\n");
}

//We print the longest subsequence of a vector if there exists one.
//Otherwise, we print a message.
int showSubseq()
{
	int* st;
	int* en;
	vector a;

	a=findSubseq(&st, &en);
	if ( en!=0)
		printVector(a, &st, &en);
	if (en==0)
		printf("No contiguos sequence in this vector!\n");
}

//For the 3rd requirement, we read n and we find the first n pairs of prime numbers who have the property that q-p=2.
//We print the pairs.
int showPairs() 
{
	int n;
	int k = 2;
	int nr = 0;
	printf("Give a number:\n");
	scanf("%d", &n);
	do
	{
		if (prime(k) == 1 && prime(k + 2) == 1)
		{
			printf("%d", k);
			printf(", %d", k+2);
			printf("\n");
			nr = nr + 1;
		}
		k = k + 1;
	} while (nr != n);
	return 0;
}

int main()
{
	char*m = menu();
	char cmd;
	vector a;
	int x;
	int y;
	do
	{
		printf(m);
		printf("Give command:");
		scanf("%c", &cmd);
		if (cmd == '1')
		{
			primesBeforeN();
		}
		if (cmd == '2')
		{
			showSubseq();
		}
		if (cmd == '3')
		{
			showPairs();
		}

	} while (cmd != '0');
	system("pause");
}