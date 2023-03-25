#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, N, Low, High, 0);
	if (rowNo < N - 1)
		CreateRows(a, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, N, colNo + 1);
	else
		cout << endl;
}

void PrintRows(int** a, const int N, int rowNo)
{
	PrintRow(a, rowNo, N, 0);
	if (rowNo < N - 1)
		PrintRows(a, N, rowNo + 1);
	else
		cout << endl;
}

int Sum(int** a, const int rowCount, const int colCount, int& S, int i, int j, int max)
{
	if (i < rowCount)
	{
		if (i % 2 == 0)
		{
			if (a[i][j] > max)
				max = a[i][j];
			if (j < colCount - 1)
				return Sum(a, rowCount, colCount, S, i, j + 1, max);
			else
			{
				S += max;
				return Sum(a, rowCount, colCount, S, i + 1, 0, 0);
			}
		}
		else
			return Sum(a, rowCount, colCount, S, i + 1, 0, 0);
	}
	return S;
}

int main()
{
	srand((unsigned)time(NULL));
	int N = 5;
	int** a = new int* [N];
	for (int i = 0; i < N; i++)
		a[i] = new int[N];
	int Low = 1, High = 25;
	CreateRows(a, N, Low, High, 0);
	PrintRows(a, N, 0);
	int S = 0;
	cout << Sum(a, N, N, S, 0, 0, 0) << endl;
	for (int i = 0; i < N; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}