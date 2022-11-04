#include<stdio.h>
#include<Windows.h>
#include<time.h>

void Shuffle(int* array, int num) //����
{
	for (int i = 0; i < 100; ++i)
	{
		int src = rand() % num;
		int dest = rand() % num;
		if (src == dest)continue; //�������� return ���������� �ϴ� ����..����(100ȸ �ȼ���)
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
	//Factorial�� ����Լ��� �ۼ�

	printf_s("Factorial : %d", Factorial(5));


	printf_s("\n---------------------------------------\n\n");
	//3�� ����� "F" , 5�� ����� "G", �Ѵ��� ����� ��� "F_G" ���
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