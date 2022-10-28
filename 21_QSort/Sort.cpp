#include <Windows.h>
#include <stdio.h>
#include <algorithm>
#include "Timer.h"

void ReadData(int* datas)
{
	FILE* file=nullptr;
	fopen_s(&file, "RandData.txt", "r");
	{
		for (UINT i = 0; i < USHRT_MAX; i++)
			fscanf_s(file, "%d", &datas[i]);
	}
	fclose(file);
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int* datas, int left, int right)
{
	int first = left;
	int pivot = datas[first];

	left++; //피벗 다음꺼부터
	while (left <= right)//i <= j 와 같음
	{
		while (datas[left] <= pivot && left < right)
			left++;

		while (datas[right] > pivot && left <= right)
			right--;

		if (left < right)
			Swap(&datas[left], &datas[right]);
		else
			break;
	}

	Swap(&datas[first], &datas[right]);

	return right;
}

void QSort(int* datas, int left, int right)
{
	if (left < right)//분할시작
	{
		int index = Partition(datas, left, right);

		QSort(datas, left, index - 1);
		QSort(datas, index + 1, right);
	}
}

int Compare(const void* val1, const void* val2)
{
	int* left = (int*)val1;
	int* right = (int*)val2;

	if (*left > *right)
		return 1;
	else if (*left < *right)
		return -1;

	return 0;
}

bool Compare2(const int& val1, const int& val2)
{
	return val1 < val2;
}

void main()
{
	//QSort
	{
		int datas[USHRT_MAX];
		ReadData(datas);

		Timer timer;
		timer.Start();
		{
			QSort(datas, 0, USHRT_MAX - 1);
		}
		printf("소요 시간 : %f\n", timer.End());

		for (int i = 0; i < 50; i++)
			printf("%d ", datas[i]);
	}

	printf("\n\n");
	//QSort-  stdio.h의 C스타일임.
	{
		int datas[USHRT_MAX];
		ReadData(datas);

		Timer timer;
		timer.Start();
		{
			qsort(datas, sizeof(datas) / sizeof(int), sizeof(int), Compare);
		}
		printf("소요 시간 : %f\n", timer.End());

		for (int i = 0; i < 50; i++)
			printf("%d ", datas[i]);
	}

	printf("\n\n");
	//sort - C++ Style 많이 사용함.
	{
		int datas[USHRT_MAX];
		ReadData(datas);

		Timer timer;
		timer.Start();
		{
			std::sort(datas, datas + USHRT_MAX, Compare2);
		}
		printf("소요 시간 : %f\n", timer.End());

		for (int i = 0; i < 50; i++)
			printf_s("%d ", datas[i]);
	}
}