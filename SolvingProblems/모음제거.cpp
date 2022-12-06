/*
����� a, e, i, o, u �ټ� ���� ���ĺ��� �������� �з��մϴ�.
���ڿ� my_string�� �Ű������� �־��� �� ������ ������ ���ڿ��� return�ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
my_string�� �ҹ��ڿ� �������� �̷���� �ֽ��ϴ�.
1 �� my_string�� ���� �� 1,000

* ����� ��
my_string					result
"bus"						"bs"
"nice to meet you"			"nc t mt y"

* ����� �� #1
"bus"���� ���� u�� ������ "bs"�� return�մϴ�.

* ����� �� #1
"nice to meet you"���� ���� i, o, e, u�� ��� ������ "nc t mt y"�� return�մϴ�.
*/ 

#include <string>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (int i = 0; i < my_string.length(); i++) {
        char c = my_string[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
            answer += c;
    }
    return answer;
}
