/*
������ ���� �ٰ��� ��� �������� ĳ���Ͱ� �������� �ݱ� ���� �̵��Ϸ� �մϴ�.

rect_1.png

������ �� ���� x��, y��� ������ ���簢���� ������ ���·� ǥ���ϸ�, 
ĳ���ʹ� �� �ٰ����� �ѷ�(���� ��)�� ���� �̵��մϴ�.

���� ���簢���� ��ģ �� ������ ���� �߾ӿ� �� ������ ����� ���, 
�ٰ����� ���� �ٱ��� �׵θ��� ĳ������ �̵� ��ΰ� �˴ϴ�.


��, ���� �ٸ� �� ���簢���� x�� ��ǥ �Ǵ� y�� ��ǥ�� ���� ���� �����ϴ�.

��, �� �׸�ó�� ���� �ٸ� �� ���簢���� ���������� �����ų�, ���� ��ġ�� ��� ���� �����ϴ�.

���� �׸��� ���� ������ 2�� �̻����� �и��� ��쵵 �����ϴ�.
�� ���簢���� �ٸ� ���簢�� �ȿ� ������ ���ԵǴ� ��� ���� �����ϴ�.

������ ��Ÿ���� ���簢���� ��� 2���� �迭 rectangle, �ʱ� ĳ������ ��ġ characterX, characterY, 
�������� ��ġ itemX, itemY�� solution �Լ��� �Ű������� �־��� ��, ĳ���Ͱ� �������� �ݱ� ���� 
�̵��ؾ� �ϴ� ���� ª�� �Ÿ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
rectangle�� ����(��) ���̴� 1 �̻� 4 �����Դϴ�.
rectangle�� ���Ҵ� �� ���簢���� [���� �ϴ� x, ���� �ϴ� y, ���� ��� x, ���� ��� y] ��ǥ �����Դϴ�.
���簢���� ��Ÿ���� ��� ��ǥ���� 1 �̻� 50 ������ �ڿ����Դϴ�.
���� �ٸ� �� ���簢���� x�� ��ǥ, Ȥ�� y�� ��ǥ�� ���� ���� �����ϴ�.
������ �־��� ���ǿ� �´� ���簢���� �Է����� �־����ϴ�.
charcterX, charcterY�� 1 �̻� 50 ������ �ڿ����Դϴ�.
������ ��Ÿ���� �ٰ��� �׵θ� ���� �� ���� �־����ϴ�.
itemX, itemY�� 1 �̻� 50 ������ �ڿ����Դϴ�.
������ ��Ÿ���� �ٰ��� �׵θ� ���� �� ���� �־����ϴ�.
ĳ���Ϳ� �������� ó�� ��ġ�� ���� ���� �����ϴ�.
��ü ������ 50%�� ���簢���� 1���� ����Դϴ�.
��ü ������ 25%�� ���簢���� 2���� ����Դϴ�.
��ü ������ 25%�� ���簢���� 3�� �Ǵ� 4���� ����Դϴ�.

* ����� ��
rectangle									characterX	characterY	itemX	itemY	result
[[1,1,7,4],[3,2,5,5],[4,3,6,9],[2,6,8,8]]	1			3			7		8		17
[[1,1,8,4],[2,2,4,9],[3,6,9,8],[6,3,7,7]]	9			7			6		1		11
[[1,1,5,7]]									1			1			4		7		9
[[2,1,7,5],[6,4,10,10]]						3			1			7		10		15
[[2,2,5,5],[1,3,6,4],[3,1,4,6]]				1			4			6		3		10


* ����� �� #1
ĳ���� ��ġ�� (1, 3)�̸�, ������ ��ġ�� (7, 8)�Դϴ�. �� �׸��� ���� ���� ���� ���� �̵��ϴ� ��ΰ� ���� ª���ϴ�.

* ����� �� #2
ĳ���� ��ġ�� (9, 7)�̸�, ������ ��ġ�� (6, 1)�Դϴ�. �� �׸��� ���� ���� ���� ���� �̵��ϴ� ��ΰ� ���� ª���ϴ�.

* ����� �� #3
ĳ���� ��ġ�� (1, 1)�̸�, ������ ��ġ�� (4, 7)�Դϴ�. �� �׸��� ���� ���� ���� ���� �̵��ϴ� ��ΰ� ���� ª���ϴ�.
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;
const int M = 60;
vector<int> v[M * M + 9];
bool is_inside(vector<vector<int>>& a, int bani, int tid, int dy) {
    int i, j, k;
    int n = a.size();
    int ti = tid / M;
    int tj = tid % M;
    for (i = 0; i < n; i++) {
        if (i == bani)continue;
        if (dy == 0) {
            if (a[i][0] <= ti && ti < a[i][2]) {
                if (a[i][1] < tj && tj < a[i][3]) {
                    return true;
                }
            }
        }
        else {
            if (a[i][0] < ti && ti < a[i][2]) {
                if (a[i][1] <= tj && tj < a[i][3]) {
                    return true;
                }
            }
        }

    }
    return false;
}
int solution(vector<vector<int>> a, int sx, int sy, int ex, int ey) {
    int i, j, k;
    int adn = M * M;
    for (i = 0; i < adn; i++) {
        v[i].clear();
    }
    int n = a.size();
    int sid = sx * M + sy;
    int eid = ex * M + ey;
    for (i = 0; i < n; i++) {
        if (a[i][0] > a[i][2])swap(a[i][0], a[i][2]);
        if (a[i][1] > a[i][3])swap(a[i][1], a[i][3]);
    }

    for (i = 0; i < n; i++) {
        // left
        {
            for (int x = a[i][0]; x < a[i][2]; x++) {
                int cid = x * M + a[i][1];
                int tid = (x + 1) * M + a[i][1];
                if (is_inside(a, i, cid, 0))continue;
                v[cid].push_back(tid);
                v[tid].push_back(cid);
            }
        }
        // right
        {
            for (int x = a[i][0]; x < a[i][2]; x++) {
                int cid = x * M + a[i][3];
                int tid = (x + 1) * M + a[i][3];
                if (is_inside(a, i, cid, 0))continue;
                v[cid].push_back(tid);
                v[tid].push_back(cid);
            }
        }
        // bottom
        {
            for (int y = a[i][1]; y < a[i][3]; y++) {
                int cid = a[i][0] * M + y;
                int tid = a[i][0] * M + y + 1;
                if (is_inside(a, i, cid, 1))continue;
                v[cid].push_back(tid);
                v[tid].push_back(cid);
            }
        }
        // top
        {
            for (int y = a[i][1]; y < a[i][3]; y++) {
                int cid = a[i][2] * M + y;
                int tid = a[i][2] * M + y + 1;
                if (is_inside(a, i, cid, 1))continue;
                v[cid].push_back(tid);
                v[tid].push_back(cid);
            }
        }
    }
    vector<int> d(M * M, -1);
    d[sid] = 0;
    queue<int> que;
    que.push(sid);
    bool cut = false;
    while (!cut && !que.empty()) {
        int qid = que.front();
        que.pop();
        for (auto& it : v[qid]) {
            if (d[it] == -1) {
                d[it] = d[qid] + 1;
                que.push(it);
                if (it == eid) {
                    cut = true;
                    break;
                }
            }
        }
    }
    return d[eid];
}