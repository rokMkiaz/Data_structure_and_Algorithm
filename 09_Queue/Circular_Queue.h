#pragma once

template<typename T> class Circular_Queue
{
public:
	Circular_Queue(int capacity)
		:capacity(capacity)
	{
		datas = new T[capacity + 1];

	}
	~Circular_Queue()
	{
		delete[] datas;
		datas = NULL; //댕글리 포인터
	}
	int Capacity() { return capacity; }
	int Front() { return front; }
	int Rear() { return rear; }


	void Enqueue(T data) //데이터 삽입
	{
		int position = 0;
		if (rear == capacity)
		{
			position = rear;
			rear = 0;

		}
		else
		{
			position = rear++;
		}

		datas[position] = data;
	}

	T Dequeue()
	{
		int position = front;

		if (front == capacity)
		{
			front = 0;

		}
		else
		{
			front++;
		}

		return datas[position];
	}

	bool IsEmpty()
	{
		return front == rear;
	}

	bool IsFull()
	{
		if (front < rear)
			return (rear - front) == capacity;

		return (rear + 1) == front;
	}
	int Size()
	{
		if(front <=rear)
			return rear - front;
		return rear + (capacity - front) + 1; //용량-프론트만큼 빼주고 리어가 온 만큼 더해준다.
	}
	

private:
	T* datas; //배열을 저장할 변수
	int capacity;
	int front = 0; //앞
	int rear = 0;  //뒤
};