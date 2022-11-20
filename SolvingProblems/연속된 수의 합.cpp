/*
���ӵ� �� ���� ������ ���� 12�� �Ǵ� ���� 3, 4, 5�Դϴ�. �� ���� num�� total�� �־����ϴ�.
���ӵ� �� num���� ���� ���� total�� �� ��, ���� �迭�� ������������ ��� return�ϵ���
solution�Լ��� �ϼ��غ�����.

* ���ѻ���
1 �� num �� 100
0 �� total �� 1000
num���� ���ӵ� ���� ���Ͽ� total�� �� �� ���� �׽�Ʈ ���̽��� �����ϴ�.

* ����� ��
num			total			result
3			12				[3, 4, 5]
5			15				[1, 2, 3, 4, 5]
4			14				[2, 3, 4, 5]
5			5				[-1, 0, 1, 2, 3]


* ����� �� #1
num = 3, total = 12�� ��� [3, 4, 5]�� return�մϴ�.

* ����� �� #2
num = 5, total = 15�� ��� [1, 2, 3, 4, 5]�� return�մϴ�.

* ����� �� #3
4���� ���ӵ� ���� ���� 14�� �Ǵ� ���� 2, 3, 4, 5�Դϴ�.

1. num�� ¦���� ���, �߰����� �������� ������ ���̰� �ٸ��ϴ�.
(total/num)-(num/2)+1�� idx�� ����

2.num�� Ȧ���� ���, �߰����� �������� ������ ���̰� �����ϴ�.
(total/num)-(num/2)�� idx�� ����

3.������ ������ (total/num)+(num/2)���� answer�� �����մϴ�.
ex) num=3, total=12 -> total/num=4, num/2=1 -> Ȧ���̱� ������ 3���� 5���� ����

*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) 
{
    vector<int> answer;
    int n = total / num;
    int m = num / 2;
    int idx = 0;

    if (num % 2 == 0) idx = n - m + 1;
    else idx = n - m;

    for (int i = idx; i <= n + m; i++)
        answer.push_back(i);

    return answer;
}