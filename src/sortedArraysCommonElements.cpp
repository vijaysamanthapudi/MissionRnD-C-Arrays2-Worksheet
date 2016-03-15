/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int str_cmp(char a[], char b[]);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	if (A == NULL || B == NULL || ALen < 0 || BLen < 0)
	{
		return NULL;
	}


	struct transaction **temp =(struct transaction **)malloc(sizeof(struct transaction));
	int i, j,k=0;
	*temp == NULL;
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{
			if (str_cmp(A[i].date, B[j].date) == 1)
			{
				temp[k] = (struct transaction *)malloc(sizeof(struct transaction));
				temp[k] = &A[i];
				k++;


			}
		}
	}
	if (k == 0)
		return NULL;
	else
	{
		return *temp;
	}
	
}

int str_cmp(char a[], char b[])
{
	int i;
	for (i = 0; a[i]; i++)
	{
		if (a[i] != b[i])
		{
			return 0;
		}
	}
	return 1;
}
