
#include "sample1.h"
#include "gtest/gtest.h"


TEST(CalculateTest, Chance)
{
	int roll[5] = { 1, 2, 3, 4, 5 };
	Category category = Category::CHANCE;

	EXPECT_EQ(15, Calculate(roll, category));
}

TEST(CalculateTest, Ones)
{
	int roll[5] = { 1, 2, 3, 1, 1 };
	Category category = Category::ONES;

	EXPECT_EQ(3, Calculate(roll, category));
}

TEST(CalculateTest, Twos)
{
	int roll[5] = { 1, 2, 3, 1, 1 };
	Category category = Category::TWOS;

	EXPECT_EQ(2, Calculate(roll, category));
}

TEST(CalculateTest, Threes)
{
	int roll[5] = { 3, 2, 3, 3, 3 };
	Category category = Category::THREES;

	EXPECT_EQ(12, Calculate(roll, category));
}

TEST(CalculateTest, Fours)
{
	int roll[5] = { 4, 2, 4, 3, 4 };
	Category category = Category::FOURS;

	EXPECT_EQ(12, Calculate(roll, category));
}

TEST(CalculateTest, Fives)
{
	int roll[5] = { 3, 5, 3, 5, 3 };
	Category category = Category::FIVES;

	EXPECT_EQ(10, Calculate(roll, category));
}

TEST(CalculateTest, Sixes)
{
	int roll[5] = { 6, 6, 6, 6, 6 };
	Category category = Category::SIXES;

	EXPECT_EQ(30, Calculate(roll, category));
}

TEST(CalculateTest, Pairs)
{
	int roll[5] = { 3, 3, 4, 4, 4 };
	Category category = Category::PAIRS;

	EXPECT_EQ(8, Calculate(roll, category));
}

TEST(CalculateTest, TwoPairs)
{
	int roll[5] = { 3, 3, 4, 4, 4 };
	Category category = Category::TWO_PAIRS;

	EXPECT_EQ(14, Calculate(roll, category));
}

TEST(CalculateTest, ThreeOfAKind)
{
	int roll[5] = { 3, 3, 4, 4, 4 };
	Category category = Category::THREE_OF_A_KIND;

	EXPECT_EQ(12, Calculate(roll, category));
}

TEST(CalculateTest, FourOfAKind)
{
	int roll[5] = { 3, 4, 4, 4, 4 };
	Category category = Category::FOUR_OF_A_KIND;

	EXPECT_EQ(16, Calculate(roll, category));
}

TEST(CalculateTest, FullHouse)
{
	int roll[5] = { 3, 3, 4, 4, 4 };
	Category category = Category::FULL_HOUSE;

	EXPECT_EQ(18, Calculate(roll, category));
}

TEST(CalculateTest, Yahtzee)
{
	int roll[5] = { 4, 4, 4, 4, 4 };
	Category category = Category::YAHTZEE;

	EXPECT_EQ(50, Calculate(roll, category));
}

TEST(CalculateTest, NotPairs)
{
	int roll[5] = { 1, 2, 3, 4, 5 };
	Category category = Category::PAIRS;

	EXPECT_EQ(0, Calculate(roll, category));
}

TEST(CalculateTest, NotThreeOfAKind)
{
	int roll[5] = { 1, 2, 2, 3, 4 };
	Category category = Category::THREE_OF_A_KIND;

	EXPECT_EQ(0, Calculate(roll, category));
}

TEST(CalculateTest, NotFourOfAKind)
{
	int roll[5] = { 1, 2, 2, 2, 3 };
	Category category = Category::FOUR_OF_A_KIND;

	EXPECT_EQ(0, Calculate(roll, category));
}

TEST(CalculateTest, NotYahtzee)
{
	int roll[5] = { 1, 4, 4, 4, 4 };
	Category category = Category::YAHTZEE;

	EXPECT_EQ(0, Calculate(roll, category));
}