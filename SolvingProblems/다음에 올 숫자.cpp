/*
�������� Ȥ�� ������ common�� �Ű������� �־��� ��,
������ ���� �������� �� ���ڸ� return �ϵ��� solution �Լ��� �ϼ��غ�����.

* ���ѻ���
2 < common�� ���� < 1,000
-1,000 < common�� ���� < 2,000
�������� Ȥ�� �������� �ƴ� ���� �����ϴ�.
���� 0�� ���� �����ϴ�.


* ����� ��
common				result
[1, 2, 3, 4]		5
[2, 4, 8]			16


* ����� �� #1
[1, 2, 3, 4]�� ������ 1�� ���������̹Ƿ� ������ �� ���� 5�̴�.

* ����� �� #2
[2, 4, 8]�� ���� 2�� �������̹Ƿ� ������ �� ���� 16�̴�.


���& �������� �˻�
*/


#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    if (common[0] - common[1] == common[1] - common[2]) { //������ ���
        return common.back() - (common[0] - common[1]);
    }
    else {
        return common.back() * (common[1] / common[0]); //����� ���
    }
    return answer;
}
