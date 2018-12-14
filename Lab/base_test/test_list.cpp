#include <gtest.h>
#include "list.h"

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> a);
}
TEST(TList, can_copy_list)
{
	TList<int> f;
	ASSERT_NO_THROW(TList<int> a(f));
}
TEST(TList, can_get_count)
{
	TList<int> f;
	f.add(1, 1);
	EXPECT_EQ(f.getCount(), 1);
}
TEST(TList, can_get_coeff)
{
	TList<int> f;
	f.add(1, 1);
	EXPECT_EQ(f.getCoeff(1), 1);
}
TEST(TList, can_get_exp)
{
	TList<int> f;
	f.add(1, 1);
	EXPECT_EQ(f.getExp(1), 1);
}
TEST(TList, can_add)
{
	TList<int> f;
	f.add(1, 1);
	EXPECT_EQ(f.getCoeff(1) + f.getExp(1), 2);
}
TEST(TList, can_delete)
{
	TList<int> f;
	f.add(1, 1);
	ASSERT_NO_THROW(f.del(1));
}