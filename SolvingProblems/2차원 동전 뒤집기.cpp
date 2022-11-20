/*
* 2차원 동전 뒤집기
한수는 직사각형 모양의 공간에 놓인 동전들을 뒤집는 놀이를 하고 있습니다. 
모든 동전들은 앞과 뒤가 구분되어 있으며, 동전을 뒤집기 위해서는 같은 줄에 있는 모든 동전을 뒤집어야 합니다. 
동전들의 초기 상태와 목표 상태가 주어졌을 때, 초기 상태에서 최소 몇 번의 동전을 뒤집어야 목표 상태가 되는지 
알아봅시다.                                       

예를 들어, 위 그림에서 맨 왼쪽이 초기 상태, 맨 오른쪽이 목표 상태인 경우에 대해 알아봅시다. 
그림에서 검은색 원은 앞면인 동전, 흰색 원은 뒷면인 동전을 의미합니다. 초기 상태에서 2행과 4행의 돌들을 뒤집으면,
두 번째 그림이 됩니다. 그 후, 2열, 4열, 5열의 돌들을 순서대로 뒤집는 다면, 총 5번의 동전 뒤집기를 통해 
목표 상태가 되며, 이 경우가 최소인 경우입니다.

직사각형 모양의 공간에 놓인 동전들의 초기 상태를 나타내는 2차원 정수 배열 beginning, 목표 상태를 나타내는
target이 주어졌을 때, 초기 상태에서 목표 상태로 만들기 위해 필요한 동전 뒤집기 횟수의 최솟값을 return 하는
solution 함수를 완성하세요. 단, 목표 상태를 만들지 못하는 경우에는 -1을 return 합니다.

* 제한사항
1 ≤ beginning의 길이 = target의 길이 ≤ 10
1 ≤ beginning[i]의 길이 = target[i]의 길이 ≤ 10
beginning[i][j]와 target[i][j]는 i + 1행 j + 1열의 동전의 상태를 나타내며, 0 또는 1의 값으로 주어집니다.
0은 동전의 앞면을, 1은 동전의 뒷면을 의미합니다.

* 입출력 예
beginning																				target																						result
[[0, 1, 0, 0, 0], [1, 0, 1, 0, 1], [0, 1, 1, 1, 0], [1, 0, 1, 1, 0], [0, 1, 0, 1, 0]]	[[0, 0, 0, 1, 1], [0, 0, 0, 0, 1], [0, 0, 1, 0, 1], [0, 0, 0, 1, 0], [0, 0, 0, 0, 1]]		5
[[0, 0, 0], [0, 0, 0], [0, 0, 0]]														[[1, 0, 1], [0, 0, 0], [0, 0, 0]]															-1

* 입출력 예 #2

목표 상태를 만들지 못합니다. 따라서 -1을 return 합니다.


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
            if ((board[i][j] ^ 0) != board[0][j]) o_flag = false; //비트연산
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