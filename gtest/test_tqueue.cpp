#include "gtest.h"

#include "..\TQueue.h"

TEST(TQueue, can_create_stack_with_positive_size)
{
	ASSERT_NO_THROW(TQueue<int> s(20));
}

TEST(TQueue, cant_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> s(-1));
}

TEST(TQueue, can_create_copied_stack)
{
	TQueue<int> sc;

	ASSERT_NO_THROW(TQueue<int> s(sc));
}

TEST(TQueue, can_push_and_pop_element)
{
	TQueue<int> s;
	s.Push(2);

	EXPECT_EQ(2, s.Pop());
}

TEST(TQueue, can_get_top)
{
	TQueue<int> s;
	s.Push(2);

	EXPECT_EQ(2, s.Top());
}

TEST(TQueue, cant_push_element_in_full_stack)
{
	TQueue<int> s(1);
	s.Push(2);

	ASSERT_ANY_THROW(s.Push(2));
}

TEST(TQueue, cant_pop_element_from_empty_stack)
{
	TQueue<int> s(1);

	ASSERT_ANY_THROW(s.Pop());
}

TEST(TQueue, can_clear_stack)
{
	TQueue<int> s;
	s.Push(2);
	s.Clear();

	EXPECT_TRUE(s.Is_empty());
}

TEST(TQueue, compare_equal_stacks_return_true)
{
	TQueue<int> s;
	s.Push(2);
	TQueue<int> s1;
	s1.Push(2);

	EXPECT_TRUE(s == s1);
}

TEST(TQueue, compare_not_equal_stacks_return_false)
{
	TQueue<int> s;
	s.Push(2);
	TQueue<int> s1;
	s1.Push(2);
	s1.Push(3);

	EXPECT_FALSE(s == s1);
}
