/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int comparedate(int d1[], int d2[], int dlen);
void convertdate(char str[], int d[]);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction *mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	if (A == NULL || B == NULL || ALen < 0 || BLen < 0)
	{
		return NULL;
	}
	struct transaction *sort = NULL;
	sort = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	int i = 0, j = 0, d1[3], d2[3], dlen = 2, k = 0;
	convertdate(A[i].date, d1);
	convertdate(B[j].date, d2);
	while (i < ALen || j < BLen)
	{

		if ((comparedate(d1, d2, dlen) == 1) && (i<ALen && j<BLen))
		{

			sort[k] = A[i];
			k++;
			sort[k] = B[j];
			k++;
			i++;
			j++;
			convertdate(A[i].date, d1);
			convertdate(B[j].date, d2);
		}
		else if ((comparedate(d1, d2, dlen) == -1) && (i<ALen && j<BLen))
		{

			sort[k] = A[i];
			k++; i++;
			convertdate(A[i].date, d1);
		}
		else if ((comparedate(d1, d2, dlen) == -2) && (i<ALen && j<BLen))
		{

			sort[k] = B[j];
			k++; j++;
			convertdate(B[j].date, d2);
		}
		else if ((i == ALen || j == BLen))
		{
			if (i == ALen)
			{

				sort[k] = B[j];
				k++; j++;
			}
			else
			{
				
				sort[k] = A[i];
				k++; i++;
			}

		}
	}

	return sort;


}

void convertdate(char str[], int d[])
{
	int i, j = 0;
	for (i = 0; i < 3; i++)
	{
		d[i] = 0;
	}
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-')
		{
			j++;
		}
		else
		{
			d[j] = d[j] * 10 + str[i] - '0';
		}


	}

}

int comparedate(int d1[], int d2[], int dlen)
{

	if (dlen == 0 && d1[dlen] == d2[dlen])
	{
		return 1;
	}

	else if (d1[dlen] < d2[dlen])
	{
		return -1;
	}
	else if (d1[dlen] > d2[dlen])
	{
		return -2;
	}
	else if (d1[dlen] == d2[dlen])
	{
		comparedate(d1, d2, --dlen);
	}


}
