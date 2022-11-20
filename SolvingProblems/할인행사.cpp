/*
* �������
XYZ ��Ʈ�� ������ �ݾ��� �����ϸ� 10�� ���� ȸ�� �ڰ��� �ο��մϴ�. 
XYZ ��Ʈ������ ȸ���� ������� ���� �� ���� ��ǰ�� �����ϴ� ��縦 �մϴ�. 
�����ϴ� ��ǰ�� �Ϸ翡 �ϳ����� ������ �� �ֽ��ϴ�. �˶��� �����̴� �ڽ��� 
���ϴ� ��ǰ�� ������ �����ϴ� ��¥�� 10�� �������� ��ġ�� ��쿡 ���缭 ȸ�������� �Ϸ� �մϴ�.

���� ���, �����̰� ���ϴ� ��ǰ�� �ٳ��� 3��, ��� 2��, �� 2��, ������� 2��, ���� 1���̸�, 
XYZ ��Ʈ���� 15�ϰ� ȸ���� ������� �����ϴ� ��ǰ�� ��¥ ������� ġŲ, ���, ���, �ٳ���, 
��, ���, �������, �ٳ���, �������, ��, ����, �ٳ���, ���, �ٳ����� ��쿡 ���� �˾ƺ��ô�.
ù° ������ ���� ������ ���� �������� �ʱ� ������ ù° ������ ȸ�������� ���� �ʽ��ϴ�. 
��° ������ ���� ������ �ٳ����� ���ϴ� ��ŭ ���α����� �� ���� ������ ��° ������ ȸ�������� ���� �ʽ��ϴ�.
��° ��, ��° ��, �ټ�° ������ ���� ������ ���ϴ� ��ǰ�� ������ ��ġ�ϱ� ������ �� �� 
�Ϸ翡 ȸ�������� �Ϸ� �մϴ�.

�����̰� ���ϴ� ��ǰ�� ��Ÿ���� ���ڿ� �迭 want�� �����̰� ���ϴ� ��ǰ�� ������ ��Ÿ���� 
���� �迭 number, XYZ ��Ʈ���� �����ϴ� ��ǰ�� ��Ÿ���� ���ڿ� �迭 discount�� �־����� ��, 
ȸ����Ͻ� �����̰� ���ϴ� ��ǰ�� ��� ���� ���� �� �ִ� ȸ����� ��¥�� �� �ϼ��� return �ϴ� 
solution �Լ��� �ϼ��Ͻÿ�. ������ ���� ������ 0�� return �մϴ�.

* ���ѻ���
1 �� want�� ���� = number�� ���� �� 10
1 �� number�� ���� �� 10
number[i]�� want[i]�� ������ �ǹ��ϸ�, number�� ������ ���� 10�Դϴ�.
10 �� discount�� ���� �� 100,000
want�� discount�� ���ҵ��� ���ĺ� �ҹ��ڷ� �̷���� ���ڿ��Դϴ�.
1 �� want�� ������ ����, discount�� ������ ���� �� 12

* ����� ��
want										number				discount																																result
["banana", "apple", "rice", "pork", "pot"]	[3, 2, 2, 2, 1]		["chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"]			3
["apple"]									[10]				["banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"]									0



* ����� �� #2
����� �����ϴ� ���� �����Ƿ� 0�� return �մϴ�.

*/

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    map<string, int> m;
    for (int i = 0; i < 9; i++) m[discount[i]]++;
    for (int i = 9; i < discount.size(); i++)
    {
        m[discount[i]]++;
        bool flag = true;
        for (int j = 0; j < want.size(); j++)
            if (m[want[j]] != number[j])
            {
                flag = false; break;
            }
        if (flag == true) answer++;
        m[discount[i - 9]]--;
    }
    return answer;
}