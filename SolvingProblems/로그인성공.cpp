/*
�Ӿ��̴� ���α׷��ӽ��� �α����Ϸ��� �մϴ�. �Ӿ��̰� �Է��� ���̵�� �н����尡
��� �迭 id_pw�� ȸ������ ������ ��� 2���� �迭 db�� �־��� ��, ������ ���� �α��� ����,
���п� ���� �޽����� return�ϵ��� solution �Լ��� �ϼ����ּ���.

���̵�� ��й�ȣ�� ��� ��ġ�ϴ� ȸ�������� ������ "login"�� return�մϴ�.
�α����� �������� �� ���̵� ��ġ�ϴ� ȸ���� ���ٸ� ��fail����, 
���̵�� ��ġ������ ��й�ȣ�� ��ġ�ϴ� ȸ���� ���ٸ� ��wrong pw���� return �մϴ�.

* ���ѻ���
ȸ������ ���̵�� ���ڿ��Դϴ�.
ȸ������ ���̵�� ���ĺ� �ҹ��ڿ� ���ڷθ� �̷���� �ֽ��ϴ�.
ȸ������ �н������ ���ڷ� ������ ���ڿ��Դϴ�.
ȸ������ ��й�ȣ�� ���� �� ������ ���̵�� ���� �� �����ϴ�.
id_pw�� ���̴� 2�Դϴ�.
id_pw�� db�� ���Ҵ� [���̵�, �н�����] �����Դϴ�.
1 �� ���̵��� ���� �� 15
1 �� ��й�ȣ�� ���� �� 6
1 �� db�� ���� �� 10
db�� ������ ���̴� 2�Դϴ�.

* ����� ��
id_pw							db																				result
["meosseugi", "1234"]			[["rardss", "123"], ["yyoom", "1234"], ["meosseugi", "1234"]]					"login"
["programmer01", "15789"]		[["programmer02", "111111"], ["programmer00", "134"], ["programmer01", "1145"]]	"wrong pw"
["rabbit04", "98761"]			[["jaja11", "98761"], ["krong0313", "29440"], ["rabbit00", "111333"]]			"fail"


* ����� �� #1
db�� ���� ������ ������ �����Ƿ� "login"�� return�մϴ�.

* ����� �� #2
db�� ���̵�� ������ �н����尡 �ٸ� ������ �����Ƿ� "wrong pw"�� return�մϴ�.

* ����� �� #3
db�� ���̵� �´� ������ �����Ƿ� "fail"�� return�մϴ�.
*/


#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    map<string, string> m;
    for (auto i : db) {
        m[i[0]] = i[1];
    }

    if (m.find(id_pw[0]) != m.end()) {
        if (m[id_pw[0]] == id_pw[1]) return "login";
        else return "wrong pw";
    }
    else return "fail";
}