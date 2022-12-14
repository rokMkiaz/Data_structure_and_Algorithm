#include<stdio.h>


void Square(int Width, int Height) //�簢�� �׸���
{

	for (int i = 0; i < Height; ++i)
	{
		for (int j = 0; j < Width; ++j)
		{
			if (i == 0 || i == Height - 1)printf_s("*");
			else
			{
				if (j == 0 || j == Width - 1) printf_s("*");
				else printf_s(" ");
			}


		}
		printf_s("\n");

	}

}
int Mid(int a ,int b)
{
	if (a != b)return (a + b) / 2;
	else return -1;
}

int RecusiveBinSearch(int nArr[], int nBegin, int nEnd, int nTarget) //���� Ž�� ���
{
	int nMid = 0;

	if (nBegin > nEnd)
	{
		return -1;	//Ż�� ���� �� Ž�� ����
	}

	nMid = (nBegin + nEnd) / 2;

	if (nArr[nMid] == nTarget)
	{
		return nMid;			//Ÿ���� ã�Ҵ�.
	}
	else if (nTarget < nArr[nMid])
	{
		return RecusiveBinSearch(nArr, nBegin, nMid - 1, nTarget);
	}
	else
	{
		return RecusiveBinSearch(nArr, nMid + 1, nEnd, nTarget);
	}
}



int main()
{

	Square(4, 5);
	printf_s("\n\n");

	/// //////////////////////////////////////////////////////////////////////////

	int mid=Mid(1, 10);
	printf_s("�߰��� %d", mid);
	printf_s("\n\n");


    /// //////////////////////////////////////////////////////////////////////////

	int nArr[] = { 1, 3, 5, 7, 9, 11, 13 };
	int nResult;

	nResult = RecusiveBinSearch(nArr, 0, sizeof(nArr) / sizeof(int) - 1, 7);

	if (nResult == -1)
	{
		printf("���� �����ϴ�.\n");
	}
	else
	{
		for (int i = 0; i < sizeof(nArr) / sizeof(int); ++i)
		{
			printf("%d ", nArr[i]);
		}
		printf("\n%d��° �迭 ��ҿ� �ֽ��ϴ�.\n", nResult);
	}
	return 0;

}