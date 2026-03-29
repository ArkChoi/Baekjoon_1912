//Baekjoon 1912 
//Brute Force
#include <iostream>
#define inf 1001

int Input();
int Mcss1(int* a, int n);

int main()
{
	int AllDataSize;

	AllDataSize = Input();

	int *Data = new int[AllDataSize];

	for (int i = 0; i < AllDataSize; i++)
	{
		Data[i] = Input();
	}

	int MaxSum = Mcss1(Data, AllDataSize);

	std::cout << MaxSum << std::endl;

	return 0;
}

int Input()
{
	int InputNumber = 0;

	std::cin >> InputNumber;

	return InputNumber;
}

int Mcss1(int* a, int n)
{
	int MaxSum = -inf;
	for (int i = 0; i < n; i++)
	{
		for (int j = i ; j < n ; j++)
		{
			int Sum = 0;
			for (int k = i; k <= j; k++)
			{
				Sum += a[k];
			}
			if (Sum > MaxSum)
			{
				MaxSum = Sum;
			}
		}
	}
	return MaxSum;
}

//의사코드
//Mcss1(a, n)
//MaxSum = -inf;
//for i = 0, ..., n - 1
//for j = i, ..., n - 1
//Sum = 0
//for k = i, ..., j
//Sum += a[j];
//if (Sum > MaxSum)
//MaxSum = Sum;
//return MaxSum;

//시간복잡도
//O(n^3)