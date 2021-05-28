#include "../src/rational.h"
#include <gtest/gtest.h>

TEST(TS1, testEquality)
{
    EXPECT_EQ(Rational(1,-2), Rational(-1,2));
    EXPECT_EQ(Rational(1,2), Rational(4,8));
    EXPECT_EQ(Rational(5,5), Rational(2,2));
    EXPECT_EQ(Rational(-1,-3), Rational(1,3));
}

TEST(TS1, testGreaterOrEqual)
{
    EXPECT_GE(Rational(1,2), Rational(2,5));
    EXPECT_GE(Rational(3,4), Rational(1,4));
    EXPECT_GE(Rational(1,4), Rational(-1,4));
}

TEST(TS1, testZeroInDenomExcept)
{
    EXPECT_THROW(Rational(1,0), ZeroInDenomException);
}

