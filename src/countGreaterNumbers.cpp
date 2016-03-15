/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
void convert_date(char str[], int d[]);
int search(struct transaction *Arr, int left, int right, int d1[], int dlen);
int compare(int d1[], int d2[], int dlen);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	
	int d1[3] = { 0 }, d2[3] = { 0 }, i;
	convert_date(date, d1);
	convert_date(Arr[len - 1].date, d2);
	if (compare(d1, d2, 3) == 1)
	{
		return 0;
	}
	int pos = search(Arr, 0, len, d1, 2);
	if (pos == -1)
	{
		return 0;
	}
	else
	{
		return len - pos - 1;
	}



}
void convert_date(char str[], int d[])
{
	int i, j = 0;
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


int search(struct transaction *Arr, int left, int right, int d1[], int dlen)
{
	if (left <= right)
	{

		int d2[3] = { 0 }, pos = left + right / 2;
		
		convert_date(Arr[pos].date, d2);
		int choice = compare(d1, d2, dlen);
		switch (choice)
		{
		case 1:return pos;
			break;
		case -1:
			search(Arr, left, pos - 1, d1, dlen);
			break;
		case -2:
			search(Arr, pos + 1, right, d1, dlen);
			break;
		case 3:
			return -1;
		}
	}
	else
	{
		return -1;
	}


}


int compare(int d1[], int d2[], int dlen)
{

	if (dlen == 0 && d1[dlen] == d2[dlen])
	{
		return 1;
	}
	if (dlen == 0 && d1[dlen] != d2[dlen])
	{
		return 3;
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
		compare(d1, d2, --dlen);
	}


}


