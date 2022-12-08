/*
�� ĭ���� S, L, �Ǵ� R�� ���� �ִ� ���ڰ� �ֽ��ϴ�. ����� �� ���ڿ��� ���� ����� �մϴ�. 
�� ������ �� ĭ���� ������ ���� Ư���� ������ �ֽ��ϴ�.

���� "S"�� ���� ĭ�� ������ ���, �����մϴ�.
���� "L"�� ���� ĭ�� ������ ���, ��ȸ���� �մϴ�.
���� "R"�� ���� ĭ�� ������ ���, ��ȸ���� �մϴ�.
���� ������ ���� �Ѿ ���, �ݴ��� ������ �ٽ� ���ƿɴϴ�. ���� ���,
���� 1�࿡�� ���� �پ��� �������� �̵��� ���, ���� ���� �ݴ��� �� ������ �ٽ� ���ƿɴϴ�.
����� �� ���� ������ ���� �̵��� �� �ִ� ��� ����Ŭ�� �� �� �ְ�, �� ����Ŭ�� 
���̰� ������ �˰� �ͽ��ϴ�. ��� ����Ŭ�̶�, ���� �̵��ϴ� ��ȯ ��θ� �ǹ��մϴ�.

���� ���, ���� �׸��� ���� ["SL","LR"]���� 1�� 1������ 2�� 1�� �������� ���� �� ���,
�ش� ���� �̵��ϴ� ��� ����Ŭ�� ǥ���� ���Դϴ�.

�� ���ڿ��� ���̰� 16�� ����Ŭ 1���� ������, �ٸ� ����Ŭ�� �������� �ʽ��ϴ�.

������ ������ ��Ÿ���� 1���� ���ڿ� �迭 grid�� �Ű������� �־����ϴ�.
�־��� ���ڸ� ���� ��������� ���� ��� ����Ŭ�� ��� ���̵��� �迭�� ��� ������������
�����Ͽ� return �ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� grid�� ���� �� 500
1 �� grid�� �� ���ڿ��� ���� �� 500
grid�� ��� ���ڿ��� ���̴� ���� �����ϴ�.
grid�� ��� ���ڿ��� 'L', 'R', 'S'�� �̷���� �ֽ��ϴ�.

* ����� ��
grid			result
["SL","LR"]		[16]
["S"]			[1,1,1,1]
["R","R"]		[4,4]

* ����� �� #1
���� ���ÿ� �����ϴ�.
���̰� 16�� ����Ŭ�� �ϳ� �����ϹǷ�(�ٸ� ����Ŭ�� �����ϴ�.), [16]�� return �ؾ� �մϴ�.

* ����� �� #2
�־��� ���ڸ� ���� ���� �� �ִ� ����Ŭ���� ���� �׸��� �����ϴ�.
4���� ����Ŭ�� ���̰� ��� 1�̹Ƿ�, [1,1,1,1]�� return �ؾ� �մϴ�.

* ����� �� #3
�־��� ���ڸ� ���� ���� �� �ִ� ����Ŭ���� ���� �׸��� �����ϴ�.
2���� ����Ŭ�� ���̰� ��� 4�̹Ƿ�, [4,4]�� return �ؾ� �մϴ�.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int row, col;
tuple<int, int, int> move_rotate(int r, int c, int d, vector<vector<char>>& grid_map) {
    char pos = grid_map[r][c];
    // 0 -> left, 1-> up, 2 -> right, 3 - > down
    // R -> ++;
    // L -> --;
    int dx[4] = { -1,0,1,0 };
    int dy[4] = { 0,1,0,-1 };

    if (pos == 'R')  d = (d + 1) % 4;
    else if (pos == 'L')   d = (d + 3) % 4;

    r = r + dy[d];
    c = c + dx[d];

    if (r >= row) r = 0;
    if (r < 0)   r = row - 1;

    if (c >= col) c = 0;
    if (c < 0)   c = col - 1;

    return make_tuple(r, c, d);
}


vector<int> solution(vector<string> grid) {
    vector<int> answer;

    row = grid.size();
    col = grid[0].size();

    vector<vector<char>> grid_map(row, vector<char>(col, 0));

    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c)
            grid_map[r][c] = grid[r][c];
    }


    bool isVisited[500][500][4] = { false, };

    for (int r = 0; r < row; ++r)
        for (int c = 0; c < col; ++c)
            for (int d = 0; d < 4; ++d) {
                if (isVisited[r][c][d] == false) {
                    int start_r = r;
                    int start_c = c;
                    int start_d = d;
                    int cnt = 0;
                    while (!isVisited[r][c][d]) {
                        isVisited[r][c][d] = true;
                        cnt++;
                        tuple<int, int, int> temp = move_rotate(r, c, d, grid_map);
                        r = get<0>(temp);
                        c = get<1>(temp);
                        d = get<2>(temp);
                    }
                    if (start_r == r && start_c == c && start_d == d) answer.push_back(cnt);
                }
            }
    sort(answer.begin(), answer.end());
    return answer;
}