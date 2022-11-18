/*
* ���� ī�� ������
ö���� ����� ���������κ��� ���ڰ� �ϳ��� ���� ī����� ���ݾ� ������ ���� ��,
���� �� ���� �� �ϳ��� �����ϴ� ���� ū ���� ���� a�� ���� ���Ϸ��� �մϴ�.

ö���� ���� ī��鿡 ���� ��� ���ڸ� ���� �� �ְ� ���� ���� ī��鿡 ���� ��� ���ڵ� �� �ϳ��� ���� �� ���� ���� ���� a
���� ���� ī��鿡 ���� ��� ���ڸ� ���� �� �ְ�, ö���� ���� ī��鿡 ���� ��� ���ڵ� �� �ϳ��� ���� �� ���� ���� ���� a
���� ���, ī��鿡 10, 5, 20, 17�� ���� �ִ� ��쿡 ���� ������ ���ô�. 
����, ö���� [10, 17]�� ���� ī�带 ����, ���� [5, 20]�� ���� ī�带 ���´ٸ� �� ���� �� �ϳ��� �����ϴ� 
���� ���� a�� �������� �ʽ��ϴ�. ������, ö���� [10, 20]�� ���� ī�带 ����, ���� [5, 17]�� ���� ī�带 ���´ٸ�, 
ö���� ���� ī����� ���ڴ� ��� 10���� ���� �� �ְ�, ���� ���� ī����� ���ڴ� ��� 10���� ���� �� �����ϴ�. 
���� ö���� ����� ���� [10, 20]�� ���� ī��, [5, 17]�� ���� ī��� ���� �����ٸ� ���ǿ� �ش��ϴ� ���� ���� a�� 10�� �˴ϴ�.

ö���� ���� ī�忡 ���� ���ڵ��� ��Ÿ���� ���� �迭 arrayA�� ���� ���� ī�忡 ���� ���ڵ��� ��Ÿ���� ����
�迭 arrayB�� �־����� ��, �־��� ������ �����ϴ� ���� ū ���� ���� a�� return�ϵ��� solution �Լ��� �ϼ��� �ּ���.
����, ������ �����ϴ� a�� ���ٸ�, 0�� return �� �ּ���.
* ���ѻ���

1 �� arrayA�� ���� = arrayB�� ���� �� 500,000
1 �� arrayA�� ����, arrayB�� ���� �� 100,000,000
arrayA�� arrayB���� �ߺ��� ���Ұ� ���� �� �ֽ��ϴ�.

* ����� ��
arrayA	         arrayB  	    result
[10, 17]	    [5, 20]     	  0
[10, 20]	    [5, 17]     	  10
[14, 35, 119]	[18, 30, 102]	  7

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> candidate, my, other;

void find_candidate(int num)//��� ã��
{ 
    candidate.push_back(num);
    for (int i = num / 2; i > 1; i--) //my�� �ּ� ���� num�� ����� ã��
        if (num % i == 0) candidate.push_back(i);

}

int check()
{
    int ret = 0;
    for (auto c : candidate) 
    {
        int flag = 1;
        for (int i = 0; i < my.size(); i++) 
        {
            if (my[i] % c != 0 || other[i] % c == 0) 
            { 
                flag = 0;
                break; //�̹� ������ �������� ���ϹǷ� ������ �˻� x
            }
        }
        //�ĺ����� ������������ ���ĵ� �����Ƿ� ã������ �ٷ� ����
        if (flag) {
            ret = c;
            break;
        }
    }
    return ret; //ret �ʱⰪ�� 0�̹Ƿ� ������ �����ϴ� ���� ã�� ���ϸ� 0�� ��ȯ��.
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int answer = 0;
    sort(arrayA.begin(), arrayA.end()); 
    sort(arrayB.begin(), arrayB.end());

    find_candidate(arrayA[0]);
    my = arrayA, other = arrayB;
    answer = max(answer, check());

    candidate.clear();
    my = arrayB, other = arrayA;
    find_candidate(arrayB[0]);
    answer = max(answer, check());

    return answer; //answer �ʱⰪ�� 0�̹Ƿ� ������ �����ϴ� a�� ã�� ���ϸ� 0�� ��ȯ��.
}