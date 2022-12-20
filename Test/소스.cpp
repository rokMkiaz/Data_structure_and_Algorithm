#include<string>
#include<queue>
using namespace std;

bool solution(string s, string t)
{
	bool answer = true;

	int s_Size = s.size()-1;

	return answer;
}

void main()
{
	string a = "ilwoo23";
	string b = "dong";

	queue<int,int> q;
	int k[] = { 5,2 };
	q.push(k);

	//if (b < a) b = a;

	printf_s("%d %d", q.front().pop());

}
/*
	0 1 2
	0 1 2 0 1 2

*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    long long left = (long long)times[0];
    long long right = (long long)times[times.size() - 1] * n;
    long long answer = right;
    while (left <= right) {
        long long mid = (right + left) / 2;
        long long pass = 0;

        for (int i = 0; i < times.size(); ++i)
            pass += mid / (long long)times[i];

        if (pass >= n) {
            right = mid - 1;
            if (mid <= answer)
                answer = mid;
        }
        else
            left = mid + 1;
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//사람 수, 심사 걸리는 시간
long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    long long left = (long long)times[0];
    long long right = (long long)times[times.size() - 1] * n;
    long long answer = right;
    while (left <= right) {
        long long mid = (right + left) / 2;
        long long pass = 0;

        for (int i = 0; i < times.size(); ++i)
            pass += mid / (long long)times[i];

        if (pass >= n) {
            right = mid - 1;
            if (mid <= answer)
                answer = mid;
        }
        else
            left = mid + 1;
    }
    return answer;
}
//심사대 수, 걸리는 시간(뒷부분만 필요)
long long solution(int n,  vector<vector<int>> datas) {
    sort(datas.begin(), datas.end());
    datas[0][1];
    long long left = (long long)times[0];
    long long right = (long long)times[times.size() - 1] * n;
    long long answer = right;
    while (left <= right) {
        long long mid = (right + left) / 2;
        long long pass = 0;

        for (int i = 0; i < times.size(); ++i)
            pass += mid / (long long)times[i];

        if (pass >= n) {
            right = mid - 1;
            if (mid <= answer)
                answer = mid;
        }
        else
            left = mid + 1;
    }
    return answer;
}