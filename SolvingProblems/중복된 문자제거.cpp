/*
���ڿ� my_string�� �Ű������� �־����ϴ�. my_string���� �ߺ��� ���ڸ� �����ϰ� 
�ϳ��� ���ڸ� ���� ���ڿ��� return�ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� my_string �� 110
my_string�� �빮��, �ҹ���, �������� �����Ǿ� �ֽ��ϴ�.
�빮�ڿ� �ҹ��ڸ� �����մϴ�.
����(" ")�� �ϳ��� ���ڷ� �����մϴ�.
�ߺ��� ���� �� ���� �տ� �ִ� ���ڸ� ����ϴ�.

* ����� ��
my_string				result
"people"				"peol"
"We are the world"		"We arthwold"

* ����� �� #1
"people"���� �ߺ��� ���� "p"�� "e"�� ������ "peol"�� return�մϴ�.

* ����� �� #2
"We are the world"���� �ߺ��� ���� "e", " ", "r" ���� ������ "We arthwold"�� return�մϴ�.

*/
#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for (auto i : my_string) {
        if (answer.find(i) == string::npos)answer += i;
    }
    return answer;
}
