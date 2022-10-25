#include <iostream>
#include <string>
using namespace std;

template<typename T> class Character
{
public:
	void Set(T name)
	{
		this->name = name; //이름받아오기
	}

	void Print()
	{
		cout << "캐릭터 이름 : " << name << endl;
	}

private:
	T name;
};

class Player : public Character<string> //<String>일 경우 상속되는 특수화
{

};

class A
{
public:
	void Test(); //클래스 내부에 정의를 포함한 함수는 inline취급된다.
	inline void Test2(); //외부에서 정의를 하면 inline x, inline화 시키고 싶다면 inline키워드를 추가해줘야함.
	_inline void Test3(); //위와 동일
	__inline void Test4(); //__forceinline: 시스템이 아닌 프로그래머의 설정을 우선시 하는 inline
};

void main()
{
	Character<int> ob;
	ob.Set(20);
	ob.Print();

	Player player;
	player.Set("포링");
	player.Print();
}

inline void A::Test() {}

void A::Test2()
{
}
