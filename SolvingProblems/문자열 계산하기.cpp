/*
my_string�� "3 + 5"ó�� ���ڿ��� �� �����Դϴ�. 
���ڿ� my_string�� �Ű������� �־��� ��, ������ ����� ���� return �ϴ� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
�����ڴ� +, -�� �����մϴ�.
���ڿ��� ���۰� ������ ������ �����ϴ�.
0���� �����ϴ� ���ڴ� �־����� �ʽ��ϴ�.
�߸��� ������ �־����� �ʽ��ϴ�.
5 �� my_string�� ���� �� 100
my_string�� ����� ������� 1 �̻� 100,000 �����Դϴ�.
my_string�� �߰� ��� ���� -100,000 �̻� 100,000 �����Դϴ�.
��꿡 ����ϴ� ���ڴ� 1 �̻� 20,000 ������ �ڿ����Դϴ�.
my_string���� �����ڰ� ��� �ϳ� ���ԵǾ� �ֽ��ϴ�.
return type �� �������Դϴ�.
my_string�� ���ڿ� �����ڴ� ���� �ϳ��� ���еǾ� �ֽ��ϴ�.


* ����� ��
my_string   	result
"3 + 4"        	7


* ����� �� #1
3 + 4 = 7�� return �մϴ�.

*/


#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    bool math = true;
    string num = "";

    for (int i = 0; i < my_string.length(); ++i)
    {
        if (my_string[i] == ' ')
        {
            //cout << num << endl;
            if (num.compare("+") == 0) math = true;
            else if (num.compare("-") == 0) math = false;
            else math == true ? answer += stoi(num) : answer -= stoi(num); //���ڿ� => ���
            num = "";
        }
        else num += my_string[i];
    }

    return math == true ? answer += stoi(num) : answer -= stoi(num);
}