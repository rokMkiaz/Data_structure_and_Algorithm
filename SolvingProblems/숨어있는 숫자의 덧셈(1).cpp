
/*
���ڿ� my_string�� �Ű������� �־����ϴ�.my_string���� ��� �ڿ������� ����
return�ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� my_string�� ���� �� 1, 000
my_string�� �ҹ���, �빮�� �׸��� ���ڸ� �ڿ����θ� �����Ǿ��ֽ��ϴ�.

* ����� ��
my_string	        result
"aAb1B2cC34oOp" 	10
"1a2b3c4d123"	    16

* ����� �� #1
"aAb1B2cC34oOp"���� ���ڸ� �ڿ����� 1, 2, 3, 4 �Դϴ�.���� 1 + 2 + 3 + 4 = 10 �� return�մϴ�.

* ����� �� #2
"1a2b3c4d123Z"���� ���ڸ� �ڿ����� 1, 2, 3, 4, 1, 2, 3 �Դϴ�.���� 1 + 2 + 3 + 4 + 1 + 2 + 3 = 16 �� return�մϴ�.

* ���ǻ���
���ӵ� ���ڵ� ���� �� �ڸ� ���ڷ� ����մϴ�.
*/

#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for (const auto v : my_string)
    {
        if (isdigit(v)) //���ڸ� �Ǵ��ϴ� �Լ�
        {
            answer += v - '0';
        }
    }
    return answer;
}