/*
���ڿ� my_string�� �Ű������� �־��� ��, �빮�ڴ� �ҹ��ڷ� �ҹ��ڴ� �빮�ڷ�
��ȯ�� ���ڿ��� return�ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� my_string�� ���� �� 1,000
my_string�� ���� �빮�ڿ� �ҹ��ڷθ� �����Ǿ� �ֽ��ϴ�.

* ����� ��
my_string	        result
"cccCCC"	        "CCCccc"
"abCdEfghIJ"	    "ABcDeFGHij"


* ����� �� #1
�ҹ��ڴ� �빮�ڷ� �빮�ڴ� �ҹ��ڷ� �ٲ� "CCCccc"�� return�մϴ�.

* ����� �� #2
�ҹ��ڴ� �빮�ڷ� �빮�ڴ� �ҹ��ڷ� �ٲ� "ABcDeFGHij"�� return�մϴ�.

*/

#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    for (int i = 0; i < my_string.length(); i++) {
        if (my_string[i] < 97) my_string[i] += 32;
        else my_string[i] -= 32;
    }
    return my_string;
}