/*
���Ի�� ������ �Խ��� �ҷ� �̿��ڸ� �Ű��ϰ� ó�� ����� ���Ϸ� �߼��ϴ� �ý����� �����Ϸ� �մϴ�.
������ �����Ϸ��� �ý����� ������ �����ϴ�.

�� ������ �� ���� �� ���� ������ �Ű��� �� �ֽ��ϴ�.
�Ű� Ƚ���� ������ �����ϴ�. ���� �ٸ� ������ ����ؼ� �Ű��� �� �ֽ��ϴ�.
�� ������ ���� �� �Ű��� ���� ������, ������ ������ ���� �Ű� Ƚ���� 1ȸ�� ó���˴ϴ�.
k�� �̻� �Ű�� ������ �Խ��� �̿��� �����Ǹ�, �ش� ������ �Ű��� ��� �������� ���� ����� ���Ϸ� �߼��մϴ�.
������ �Ű��� ��� ������ �����Ͽ� �������� �Ѳ����� �Խ��� �̿� ������ ��Ű�鼭 ���� ������ �߼��մϴ�.
������ ��ü ���� ����� ["muzi", "frodo", "apeach", "neo"]�̰�, k = 2(��, 2�� �̻� �Ű���ϸ� �̿� ����)
�� ����� �����Դϴ�.
	
���� ID		������ �Ű��� ID			����
"muzi"		"frodo"					"muzi"�� "frodo"�� �Ű��߽��ϴ�.
"apeach"	"frodo"					"apeach"�� "frodo"�� �Ű��߽��ϴ�.
"frodo"		"neo"					"frodo"�� "neo"�� �Ű��߽��ϴ�.
"muzi"		"neo"					"muzi"�� "neo"�� �Ű��߽��ϴ�.
"apeach"	"muzi"					"apeach"�� "muzi"�� �Ű��߽��ϴ�.
�� �������� �Ű���� Ƚ���� ������ �����ϴ�.

���� ID		�Ű���� Ƚ��
"muzi"		1
"frodo"		2
"apeach"	0
"neo"		2
�� ���ÿ����� 2�� �̻� �Ű���� "frodo"�� "neo"�� �Խ��� �̿��� �����˴ϴ�.
�̶�, �� �������� �Ű��� ���̵�� ������ ���̵� �����ϸ� ������ �����ϴ�.

���� ID		������ �Ű��� ID				������ ID
"muzi"		["frodo", "neo"]			["frodo", "neo"]
"frodo"		["neo"]						["neo"]
"apeach"	["muzi", "frodo"]			["frodo"]
"neo"		����							����
���� "muzi"�� ó�� ��� ������ 2ȸ, "frodo"�� "apeach"�� ���� ó�� ��� ������ 1ȸ �ް� �˴ϴ�.

�̿����� ID�� ��� ���ڿ� �迭 id_list, �� �̿��ڰ� �Ű��� �̿����� ID ������ ��� ���ڿ� �迭 report, 
���� ������ �Ǵ� �Ű� Ƚ�� k�� �Ű������� �־��� ��, �� �������� ó�� ��� ������ ���� Ƚ���� �迭�� 
��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
2 �� id_list�� ���� �� 1,000
1 �� id_list�� ���� ���� �� 10
id_list�� ���Ҵ� �̿����� id�� ��Ÿ���� ���ڿ��̸� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
id_list���� ���� ���̵� �ߺ��ؼ� ������� �ʽ��ϴ�.
1 �� report�� ���� �� 200,000
3 �� report�� ���� ���� �� 21
report�� ���Ҵ� "�̿���id �Ű���id"������ ���ڿ��Դϴ�.
���� ��� "muzi frodo"�� ��� "muzi"�� "frodo"�� �Ű��ߴٴ� �ǹ��Դϴ�.
id�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
�̿���id�� �Ű���id�� ����(�����̽�)�ϳ��� ���еǾ� �ֽ��ϴ�.
�ڱ� �ڽ��� �Ű��ϴ� ���� �����ϴ�.
1 �� k �� 200, k�� �ڿ����Դϴ�.
return �ϴ� �迭�� id_list�� ��� id ������� �� ������ ���� ��� ���� ���� ������ �˴ϴ�.

* ����� ��
id_list								report																k	result
["muzi", "frodo", "apeach", "neo"]	["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]	2	[2,1,1,0]
["con", "ryan"]						["ryan con", "ryan con", "ryan con", "ryan con"]					3	[0,0]

*/

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>

using namespace std;

vector<string> split(string& s, string token);

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, set<string>> calleeTable; //key�� string�� �Ű� ���� ���, set�� �� ����� �Ű��� ����� ����
    map<string, set<string>> callerTable; //key�� string�� �Ű� �� ���, set�� �� ����� �Ű��� ����� ����

    //callTable �ʱ�ȭ
    for (string id : id_list) {
        calleeTable[id] = {};
        callerTable[id] = {};
    }

    for (string s : report) {
        vector<string> parsed = split(s, " ");

        string caller = parsed[0];
        string callee = parsed[1];

        calleeTable[callee].insert(caller);
        callerTable[caller].insert(callee);
    }

    vector<int> answer;
    for (string id : id_list) {
        int notificationCount = 0;

        for (string callee : callerTable[id]) {
            if (calleeTable[callee].size() >= k) {
                notificationCount++;
            }
        }

        answer.push_back(notificationCount);
    }
    return answer;
}

vector<string> split(string& s, string token) {
    vector<string> stringList;

    int searchPoint = 0;
    while (true) {
        int searchResult = s.find(token, searchPoint);

        stringList.push_back(s.substr(searchPoint, searchResult - searchPoint));
        searchPoint = searchResult + 1;

        if (searchResult == string::npos) {
            break;
        }
    }

    return stringList;
}