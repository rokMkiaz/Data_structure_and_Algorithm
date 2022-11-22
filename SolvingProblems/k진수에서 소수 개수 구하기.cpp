/*
���� ���� n�� �־����ϴ�. �� ���ڸ� k������ �ٲ��� ��, ��ȯ�� �� �ȿ� �Ʒ� 
���ǿ� �´� �Ҽ�(Prime number)�� �� ������ �˾ƺ��� �մϴ�.

0P0ó�� �Ҽ� ���ʿ� 0�� �ִ� ���
P0ó�� �Ҽ� �����ʿ��� 0�� �ְ� ���ʿ��� �ƹ��͵� ���� ���
0Pó�� �Ҽ� ���ʿ��� 0�� �ְ� �����ʿ��� �ƹ��͵� ���� ���
Pó�� �Ҽ� ���ʿ� �ƹ��͵� ���� ���
��, P�� �� �ڸ����� 0�� �������� �ʴ� �Ҽ��Դϴ�.
���� ���, 101�� P�� �� �� �����ϴ�.
���� ���, 437674�� 3������ �ٲٸ� 211020101011�Դϴ�. ���⼭ ã�� �� �ִ� ���ǿ�
�´� �Ҽ��� ���ʺ��� ������� 211, 2, 11�� ������, �� 3���Դϴ�. 
(211, 2, 11�� k�������� ������ ���� �ƴ�, 10�������� ������ �� �Ҽ����� �Ѵٴ� ���� �����մϴ�.) 
211�� P0 ���¿��� ã�� �� ������, 2�� 0P0����, 11�� 0P���� ã�� �� �ֽ��ϴ�.

���� n�� k�� �Ű������� �־����ϴ�. n�� k������ �ٲ��� ��, 
��ȯ�� �� �ȿ��� ã�� �� �ִ� �� ���ǿ� �´� �Ҽ��� ������ return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

* ���ѻ���
1 �� n �� 1,000,000
3 �� k �� 10

* ����� ��
n			k		result
437674		3		3
110011		10		2

* ����� �� #2

110011�� 10������ �ٲٸ� 110011�Դϴ�. ���⼭ ã�� �� �ִ� ���ǿ� �´� 
�Ҽ��� 11, 11 2���Դϴ�. �̿� ����, �ߺ��Ǵ� �Ҽ��� �߰��ϴ��� ��� ���� ����� �մϴ�.


*/
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    int sqrtn = sqrt(n);

    for (int i = 4; i <= sqrtn; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

string decToK(int n, int k) {
    string knum;
    for (; n; n /= k) {
        knum = (char)(n % k + '0') + knum;
    }
    return knum;
}

int solution(int n, int k) {
    int answer = 0;
    vector<string> splited;
    string temp, knum = decToK(n, k);

    for (int i = 0; i < knum.length(); i++) {
        if (knum[i] != '0')
            temp += knum[i];
        if (temp.length() > 0 && (i == knum.length() - 1 || knum[i] == '0'))
            splited.push_back(temp), temp.clear();
    }

    for (const string& s : splited) {
        if (isPrime(stoll(s)))
            answer++;
    }

    return answer;
}