/*
���� n�� �������� n�� ����� ������ �����Ϸ��� �մϴ�. 
�̶� n���κ����� �Ÿ��� ���ٸ� �� ū ���� �տ� ������ ��ġ�մϴ�. 
������ ��� �迭 numlist�� ���� n�� �־��� �� numlist�� ���Ҹ� n���κ��� 
����� ������� ������ �迭�� return�ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� n �� 10,000
1 �� numlist�� ���� �� 10,000
1 �� numlist�� ���� �� 100
numlist�� �ߺ��� ���Ҹ� ���� �ʽ��ϴ�.

* ����� ��
numlist							n		result
[1, 2, 3, 4, 5, 6]				4		[4, 5, 3, 6, 2, 1]
[10000,20,36,47,40,6,10,7000]	30		[36, 40, 20, 47, 10, 6, 7000, 10000]

* ����� �� #1
4���� ����� ������ [4, 5, 3, 6, 2, 1]�� return�մϴ�.
3�� 5�� �Ÿ��� �����Ƿ� �� ū 5�� �տ� �;� �մϴ�.
2�� 6�� �Ÿ��� �����Ƿ� �� ū 6�� �տ� �;� �մϴ�.

* ����� �� #2
30���� ����� ������ [36, 40, 20, 47, 10, 6, 7000, 10000]�� return�մϴ�.
20�� 40�� �Ÿ��� �����Ƿ� �� ū 40�� �տ� �;� �մϴ�.
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numlist, int n) 
{

    sort(numlist.begin(), numlist.end(), [n](const auto& a, const auto& b)->bool
        {
        if (abs(n - a) == abs(n - b))
        {
            return a > b;
        }
        return abs(n - a) < abs(n - b);
        });
    return numlist;
}
