/*
���� �迭 array�� ���� n�� �Ű������� �־��� ��,
array�� ����ִ� ���� �� n�� ���� ����� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� array�� ���� �� 100
1 �� array�� ���� �� 100
1 �� n �� 100
���� ����� ���� ���� ���� ��� �� ���� ���� return �մϴ�.

* ����� ��
array				n			result
[3, 10, 28]			20			28
[10, 11, 12]		13			12

* ����� �� #1
3, 10, 28 �� 20�� ���� ����� ���� 28�Դϴ�.

* ����� �� #2
10, 11, 12 �� 13�� ���� ����� ���� 12�Դϴ�.

*/


#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> array, int n)
{
    return *min_element(begin(array), end(array), [&](int a, int b) 
        {
            return abs(a - n) * 2 < abs(b - n) * 2 + (a < b);
        });
}