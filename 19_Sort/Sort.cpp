#include <stdio.h>
#include "Timer.h"

void BubbleSort(int* data, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - (i + 1); j++)
		{
			if (data[j] > data[j + 1])
			{
				int temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}//for(j)
	}//for(i)
}

void InsertionSort(int* data, int length)
{
	for (int i = 1; i < length; i++)
	{
		if (data[i - 1] <= data[i])
			continue;


		int value = data[i];

		for (int j = 0; j < i; j++)
		{
			if (data[j] > value)
			{
				memmove(&data[j + 1], &data[j], sizeof(data[0]) * (i - j));
				data[j] = value;

				break;
			}
		}//for(j)
	}//for(i)
}

void main()
{
	Timer timer;

	//Bubble
	{
		int dataSet[] = { 5, 1, 6, 4, 2, 3 };
		int length = sizeof(dataSet) / sizeof(dataSet[0]);


		printf("버블 정렬\n");

		for (int i = 0; i < length; i++)
			printf("%d ", dataSet[i]);

		printf("\n");

		timer.Start();
		BubbleSort(dataSet, length);
		float t = timer.End();

		for (int i = 0; i < length; i++)
			printf("%d ", dataSet[i]);

		printf("\n수행시간 : %f\n", t);

		printf("\n\n");
	}


	//Insertion
	{
		int dataSet[] = { 5, 1, 6, 4, 2, 3 };
		int length = sizeof(dataSet) / sizeof(dataSet[0]);
	
	
		printf("삽입 정렬\n");
	
		for (int i = 0; i < length; i++)
			printf("%d ", dataSet[i]);
	
		printf("\n");
	
		timer.Start();
		InsertionSort(dataSet, length);
		float t = timer.End();
	
		for (int i = 0; i < length; i++)
			printf("%d ", dataSet[i]);
	
		printf("\n수행시간 : %f\n", t);
	
		printf("\n\n");
	}
}