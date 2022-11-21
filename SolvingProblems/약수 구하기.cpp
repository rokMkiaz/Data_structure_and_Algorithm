/*
���� n�� �Ű������� �־��� ��, n�� ����� ������������ ���� �迭�� return�ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� n �� 10, 000

* ����� ��
n	        result
24          [1, 2, 3, 4, 6, 8, 12, 24]
29          [1, 29]

* ����� �� #1
24�� ����� ������������ ���� �迭[1, 2, 3, 4, 6, 8, 12, 24]�� return�մϴ�.

* ����� �� #2
29�� ����� ������������ ���� �迭[1, 29]�� return�մϴ�.
*/


#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    for (int i = 1; i <= n; i++) if (n % i == 0) answer.push_back(i);
    return answer;
}