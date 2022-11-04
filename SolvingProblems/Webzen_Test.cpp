#include<stdio.h>
#include<Windows.h>
#include<time.h>

void Shuffle(int* array, int num) //셔플
{
	for (int i = 0; i < 100; ++i)
	{
		int src = rand() % num;
		int dest = rand() % num;
		if (src == dest)continue; //시험지에 return 으로했지만 일단 섞임..읍읍(100회 안섞임)
		int temp = array[src];
		array[src] = array[dest];
		array[dest] = temp;

		if (i == 99)printf_s("%d\n", i);
	}
}

int Factorial(int num)
{
	if (num <= 1) return 1;

	return num * Factorial(num - 1);
}


int main()
{
	//Shuffle
	srand(time(NULL));

	int i[] = { 1,2,3,4,5,6,7,8,9,10 };
	Shuffle(i, 10);
	for (int j = 0; j < 10; j++)
	{
		printf_s("%d    ", i[j]);
	}

	printf_s("\n---------------------------------------\n\n");
	//Factorial을 재귀함수로 작성

	printf_s("Factorial : %d", Factorial(5));


	printf_s("\n---------------------------------------\n\n");
	//3의 배수시 "F" , 5의 배수시 "G", 둘다의 배수일 경우 "F_G" 출력
	for (int i = 1; i <= 100; ++i)
	{
		printf_s("%d", i);
		if (i % 15 == 0)printf_s(" F_G\n");
		else if (i % 3 == 0)printf_s(" F\n");
		else if (i % 5 == 0)printf_s(" G\n");
		else printf_s("\n");

	}

	return 0;
}