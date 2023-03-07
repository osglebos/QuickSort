#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void PrintArr(int *arr, int n)
{
	for (int x = 0; x < n; x++)
		printf("%i ", arr[x]);
	printf("\n");
}

int Partition(int *arr, int l, int r)
{
	int i = l, j = r;
	int x = arr[(r + l) / 2];
	while (i <= j)
	{
		if (arr[i] < x)			i++;
		else if (x < arr[j])	j--;
		else					Swap(&arr[i++], &arr[j--]);
	}
	return i - 1;
}

void QSort(int *arr, int l, int r)
{
	int m;
	if (l >= r) return;
	m = Partition(arr, l, r);
	QSort(arr, l, m);
	QSort(arr, m + 1, r);
}

void RandomFill(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
}

int main(void)
{
	int *arr = NULL;
	int n = 0;

	bool exit = false;
	char key;

	printf("ÉÍÍÍËÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n");
	printf("ºescºExit		º\n");
	printf("º1  ºPrint array	º\n");
	printf("º2  ºCreate array	º\n");
	printf("º3  ºQuick sort		º\n");
	printf("ÈÍÍÍÊÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n");

	while (!exit)
	{

		key = _getch();
		switch (key)
		{
		case 27:
			printf("Exit.\n");
			exit = true;
			break;

		case '1':
			PrintArr(arr, n);
			break;

		case '2':
		{
			printf("Input number of elements to create array: ");
			scanf("%i", &n);
			arr = new int[n];
			RandomFill(arr, n);
			break;
		}

		case '3':
		{
			QSort(arr, 0, n - 1);
			break;
		}

		default:
			printf("Wrong symbol\n");
			break;
		}
	}
	return 0;
}