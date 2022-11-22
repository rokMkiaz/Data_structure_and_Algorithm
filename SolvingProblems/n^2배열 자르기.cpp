/*
���� n, left, right�� �־����ϴ�. ���� ������ ���ļ� 1���� �迭�� ������� �մϴ�.

n�� n�� ũ���� ����ִ� 2���� �迭�� ����ϴ�.
i = 1, 2, 3, ..., n�� ���ؼ�, ���� ������ �ݺ��մϴ�.
1�� 1������ i�� i�������� ���� ���� ��� �� ĭ�� ���� i�� ä��ϴ�.
1��, 2��, ..., n���� �߶󳻾� ��� �̾���� ���ο� 1���� �迭�� ����ϴ�.
���ο� 1���� �迭�� arr�̶� �� ��, arr[left], arr[left+1], ..., arr[right]�� ����� �������� ����ϴ�.
���� n, left, right�� �Ű������� �־����ϴ�. �־��� ������� ������� 1���� �迭�� 
return �ϵ��� solution �Լ��� �ϼ����ּ���.

* ���ѻ���
1 �� n �� 107
0 �� left �� right < n2
right - left < 105

* ����� ��
n	left	right	result
3	2	    5	    [3,2,2,3]
4	7	    14  	[4,3,3,3,4,4,4,4]


* ����� �� #1

���� �ִϸ��̼��� �־��� ������� 1���� �迭�� ����� ������ ��Ÿ�� ���Դϴ�.


* ����� �� #2

���� �ִϸ��̼��� �־��� ������� 1���� �迭�� ����� ������ ��Ÿ�� ���Դϴ�.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) 
{
    vector<int> answer;
    int row;
    int column;
    for (long long i = left; i <= right; i++) {
        answer.push_back(max(i / n, i % n) + 1);
    }

    return answer;
}
