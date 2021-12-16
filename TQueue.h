#pragma once

template <class T> 
class TQueue
{
	int tail;
	int head;
	T* queue;
	int MaxSize;
	int countEl;

public: 

	TQueue (int MaxSize = 10) : MaxSize(MaxSize), head(0), tail(-1), countEl(0)
	{
		if (MaxSize < 0)
			throw MaxSize;
		queue = new T[MaxSize];
	}

	TQueue(const TQueue& tq) : MaxSize(tq.MaxSize), head(tq.head), tail(tq.tail), countEl(tq.countEl)
	{
		queue = new T[MaxSize];
		for (int i = 0; i < MaxSize; i++)
		{
			queue[i] = tq.queue[i];
		}
	}

	int GetMaxSize() const{
		return MaxSize;
	}

	int GetCountEl() const {
		return countEl;
	}

	int GetHead() const {
		return head;
	}

	void Push(const T& elem)
	{
		if (IsFull())
			throw countEl;
		tail = (tail + 1) % MaxSize;
		queue[tail] = elem;
		countEl++;
	}

	T Pop()
	{
		if (IsEmpty())
			throw countEl;
		T tmp = queue[head];
		head = (head + 1) % MaxSize;
		countEl--;
		return tmp;
	}

	bool IsEmpty() const
	{
		return countEl == 0;
	}

	bool IsFull() const
	{
		return countEl == MaxSize;
	}

	T& Back()
	{
		if (IsEmpty())
			throw 0;
		return queue[tail];
	}

	T& Front()
	{
		if (IsEmpty())
			throw 0;
		return queue[head];
	}

	~TQueue()
	{
		delete[] queue;
	}
};

