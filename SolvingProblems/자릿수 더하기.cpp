/*
���� n�� �Ű������� �־��� �� n�� �� �ڸ� ������ ���� return�ϵ��� solution �Լ��� �ϼ����ּ���

* ���ѻ���
0 �� n �� 1,000,000


* ����� ��
n	        result
1234	    10
930211	    16

* ����� �� #1
1 + 2 + 3 + 4 = 10�� return�մϴ�.

* ����� �� #2
9 + 3 + 0 + 2 + 1 + 1 = 16�� return�մϴ�.


*/
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    while (n != 0) {
        answer += n % 10;
        n /= 10;
    }
    return answer;
}