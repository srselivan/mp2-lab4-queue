#include "gtest.h"

#include "..\TQueue.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue<int> s(20));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> s(-1));
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> sc;

	ASSERT_NO_THROW(TQueue<int> s(sc));
}

TEST(TQueue, can_push_and_pop_element)
{
	TQueue<int> s;
	s.Push(2);
	s.Push(1);

	EXPECT_EQ(2, s.Pop());
}

TEST(TQueue, can_get_top)
{
	TQueue<int> s;
	s.Push(2);
	s.Push(1);

	EXPECT_EQ(2, s.Front());
}

TEST(TQueue, cant_push_element_in_full_queue)
{
	TQueue<int> s(1);
	s.Push(2);

	ASSERT_ANY_THROW(s.Push(2));
}

TEST(TQueue, cant_pop_element_from_empty_queue)
{
	TQueue<int> s(1);

	ASSERT_ANY_THROW(s.Pop());
}
