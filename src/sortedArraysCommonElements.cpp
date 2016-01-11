/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
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
int equality(char A[], char B[]);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction temp[10];
	int flag = 0, i, j, k = 0;
	for (i = 0; i<ALen; i++)
	{
		for (j = 0; j<BLen; j++)
		{
			if (A[i].amount == B[j].amount)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			int ans = equality(A[i].date, B[i].date);// if equality(description and date of A[i], description and date of B[i])==1 
			// means we can add that Variable in our common variables
			if (ans == 1)

			{
				int des = equality(A[i].description, B[i].description);
				temp[k] = A[i];
				k++;
				flag = 0;

			}
			else
				flag = 0;

		}
	}
	if (k == 0)
		return NULL;
	else
		return temp;
}

int equality(char A[], char B[])
{
	int flag = 0;
	for (int i = 0; A[i] != '\0';)
	{
		if (A[i] == B[i])
		{
			flag = 1;
			i++;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		return 1;
	else
		return 0;
}
