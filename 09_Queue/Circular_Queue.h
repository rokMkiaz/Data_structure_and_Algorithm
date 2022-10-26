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
		datas = NULL; //��۸� ������
	}
	int Capacity() { return capacity; }
	int Front() { return front; }
	int Rear() { return rear; }


	void Enqueue(T data) //������ ����
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
		return rear + (capacity - front) + 1; //�뷮-����Ʈ��ŭ ���ְ� ��� �� ��ŭ �����ش�.
	}
	

private:
	T* datas; //�迭�� ������ ����
	int capacity;
	int front = 0; //��
	int rear = 0;  //��
};