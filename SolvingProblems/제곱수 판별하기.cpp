/*
� �ڿ����� �������� �� ������ ������ ��������� �մϴ�. 
���� n�� �Ű������� �־��� ��, n�� ��������� 1�� �ƴ϶�� 2�� return�ϵ��� solution �Լ��� �ϼ����ּ���.


* ���ѻ���
1 �� n �� 1,000,000

����� ��
n			result
144			1
976			2

* ����� �� #1
144�� 12�� �����̹Ƿ� �������Դϴ�. ���� 1�� return�մϴ�.

* ����� �� #2
976�� �������� �ƴմϴ�. ���� 2�� return�մϴ�.

*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (i * i == n) return 1;
    }

    return 2;
}
