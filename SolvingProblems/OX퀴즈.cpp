/*
����, ���� ���ĵ��� 'X [������] Y = Z' ���·� ����ִ� ���ڿ� �迭 quiz�� �Ű������� �־����ϴ�.
������ �Ǵٸ� "O"�� Ʋ���ٸ� "X"�� ������� ���� �迭�� return�ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
���� ��ȣ�� ���� ���̴� �׻� �ϳ��� ������ �����մϴ�. �� ������ ǥ���ϴ� ���̳ʽ� ��ȣ�� 
���� ���̿��� ������ �������� �ʽ��ϴ�.
1 �� quiz�� ���� �� 10
X, Y, Z�� ���� 0���� 9���� ���ڷ� �̷���� ������ �ǹ��ϸ�, �� ������ �� �տ� ���̳ʽ� ��ȣ��
�ϳ� ���� �� �ְ� �̴� ������ �ǹ��մϴ�.
X, Y, Z�� 0�� �����ϰ�� 0���� �������� �ʽ��ϴ�.
-10,000 �� X, Y �� 10,000
-20,000 �� Z �� 20,000
[������]�� + �� - �� �ϳ��Դϴ�.


* ����� ��
quiz	result
["3 - 4 = -3", "5 + 6 = 11"]	["X", "O"]
["19 - 6 = 13", "5 + 66 = 71", "5 - 15 = 63", "3 - 1 = 2"]	["O", "O", "X", "O"]

* ����� �� #1
3 - 4 = -3 �� Ʋ�� �����̹Ƿ� "X", 5 + 6 = 11 �� ���� �����̹Ƿ� "O" �Դϴ�. ���� ["X", "O"]�� return�մϴ�.

* ����� �� #2
19 - 6 = 13 �� ���� �����̹Ƿ� "O", 5 + 66 = 71 �� ���� �����̹Ƿ� "O", 5 - 15 = 63 �� 
Ʋ�� �����̹Ƿ� "X", 3 - 1 = 2�� ���� �����̹Ƿ� "O" ���� ["O", "O", "X", "O"]�� return�մϴ�.

*/


#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for (auto element : quiz) { //quiz �� ������ ���� �ݺ�
        string delim = " ";
        size_t pos = 0;
        vector<string> line;
        while ((pos = element.find(delim)) != string::npos)
        {
            line.push_back(element.substr(0, pos));
            element.erase(0, pos + delim.length());
        }
        line.push_back(element);
        bool isTrue = false;
        if (line[1] == "+")
            isTrue = to_string(stoi(line[0]) + stoi(line[2])) == to_string(stoi(line[4])) ?
            true : false;
        else if (line[1] == "-")
            isTrue = to_string(stoi(line[0]) - stoi(line[2])) == to_string(stoi(line[4])) ?
            true : false;
        string result = isTrue ? "O" : "X";
        answer.push_back(result);
    }


    return answer;
}