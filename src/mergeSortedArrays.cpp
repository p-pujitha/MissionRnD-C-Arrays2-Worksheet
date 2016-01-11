/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL) return NULL;

	struct transaction *temp = (struct transaction*)malloc(sizeof(struct transaction) * 20);


	int i = 0, j, k = 0, flag = 0;
	for (j = 0; j < BLen;)
	{
		if (B[j].amount <= A[i].amount)
		{
			temp[k] = B[j];
			k++;



			j++;
		}
		else
		{
			temp[k] = A[i];
			k++;
			i++;
			if (ALen == i)
			{
				flag = 1;
				break;
			}
		}

	}
	if (flag == 1)
	{
		for (int l = j; l < BLen; l++)
		{
			temp[k] = B[l];
			k++;
		}
	}
	if (ALen != i && flag != 1)
	{
		for (int j = i; j < ALen; j++)
		{
			temp[k] = A[j];
			k++;
		}
	}
	return temp;
}