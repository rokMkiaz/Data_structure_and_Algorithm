#include <iostream>
#include <string>
using namespace std;

template<typename T> class Character
{
public:
	void Set(T name)
	{
		this->name = name; //�̸��޾ƿ���
	}

	void Print()
	{
		cout << "ĳ���� �̸� : " << name << endl;
	}

private:
	T name;
};

class Player : public Character<string> //<String>�� ��� ��ӵǴ� Ư��ȭ
{

};

class A
{
public:
	void Test(); //Ŭ���� ���ο� ���Ǹ� ������ �Լ��� inline��޵ȴ�.
	inline void Test2(); //�ܺο��� ���Ǹ� �ϸ� inline x, inlineȭ ��Ű�� �ʹٸ� inlineŰ���带 �߰��������.
	_inline void Test3(); //���� ����
	__inline void Test4(); //__forceinline: �ý����� �ƴ� ���α׷����� ������ �켱�� �ϴ� inline
};

void main()
{
	Character<int> ob;
	ob.Set(20);
	ob.Print();

	Player player;
	player.Set("����");
	player.Print();
}

inline void A::Test() {}

void A::Test2()
{
}
