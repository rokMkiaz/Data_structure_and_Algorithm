/*
���� ���� x�� ���� �Լ� f(x)�� ������ ���� �����մϴ�.

x���� ũ�� x�� ��Ʈ�� 1~2�� �ٸ� ���� �߿��� ���� ���� ��
���� ���,

f(2) = 3 �Դϴ�. ���� ǥ�� ���� 2���� ū ���� �߿��� ��Ʈ�� �ٸ� ������ 2�� �����̸鼭 
���� ���� ���� 3�̱� �����Դϴ�.
��		��Ʈ	�ٸ�			��Ʈ�� ����
2		000...0010
3		000...0011		1

f(7) = 11 �Դϴ�. ���� ǥ�� ���� 7���� ū ���� �߿��� ��Ʈ�� �ٸ� ������ 2�� 
�����̸鼭 ���� ���� ���� 11�̱� �����Դϴ�.
��			��Ʈ	�ٸ�			��Ʈ�� ����
7			000...0111
8			000...1000		4
9			000...1001		3
10			000...1010		3
11			000...1011		2

�������� ��� �迭 numbers�� �Ű������� �־����ϴ�. numbers�� ��� ���鿡 ���Ͽ� 
�� ���� f ���� �迭�� ���ʴ�� ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� numbers�� ���� �� 100,000
0 �� numbers�� ��� �� �� 1015

* ����� ��
numbers			result
[2,7]			[3,11]

*/
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int count = 0;
    long long copy;
    for (long long func : numbers) {
        copy = func;
        while (1) {
            if (copy & 1) {
                copy = copy >> 1;
                count++;
            }
            else {
                if (count) answer.push_back(func + pow(2, count - 1));
                else answer.push_back(func + 1);
                break;
            }
        }
        count = 0;
    }
    return answer;
}