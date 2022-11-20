/*
���� n�� ���� �迭 numlist�� �Ű������� �־��� ��, 
numlist���� n�� ����� �ƴ� ������ ������ �迭�� return�ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� n �� 10,000
1 �� numlist�� ũ�� �� 100
1 �� numlist�� ���� �� 100,000

����� ��
n	             numlist	                                    result
3	             [4, 5, 6, 7, 8, 9, 10, 11, 12]              	[6, 9, 12]
5	             [1, 9, 3, 10, 13, 5]	                        [10, 5]
12	             [2, 100, 120, 600, 12, 12]	                    [120, 600, 12, 12]

* ����� �� #1
numlist���� 3�� ������� ���� [6, 9, 12]�� return�մϴ�.

* ����� �� #2
numlist���� 5�� ������� ���� [10, 5]�� return�մϴ�.

* ����� �� #3
numlist���� 12�� ������� ���� [120, 600, 12, 12]�� return�մϴ�.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;

    for (int i = 0; i < numlist.size(); i++) {
        if (numlist[i] % n == 0) {
            answer.push_back(numlist[i]);
        }
    }

    return answer;
}