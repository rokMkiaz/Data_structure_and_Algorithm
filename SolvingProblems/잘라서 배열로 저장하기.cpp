/*
���ڿ� my_str�� n�� �Ű������� �־��� ��, my_str�� ���� n�� �߶� ������ �迭�� return�ϵ���
solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� my_str�� ���� �� 100
1 �� n �� my_str�� ����
my_str�� ���ĺ� �ҹ���, �빮��, ���ڷ� �̷���� �ֽ��ϴ�.

* ����� ��
my_str          	        n	            result
"abc1Addfggg4556b"	        6	            ["abc1Ad", "dfggg4", "556b"]
"abcdef123"	                3	            ["abc", "def", "123"]


* ����� �� #1
"abc1Addfggg4556b" �� ���� 6�� �߶� �迭�� ������ ["abc1Ad", "dfggg4", "556b"]�� return�ؾ� �մϴ�.

* ����� �� #2
"abcdef123" �� ���� 3�� �߶� �迭�� ������ ["abc", "def", "123"]�� return�ؾ� �մϴ�.

* ���ǻ���
����� �� #1�� ��� "abc1Addfggg4556b"�� ���� 6�� �ڸ��� "abc1Ad", "dfggg4" �ΰ��� ������ "556b"�� �����ϴ�.
�̷� ��� ���� ���ڿ��� �״�� �迭�� �����մϴ�.

*/



#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) 
{
    vector<string> answer;
    for (int i = 0; i < my_str.length(); i += n) {
        answer.push_back(my_str.substr(i, n));
    }
    return answer;
}
