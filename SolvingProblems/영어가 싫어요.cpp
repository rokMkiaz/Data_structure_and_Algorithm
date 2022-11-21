/*
��� ���� �Ӿ��̴� ����� ǥ��Ǿ��ִ� ���ڸ� ���� �ٲٷ��� �մϴ�. 
���ڿ� numbers�� �Ű������� �־��� ��, numbers�� ������ �ٲ� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

���ѻ���
numbers�� �ҹ��ڷθ� �����Ǿ� �ֽ��ϴ�.
numbers�� "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" ���� ���� ���� ���յǾ� �ֽ��ϴ�.
1 �� numbers�� ���� �� 50
"zero"�� numbers�� �� �տ� �� �� �����ϴ�.

* ����� ��
numbers	                                            result
"onetwothreefourfivesixseveneightnine"	            123456789
"onefourzerosixseven"               	            14067

* ����� �� #1
"onetwothreefourfivesixseveneightnine"�� ���ڷ� �ٲ� 123456789�� return�մϴ�.

* ����� �� #1
"onefourzerosixseven"�� ���ڷ� �ٲ� 14067�� return�մϴ�.

*/


#include <string>
#include <vector>

using namespace std;

vector<string> v = { "zero", "one", "two", "three", "four",
                   "five", "six", "seven", "eight", "nine" };

long long solution(string numbers) {
    long long answer = 0;
    while (numbers.length() > 0) {
        for (int i = 0; i < v.size(); i++) {
            if (numbers.substr(0, v[i].length()) == v[i]) {
                answer = answer * 10 + i;
                numbers = numbers.substr(v[i].length());
            }
        }
    }
    return answer;
}