/*
* 2���� ���� ������
�Ѽ��� ���簢�� ����� ������ ���� �������� ������ ���̸� �ϰ� �ֽ��ϴ�. 
��� �������� �հ� �ڰ� ���еǾ� ������, ������ ������ ���ؼ��� ���� �ٿ� �ִ� ��� ������ ������� �մϴ�. 
�������� �ʱ� ���¿� ��ǥ ���°� �־����� ��, �ʱ� ���¿��� �ּ� �� ���� ������ ������� ��ǥ ���°� �Ǵ��� 
�˾ƺ��ô�.

���� ���, �� �׸����� �� ������ �ʱ� ����, �� �������� ��ǥ ������ ��쿡 ���� �˾ƺ��ô�. 
�׸����� ������ ���� �ո��� ����, ��� ���� �޸��� ������ �ǹ��մϴ�. �ʱ� ���¿��� 2��� 4���� ������ ��������,
�� ��° �׸��� �˴ϴ�. �� ��, 2��, 4��, 5���� ������ ������� ������ �ٸ�, �� 5���� ���� �����⸦ ���� 
��ǥ ���°� �Ǹ�, �� ��찡 �ּ��� ����Դϴ�.

���簢�� ����� ������ ���� �������� �ʱ� ���¸� ��Ÿ���� 2���� ���� �迭 beginning, ��ǥ ���¸� ��Ÿ����
target�� �־����� ��, �ʱ� ���¿��� ��ǥ ���·� ����� ���� �ʿ��� ���� ������ Ƚ���� �ּڰ��� return �ϴ�
solution �Լ��� �ϼ��ϼ���. ��, ��ǥ ���¸� ������ ���ϴ� ��쿡�� -1�� return �մϴ�.

* ���ѻ���
1 �� beginning�� ���� = target�� ���� �� 10
1 �� beginning[i]�� ���� = target[i]�� ���� �� 10
beginning[i][j]�� target[i][j]�� i + 1�� j + 1���� ������ ���¸� ��Ÿ����, 0 �Ǵ� 1�� ������ �־����ϴ�.
0�� ������ �ո���, 1�� ������ �޸��� �ǹ��մϴ�.

* ����� ��
beginning																				target																						result
[[0, 1, 0, 0, 0], [1, 0, 1, 0, 1], [0, 1, 1, 1, 0], [1, 0, 1, 1, 0], [0, 1, 0, 1, 0]]	[[0, 0, 0, 1, 1], [0, 0, 0, 0, 1], [0, 0, 1, 0, 1], [0, 0, 0, 1, 0], [0, 0, 0, 0, 1]]		5
[[0, 0, 0], [0, 0, 0], [0, 0, 0]]														[[1, 0, 1], [0, 0, 0], [0, 0, 0]]															-1

* ����� �� #2

��ǥ ���¸� ������ ���մϴ�. ���� -1�� return �մϴ�.


*/




#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target)
{
    int answer = 0;
    int r_size = beginning.size(), c_size = beginning[0].size();
    vector<vector<int>> board(r_size, vector<int>(c_size));
    for (int i = 0; i < r_size; i++)
        for (int j = 0; j < c_size; j++)
            board[i][j] = beginning[i][j] ^ target[i][j];
    int cnt = 0, sum = 0;
    for (int i = 0; i < c_size; i++) sum += board[0][i];
    for (int i = 1; i < r_size; i++)
    {
        bool o_flag = true, r_flag = true;
        for (int j = 0; j < c_size; j++)
        {
            if ((board[i][j] ^ 0) != board[0][j]) o_flag = false; //��Ʈ����
            if ((board[i][j] ^ 1) != board[0][j]) r_flag = false;
        }
        if (!o_flag)
        {
            if (!r_flag) return -1;
            else cnt++;
        }
    }
    answer = min(cnt + sum, r_size - cnt + c_size - sum);
    return answer;
}