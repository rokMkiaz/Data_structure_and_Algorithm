/*
���ڿ� "hello"���� �� ���ڸ� ���������� �� ĭ�� �а� ������ ���ڴ� �� ������ �̵���Ű��
"ohell"�� �˴ϴ�. �̰��� ���ڿ��� �δٰ� �����Ѵٸ� ���ڿ� A�� B�� �Ű������� �־��� ��,
A�� �о B�� �� �� �ִٸ� �� �� �о�� �ϴ��� Ƚ���� return�ϰ� �о B�� �� �� ������
-1�� return �ϵ��� solution �Լ��� �ϼ��غ�����.

* ���ѻ���
0 < A�� ���� = B�� ���� < 100
A, B�� ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.

* ����� ��
A	            B	            result
"hello"	        "ohell"	            1
"apple"	        "elppa"	           -1


* ����� �� #1
"hello"�� ���������� �� ĭ �и� "ohell"�� �˴ϴ�.

* ����� �� #2
"apple"�� �� ���� �о "elppa"�� �� �� �����ϴ�.
*/


#include <string>

using namespace std;

int solution(string A, string B)
{

    B += B; // ohell+ohell => hello��ġ�� ã��
    sizeof(B);
    return B.find(A); //���ϴ� ���ڿ��� ��ġ�� ã�´�.
}