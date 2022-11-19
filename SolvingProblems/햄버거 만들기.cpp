﻿/*
* 햄버거 만들기
햄버거 가게에서 일을 하는 상수는 햄버거를 포장하는 일을 합니다. 
함께 일을 하는 다른 직원들이 햄버거에 들어갈 재료를 조리해 주면 조리된 순서대로 
상수의 앞에 아래서부터 위로 쌓이게 되고, 상수는 순서에 맞게 쌓여서 완성된 햄버거를
따로 옮겨 포장을 하게 됩니다. 상수가 일하는 가게는 정해진 순서(아래서부터, 빵 – 야채 – 고기 - 빵)
로 쌓인 햄버거만 포장을 합니다. 상수는 손이 굉장히 빠르기 때문에 상수가 포장하는 동안 속
재료가 추가적으로 들어오는 일은 없으며, 재료의 높이는 무시하여 재료가 높이 쌓여서 일이 힘들어지는 경우는 없습니다.

예를 들어, 상수의 앞에 쌓이는 재료의 순서가 [야채, 빵, 빵, 야채, 고기, 빵, 야채, 고기, 빵]일 때,
상수는 여섯 번째 재료가 쌓였을 때, 세 번째 재료부터 여섯 번째 재료를 이용하여 햄버거를 포장하고,
아홉 번째 재료가 쌓였을 때, 두 번째 재료와 일곱 번째 재료부터 아홉 번째 재료를 이용하여 햄버거를 포장합니다. 
즉, 2개의 햄버거를 포장하게 됩니다.

상수에게 전해지는 재료의 정보를 나타내는 정수 배열 ingredient가 주어졌을 때, 상수가 포장하는 햄버거의 
개수를 return 하도록 solution 함수를 완성하시오.

* 제한사항
1 ≤ ingredient의 길이 ≤ 1,000,000
ingredient의 원소는 1, 2, 3 중 하나의 값이며, 순서대로 빵, 야채, 고기를 의미합니다.

* 입출력 예
ingredient							result
[2, 1, 1, 2, 3, 1, 2, 3, 1]			2    
[1, 3, 2, 1, 2, 1, 3, 1, 2]			0

*풀이
햄버거를 만들 수 있는 올바른 순서는 1,2,3,1 이다.
나는 ingredient를 처음부터 끝까지 탐색하면서 문자열 sequence에 재료를 순서대로 쌓고
sequence에 4개 이상의 재료가 쌓였을 때 "1231"을 포함하고 있는지 검사하고자 했다.

ingredient가 [2, 1, 1, 2, 3, 1, 2, 3, 1]일 때 sequence의 변화를 살펴보며 이해해보자.

sequence : "2" -> "21" -> "211" -> "2112" (포함x) -> "21123" (포함x) -> "211231" (포함)

sequence : "21" -> "212" -> "2123" (포함x) -> "21231" (포함)
*/

#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = { -1 };
    for (int x : ingredient) {
        if (v.back() == 1 && x == 2) v.back() = 12;
        else if (v.back() == 12 && x == 3) v.back() = 123;
        else if (v.back() == 123 && x == 1) answer++, v.pop_back();
        else v.push_back(x);
    }

    return answer;
}