/*
������ ��� �ִ� �迭 num_list�� �Ű������� �־����ϴ�. num_list�� ������ ������ �Ųٷ� 
������ �迭�� return�ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� num_list�� ���� �� 1,000
0 �� num_list�� ���� �� 1,000

* ����� ��
num_list				result
[1, 2, 3, 4, 5]			[5, 4, 3, 2, 1]
[1, 1, 1, 1, 1, 2]		[2, 1, 1, 1, 1, 1]
[1, 0, 1, 1, 1, 3, 5]	[5, 3, 1, 1, 1, 0, 1]


* ����� �� #1
num_list�� [1, 2, 3, 4, 5]�̹Ƿ� ������ �Ųٷ� ������ �迭 [5, 4, 3, 2, 1]�� return�մϴ�.

* ����� �� #2
num_list�� [1, 1, 1, 1, 1, 2]�̹Ƿ� ������ �Ųٷ� ������ �迭 [2, 1, 1, 1, 1, 1]�� return�մϴ�.

* ����� �� #3
num_list�� [1, 0, 1, 1, 1, 3, 5]�̹Ƿ� ������ �Ųٷ� ������ �迭 [5, 3, 1, 1, 1, 0, 1]�� return�մϴ�.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    for (int i = num_list.size() - 1; i >= 0; i--) {
        answer.push_back(num_list[i]);
    }
    return answer;
}
