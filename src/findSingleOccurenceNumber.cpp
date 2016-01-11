/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL || len < 0)
		return -1;


	int j = 0, b[10], flag = 0;

	for (int i = 0; i<len; i++)
	{
		for (int k = 0; k<j; k++)
		{
			if (A[i] == b[k])
			{
				flag = 1;
				break;
			}
			else
			{
				flag = 0;
			}
		}
		if (flag == 0)
		{
			b[j] = A[i];
			j++;
		}
		if (flag == 1)
			flag = 0;
	}
	/*for (int i = 0; i<j; i++)
	printf("%d", b[i]);*/
	int count = 0;
	for (int i = 0; i<j; i++)
	{
		for (int k = 0; k<len; k++)
		{
			if (b[i] == A[k])
				count++;
		}
		if (count == 1)
		{
			return b[i];
		}
		else
			count = 0;
	}


}