
/*
�� ������ �Ӿ��̴� ���� �� ������ ������ ���� ��ȣ ü�踦 ����Ѵٴ� ���� �˾Ƴ½��ϴ�.

��ȣȭ�� ���ڿ� cipher�� �ְ�޽��ϴ�.
�� ���ڿ����� code�� ��� ��° ���ڸ� ��¥ ��ȣ�Դϴ�.
���ڿ� cipher�� ���� code�� �Ű������� �־��� �� �ص��� ��ȣ ���ڿ��� return�ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� cipher�� ���� �� 1, 000
1 �� code �� cipher�� ����
cipher�� �ҹ��ڿ� �������θ� �����Ǿ� �ֽ��ϴ�.
���鵵 �ϳ��� ���ڷ� ����մϴ�.

* ����� ��
cipher	code	result
"dfjardstddetckdaccccdegk"	4	"attack"
"pfqallllabwaoclk"	2	"fallback"

* ����� �� #1
"dfjardstddetckdaccccdegk" �� 4��°, 8��°, 12��°, 16��°, 20��°, 24��° ���ڸ� ��ģ
"attack"�� return�մϴ�.

* ����� �� #2
"pfqallllabwaoclk" �� 2��°, 4��°, 6��°, 8��°, 10��°, 12��°, 14��°, 16��° ���ڸ� ��ģ 
"fallback"�� return�մϴ�.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code)
{
    string answer = "";

    for (int i = 0; i < cipher.size(); i++)
        if ((i + 1) % code == 0)
            answer += cipher[i];

    return answer;
}