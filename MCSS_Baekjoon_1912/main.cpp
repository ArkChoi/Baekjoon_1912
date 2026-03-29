//Baekjoon 1912 
//Merge Sort
#include <iostream>
#define inf 1001

int Input();
int Mcss3(int* a, int low, int high);
int CrossSum(int* a, int low, int mid, int high);
int Max(int InLeftSum, int InRightSum, int InTwoSidedSum);

int main()
{
	int AllDataSize;

	AllDataSize = Input();

	int *Data = new int[AllDataSize];

	for (int i = 0; i < AllDataSize; i++)
	{
		Data[i] = Input();
	}

	int MaxSum = Mcss3(Data, 0, (AllDataSize - 1) );

	std::cout << MaxSum << std::endl;

	return 0;
}

int Input()
{
	int InputNumber = 0;

	std::cin >> InputNumber;

	return InputNumber;
}

int Mcss3(int* a, int low, int high)
{
	if (low == high)
	{
		return a[low];
	}

	int mid = (low + high) / 2;

	int LeftSum = Mcss3(a, low, mid);
	int RightSum = Mcss3(a, mid + 1, high);
	int TwoSidedSum = CrossSum(a, low, mid, high);
	return Max(LeftSum, RightSum, TwoSidedSum);
}

int CrossSum(int* a, int low, int mid, int high)
{
	int LSum = -inf;
	int RSum = -inf;
	int Sum = 0;

	for (int i = mid ; i >= low; i--)
	{
		Sum += a[i];
		if (Sum > LSum)
		{
			LSum = Sum;
		}
	}

	Sum = 0;

	for (int i = mid + 1; i <= high; i++)
	{
		Sum += a[i];
		if (Sum > RSum)
		{
			RSum = Sum;
		}
	}

	return LSum + RSum;
}

int Max(int InLeftSum, int InRightSum, int InTwoSidedSum)
{
	int MaxSum = -inf;

	if (InLeftSum > MaxSum)
	{
		MaxSum = InLeftSum;
	}
	if (InRightSum > MaxSum)
	{
		MaxSum = InRightSum;
	}
	if (InTwoSidedSum > MaxSum)
	{
		MaxSum = InTwoSidedSum;
	}

	return MaxSum;
}

//의사코드
//MCSS3(a, low, high)
//if (low == high) return a[low]
//mid = (low, hgih) / 2
//left_sum = MCSS3(a, low, mid)
//right_sum = MCSS3(a, mid + 1, high)
//tow_sided_sum = cross_sum(a, low, mid, high)
//return Max(left_sum, right_sum, tow_sided_sum)
//
//cross_sum(a, low, mid, high)
//lsum = sum = a[mid]
//for i = mid - 1, mid - 2, ..., low
//sum += a[i]
//if (sum > lsum) lsum = sum
//rsum = sum = a[mid + 1]
//for i = mid + 2, mid + 3, ..., hgih
//sum += a[i]
//if (sum > rsum) rsum = sum
//return lsum + rsum

//시간복잡도
//O(n log n)