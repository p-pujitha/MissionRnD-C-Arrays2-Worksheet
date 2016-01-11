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
#include<stdio.h>
#include<malloc.h>
int* convert_day_month_year(char *datee);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int *day, *month, *year, *arr, j = 0;
	day = (int*)malloc(sizeof(int)*len);
	month = (int*)malloc(sizeof(int)*len);
	year = (int*)malloc(sizeof(int)*len);
	for (int i = 0; i < len; i++)
	{
		arr = convert_day_month_year(Arr[i].date);
		day[j] = arr[0];
		month[j] = arr[1];
		year[j] = arr[2];
		j++;

	}
	int count = 0;
	int *date_arr = convert_day_month_year(date);
	int y = date_arr[2];
	for (int i = 0; i < len; i++)
	{
		if (year[i]>y)
		{
			count++;
		}
	}

	return count;

}

int* convert_day_month_year(char *datee)
{
	int day = 0, month = 0, year = 0;
	int count = 0;
	for (int i = 0; datee[i] != '\0';)
	{
		if (datee[i] != '-'){
			day = day * 10 + (datee[i] - '0');
			i++;
		}

		else
		{
			i++;
			if (count == 0)
			{
				while (datee[i] != '\0')
				{
					if (datee[i] != '-')
					{
						month = month * 10 + (datee[i] - '0');
						i++;
					}
					else{
						count = 1;
						break;
					}
				}

			}
			else if (count == 1)

			{
				while (datee[i] != '\0')
				{
					year = year * 10 + (datee[i] - '0');
					i++;
				}
				break;
			}
		}
	}
	int *a = (int*)malloc(sizeof(int) * 3);
	a[0] = day;
	a[1] = month;
	a[2] = year;

	return a;
}
