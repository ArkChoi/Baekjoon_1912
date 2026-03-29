//Baekjoon 1912 
//Brute Force
#include <iostream>
#define inf 1001

int Input();
int Mcss2(int* a, int n);

int main()
{
	int AllDataSize;

	AllDataSize = Input();

	int *Data = new int[AllDataSize];

	for (int i = 0; i < AllDataSize; i++)
	{
		Data[i] = Input();
	}

	int MaxSum = Mcss2(Data, AllDataSize);

	std::cout << MaxSum << std::endl;

	return 0;
}

int Input()
{
	int InputNumber = 0;

	std::cin >> InputNumber;

	return InputNumber;
}

int Mcss2(int* a, int n)
{
	int MaxSum = -inf;
	for (int i = 0; i < n; i++)
	{
		int Sum = 0;
		for (int j = i ; j < n ; j++)
		{
			Sum += a[j];
			if (Sum > MaxSum)
			{
				MaxSum = Sum;
			}
		}
	}
	return MaxSum;
}

//의사코드
//mcss2(a, n)
//max_sum = -∞
//for i = 0, ..., n - 1
////시작점이 i인 경우의 최대 연속합 구하기
//sum = 0
//for j = i, ..., n - 1
//sum += a[j]
//if (sum > max_sum)
//max_sum = sum
//return max_sum

//시간복잡도
//O(n^2)