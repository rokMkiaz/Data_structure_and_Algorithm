/*
���ڿ� s�� �Ű������� �־����ϴ�. s���� �� ���� �����ϴ� ���ڸ� ���� ������ ������ ���ڿ���
return �ϵ��� solution �Լ��� �ϼ��غ�����. �� ���� �����ϴ� ���ڰ� ���� ��� �� ���ڿ��� return �մϴ�.

* ���ѻ���
0 < s�� ���� < 1,000
s�� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.


* ����� ��
s	                            result
"abcabcadc"	                    "d"
"abdc"	                        "abcd"
"hello"	                        "eho"

* ����� �� #1
"abcabcadc"���� �ϳ��� �����ϴ� ���ڴ� "d"�Դϴ�.

* ����� �� #2
"abdc"���� ��� ���ڰ� �� ���� �����ϹǷ� ���� ������ ������ "abcd"�� return �մϴ�.

* ����� �� #3
"hello"���� �� ���� ������ ���ڴ� "heo"�̰� �̸� ���� ������ ������ "eho"�� return �մϴ�.

*/



#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string s) {
    string answer = "";

    map<char, int> m;
    for (const auto v : s)
    {
        m[v]++;
    }

    for (const auto& v : m)
    {
        if (v.second == 1)
        {
            answer.push_back(v.first);
        }
    }
    return answer;
}