#include <iostream>
#include "TQueue.h"

void main()
{
	TQueue<int> q(3);
	q.Push(1);
	q.Push(2);

	std::cout << q.Pop() << std::endl;

	q.Push(3);
	q.Push(4);

	std::cout << q.Pop() << std::endl;
}