/*
���ڿ� before�� after�� �Ű������� �־��� ��, before�� ������ �ٲپ� after�� ���� �� ������ 1��,
���� �� ������ 0�� return �ϵ��� solution �Լ��� �ϼ��غ�����.

* ���ѻ���
0 < before�� ���� == after�� ���� < 1, 000
	before�� after�� ��� �ҹ��ڷ� �̷���� �ֽ��ϴ�.

*����� ��
before	after	result
"olleh"	"hello"	1
"allpe"	"apple"	0


* ����� �� #1
"olleh"�� ������ �ٲٸ� "hello"�� ���� �� �ֽ��ϴ�.

* ����� �� #2
"allpe"�� ������ �ٲ㵵 "apple"�� ���� �� �����ϴ�.

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string before, string after) {
    int answer = 1;

    sort(before.begin(), before.end());
    sort(after.begin(), after.end());

    if (before != after) answer = 0;

    return answer;
}