
#ifndef GTEST_SAMPLES_SAMPLE1_H_
#define GTEST_SAMPLES_SAMPLE1_H_

#include <vector>
#include <algorithm>

enum class Category
{
	CHANCE,
	ONES,
	TWOS,
	THREES,
	FOURS,
	FIVES,
	SIXES,
	PAIRS,
	TWO_PAIRS,
	THREE_OF_A_KIND,
	FOUR_OF_A_KIND,
	FULL_HOUSE,
	YAHTZEE

};

int CalculateChance(int roll[5])
{
	int sum = 0;

	for (int i = 0; i < 5; ++i)
	{
		sum += roll[i];
	}
	
	return sum;
}

int CalculateSameNumberAmount(int roll[5], int numberToCount)
{
	int sum = 0;

	for (int i = 0; i < 5; ++i)
	{
		if (roll[i] == numberToCount)
		{
			sum += numberToCount;
		}
	}

	return sum;
}

std::vector<int>::reverse_iterator FindLargestSequence(std::vector<int>::reverse_iterator begin, std::vector<int>::reverse_iterator end, int sequenceLength)
{
	int currentValue = -1;
	int numberOfOcurrences = 0;

	std::vector<int>::reverse_iterator lastIter;
	for (std::vector<int>::reverse_iterator iter = begin; iter != end; ++iter)
	{
		int value = *iter;
		if(currentValue == value)
		{
			++numberOfOcurrences;
		}
		else
		{
			if(numberOfOcurrences == sequenceLength)
			{
				return lastIter;
			}
			currentValue = value;
			numberOfOcurrences = 1;
		}
		lastIter = iter;
	}
	return end;
}

int FindLargestSequenceInArray(int roll[5], int sequenceLength)
{
	std::vector<int> rollVector;
	rollVector.assign(roll, roll + 5);
	std::sort(rollVector.begin(), rollVector.end());
	std::vector<int>::reverse_iterator iter = FindLargestSequence(rollVector.rbegin(), rollVector.rend(), sequenceLength);
	if(iter != rollVector.rend())
	{
		return *iter;
	}
	return 0;
}

int Calculate(int roll[5], Category category)
{
	switch (category)
	{
		case Category::CHANCE:
		{
			return CalculateChance(roll);
		}
		case Category::ONES:
		case Category::TWOS:
		case Category::THREES:
		case Category::FOURS:
		case Category::FIVES:
		case Category::SIXES:
		{
			return CalculateSameNumberAmount(roll, static_cast<int>(category));
		}
		case Category::PAIRS:
		{
			return FindLargestSequenceInArray(roll, 2) * 2;
		}
		case Category::TWO_PAIRS:
		{
			std::vector<int> rollVector;
			rollVector.assign(roll, roll + 5);
			std::sort(rollVector.begin(), rollVector.end());

			auto firstPairIter = FindLargestSequence(rollVector.rbegin(), rollVector.rend(), 2);
			if(firstPairIter == rollVector.rend())
				return 0;

			auto secondPairIter = FindLargestSequence(firstPairIter + 1, rollVector.rend(), 2);

			if(firstPairIter != rollVector.rend() && secondPairIter != rollVector.rend())
			{
				return ((*firstPairIter) * 2) + ((*secondPairIter) * 2);
			}
			return 0;
		}

		case Category::THREE_OF_A_KIND:
		{
			return FindLargestSequenceInArray(roll, 3) * 3;
		}
		case Category::FOUR_OF_A_KIND:
		{
			return FindLargestSequenceInArray(roll, 4) * 4;
		}
		case Category::FULL_HOUSE:
		{
			std::vector<int> rollVector;
			rollVector.assign(roll, roll + 5);
			std::sort(rollVector.begin(), rollVector.end());

			auto pairIter = FindLargestSequence(rollVector.rbegin(), rollVector.rend(), 2);
			if(pairIter == rollVector.rend())
				return 0;

			auto threeOfAKindIter = FindLargestSequence(rollVector.rbegin(), rollVector.rend(), 3);
			if(threeOfAKindIter == rollVector.rend())
				return 0;

			return ((*pairIter) * 2) + ((*threeOfAKindIter) * 3);
		}
		case Category::YAHTZEE:
		{
			int sum = FindLargestSequenceInArray(roll, 5) * 5;
			if(sum > 0)
			{
				return 50;
			}
			return 0;

		}
		default:
		{
			return -1;
		}

	}
}

#endif  // GTEST_SAMPLES_SAMPLE1_H_
