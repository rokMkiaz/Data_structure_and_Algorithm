/*
* ���� ����
��ö�δ��� �� �δ���� ���� ������ �Ի��� ����� Ư�� �ӹ��� ���� ���Դϴ�.
�������� ��ö�δ밡 ��ġ�� ������ ������ �� ������ ������ ��ȣ�� ���еǸ�,
�� ���� ���� ���� ����ϴ� �� �ɸ��� �ð��� ��� 1�� �����մϴ�. 
�ӹ��� ������ �� �δ���� ���� ������ �̿��Ͽ� �ִܽð��� �δ�� �����ϰ��� �մϴ�. 
�ٸ� ������ ���ط� ����, �ӹ��� ���� ���� �ٸ��� �ǵ��ƿ��� ��ΰ� ������ ���Ͱ� �Ұ����� �δ���� ���� �� �ֽ��ϴ�.

��ö�δ밡 ��ġ�� ������ ������ �������� �� n, �� ������ �պ��� �� �ִ� �� ������ ���� 2���� ���� �迭 roads, 
�� �δ���� ��ġ�� ���� �ٸ� �������� ��Ÿ���� ���� �迭 sources, ��ö�δ��� ���� destination�� �־����� ��, 
�־��� sources�� ���� ������� ��ö�δ�� ������ �� �ִ� �ִܽð��� ���� �迭�� return�ϴ� 
solution �Լ��� �ϼ����ּ���. ���Ͱ� �Ұ����� ��� �ش� �δ���� �ִܽð��� -1�Դϴ�.

* ���ѻ���
3 �� n �� 100,000
�� ������ ���� 1���� n������ ��ȣ�� ���е˴ϴ�.
2 �� roads�� ���� �� 500,000
roads�� ������ ���� = 2
roads�� ���Ҵ� [a, b] ���·� �� ���� a, b�� ���� �պ��� �� ������ �ǹ��մϴ�.(1 �� a, b �� n, a �� b)
������ ������ �ߺ��ؼ� �־����� �ʽ��ϴ�.
������ [a, b]�� �ߺ��ؼ� �־����� �ʽ��ϴ�.
[a, b]�� �ִٸ� [b, a]�� �־����� �ʽ��ϴ�.
1 �� sources�� ���� �� 500
1 �� sources[i] �� n
1 �� destination �� n

* ����� ��
n		roads										sources			destination					result
3		[[1, 2], [2, 3]]							[2, 3]				1						[1, 2]
5		[[1, 2], [1, 4], [2, 4], [2, 5], [4, 5]]	[1, 3, 5]			5						[2, -1, 0]

* ����� �� #1

���� 2�� ���� 1�� ��� ����Ǿ� �ֱ� ������, ���� 2���� ���� 1�� �ִܰŸ��� 1�Դϴ�.
���� 3���� ���� 1�� �̵��� �� �ִ� �ִܰ�δ� ���� 3 �� ���� 2 �� ���� 1 ������ 
�̵��ϴ� ���̱� ������, ���� 3���� ���� 1�� �ִܰŸ��� 2�Դϴ�.
���� [1, 2]�� return�մϴ�.

* ����� �� #2
���� 1���� ���� 5�� �ִܰ�δ� ���� 1 �� ���� 2 �� ���� 5 �Ǵ� ���� 1 �� ���� 4 �� ���� 5 ������ 
�̵��ϴ� ���̱� ������,�ִܰŸ��� 2�Դϴ�.
���� 3���� ���� 5�� ���� ��ΰ� ���� ������, ���� 3���� ���� 5�� ���� �ִܰŸ��� -1�Դϴ�.
���� 5���� ���� 5�� �̵��� �ʿ䰡 ���� ������, �ִܰŸ��� 0�Դϴ�.
���� [2, -1, 0]�� return�մϴ�.
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[100001];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    vector<int> answer(sources.size());

    vector<int> costFromDestination(n + 1, -1);

    // make edge
    for (int i = 0; i < roads.size(); i++) //��ġ �����
    {
        edge[roads[i][0]].push_back(roads[i][1]); 
        edge[roads[i][1]].push_back(roads[i][0]);
    }

    // find by bfs �ʺ� �켱 Ž��
    queue<pair<int, int>> q; // pos, count
    q.push({ destination, 0 });
    costFromDestination[destination] = 0;

    while (!q.empty())
    {
        auto curPos = q.front().first;
        auto curCount = q.front().second;
        q.pop();

        for (int i = 0; i < edge[curPos].size(); i++)
        {
            int nextPos = edge[curPos][i];

            if (costFromDestination[nextPos] == -1 || costFromDestination[nextPos] > curCount + 1) 
            {
                q.push({ nextPos, curCount + 1 });
                costFromDestination[nextPos] = curCount + 1;
            }
        }
    }

    for (int i = 0; i < sources.size(); i++)
    {
        answer[i] = costFromDestination[sources[i]];

    }

    return answer;
}