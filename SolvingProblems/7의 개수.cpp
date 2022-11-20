/*
�Ӿ��̴� ����� ���� 7�� ���� �����մϴ�. ���� �迭 array�� �Ű������� �־��� ��, 
7�� �� �� �� �ִ��� return �ϵ��� solution �Լ��� �ϼ��غ�����.

* ���ѻ���
1 �� array�� ���� �� 100
0 �� array�� ���� �� 100,000

* ����� ��
array	        result
[7, 77, 17]	    4
[10, 29]	    0


* ����� �� #1
[7, 77, 17]���� 7�� 4�� �����Ƿ� 4�� return �մϴ�.

* ����� �� #2
[10, 29]���� 7�� �����Ƿ� 0�� return �մϴ�.

*/


#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for (auto num : array)
    {
        while (num > 0)
        {
            if ((num % 10) == 7)
                answer++;
            num = num / 10;
        }
    }
    return answer;
}
