/*
���ڿ� s�� �ԷµǾ��� �� ���� ��Ģ�� ���� �� ���ڿ��� ���� ���ڿ��� �����Ϸ��� �մϴ�.

���� ù ���ڸ� �н��ϴ�. �� ���ڸ� x��� �սô�.
���� �� ���ڿ��� ���ʿ��� ���������� �о���鼭, x�� x�� �ƴ� �ٸ� ���ڵ��� ���� Ƚ���� ���� ���ϴ�.
ó������ �� Ƚ���� �������� ���� ���߰�, ���ݱ��� ���� ���ڿ��� �и��մϴ�.
s���� �и��� ���ڿ��� ���� ���� �κп� ���ؼ� �� ������ �ݺ��մϴ�. ���� �κ��� ���ٸ� �����մϴ�.
���� �� Ƚ���� �ٸ� ���¿��� �� �̻� ���� ���ڰ� ���ٸ�, ���� ���ݱ��� ���� ���ڿ��� �и��ϰ�, �����մϴ�.
���ڿ� s�� �Ű������� �־��� ��, �� ������ ���� ���ڿ���� �����ϰ�, ������ ���ڿ��� ������ 
return �ϴ� �Լ� solution�� �ϼ��ϼ���.

* ���ѻ���
1 �� s�� ���� �� 10,000
s�� ���� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.

* ����� ��
s					result
"banana"			3
"abracadabra"		6
"aaabbaccccabba"	3


* ����� �� #1
s="banana"�� ��� ba - na - na�� ���� ���ص˴ϴ�.

* ����� �� #2
s="abracadabra"�� ��� ab - ra - ca - da - br - a�� ���� ���ص˴ϴ�.

* ����� �� #3
s="aaabbaccccabba"�� ��� aaabbacc - ccab - ba�� ���� ���ص˴ϴ�.
*/

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0, nFirst = 1, nSecond = 0, nTmp = 0;
    char x = s[0];
    bool bBool = false;

    if (s.size() == 1) {
        return 1;
    }

    for (int i = 1; i < s.size(); i++) {
        s[i] == x ? nFirst++ : nSecond++;
        if (nFirst == nSecond) {
            x = s[i + 1];
            nFirst = 1;
            nSecond = 0;
            answer++;
            i++;
        }

        if (i == s.size() - 1) {
            answer++;
        }
    }
    return answer;
}