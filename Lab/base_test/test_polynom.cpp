#include "polynom.h"
#include <gtest.h>

TEST(TPolynom, can_create_polynom)
{
	TPolynom a;
	ASSERT_NO_THROW(a.Create("1x1y1z1"));
}
TEST(TPolynom, can_get_coef)
{
	TPolynom a;
	a.Create("1x1y1z1");
	EXPECT_EQ(a.getListCoeff(1), 1);
}
TEST(TPolynom, can_get_exp)
{
	TPolynom a;
	a.Create("1x1y1z1");
	EXPECT_EQ(a.getListExp(1), 111);
}
TEST(TPolynom, can_get_count)
{
	TPolynom a;
	a.Create("1x1y1z1");
	EXPECT_EQ(a.getListCount(), 1);
}
TEST(TPolynom, can_calculate)
{
	TPolynom a;
	a.Create("2x1y2z3+1x2y1z3");
	EXPECT_EQ(a.Calculate(3,2,1), 42);
}
