//Baekjoon 1912 
//Brute Force
#include <iostream>
#define inf 1001

int Mcss1(int* a, int n);

int main()
{

	std::cout << "HelloWorld" << std::endl;

	return 0;
}

int Mcss1(int* a, int n)
{
	int MaxSum = -inf;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			int Sum = 0;
			for (int k = 0; k < j; k++)
			{

			}
		}
	}
}

for i = 0, ..., n - 1
for j = i, ..., n - 1
Sum = 0
for k = i, ..., j
Sum += a[j];
if (Sum > MaxSum)
MaxSum = Sum;
return MaxSum;