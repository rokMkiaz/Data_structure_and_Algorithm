/*
* 숫자 카드 나누기
철수와 영희는 선생님으로부터 숫자가 하나씩 적힌 카드들을 절반씩 나눠서 가진 후,
다음 두 조건 중 하나를 만족하는 가장 큰 양의 정수 a의 값을 구하려고 합니다.

철수가 가진 카드들에 적힌 모든 숫자를 나눌 수 있고 영희가 가진 카드들에 적힌 모든 숫자들 중 하나도 나눌 수 없는 양의 정수 a
영희가 가진 카드들에 적힌 모든 숫자를 나눌 수 있고, 철수가 가진 카드들에 적힌 모든 숫자들 중 하나도 나눌 수 없는 양의 정수 a
예를 들어, 카드들에 10, 5, 20, 17이 적혀 있는 경우에 대해 생각해 봅시다. 
만약, 철수가 [10, 17]이 적힌 카드를 갖고, 영희가 [5, 20]이 적힌 카드를 갖는다면 두 조건 중 하나를 만족하는 
양의 정수 a는 존재하지 않습니다. 하지만, 철수가 [10, 20]이 적힌 카드를 갖고, 영희가 [5, 17]이 적힌 카드를 갖는다면, 
철수가 가진 카드들의 숫자는 모두 10으로 나눌 수 있고, 영희가 가진 카드들의 숫자는 모두 10으로 나눌 수 없습니다. 
따라서 철수와 영희는 각각 [10, 20]이 적힌 카드, [5, 17]이 적힌 카드로 나눠 가졌다면 조건에 해당하는 양의 정수 a는 10이 됩니다.

철수가 가진 카드에 적힌 숫자들을 나타내는 정수 배열 arrayA와 영희가 가진 카드에 적힌 숫자들을 나타내는 정수
배열 arrayB가 주어졌을 때, 주어진 조건을 만족하는 가장 큰 양의 정수 a를 return하도록 solution 함수를 완성해 주세요.
만약, 조건을 만족하는 a가 없다면, 0을 return 해 주세요.
* 제한사항

1 ≤ arrayA의 길이 = arrayB의 길이 ≤ 500,000
1 ≤ arrayA의 원소, arrayB의 원소 ≤ 100,000,000
arrayA와 arrayB에는 중복된 원소가 있을 수 있습니다.

* 입출력 예
arrayA	         arrayB  	    result
[10, 17]	    [5, 20]     	  0
[10, 20]	    [5, 17]     	  10
[14, 35, 119]	[18, 30, 102]	  7

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> candidate, my, other;

void find_candidate(int num)//약수 찾기
{ 
    candidate.push_back(num);
    for (int i = num / 2; i > 1; i--) //my의 최소 값인 num의 약수들 찾기
        if (num % i == 0) candidate.push_back(i);

}

int check()
{
    int ret = 0;
    for (auto c : candidate) 
    {
        int flag = 1;
        for (int i = 0; i < my.size(); i++) 
        {
            if (my[i] % c != 0 || other[i] % c == 0) 
            { 
                flag = 0;
                break; //이미 조건을 만족하지 못하므로 나머지 검사 x
            }
        }
        //후보군은 내림차순으로 정렬돼 있으므로 찾았으면 바로 종료
        if (flag) {
            ret = c;
            break;
        }
    }
    return ret; //ret 초기값이 0이므로 조건을 만족하는 수를 찾지 못하면 0을 반환함.
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int answer = 0;
    sort(arrayA.begin(), arrayA.end()); 
    sort(arrayB.begin(), arrayB.end());

    find_candidate(arrayA[0]);
    my = arrayA, other = arrayB;
    answer = max(answer, check());

    candidate.clear();
    my = arrayB, other = arrayA;
    find_candidate(arrayB[0]);
    answer = max(answer, check());

    return answer; //answer 초기값이 0이므로 조건을 만족하는 a를 찾지 못하면 0을 반환함.
}