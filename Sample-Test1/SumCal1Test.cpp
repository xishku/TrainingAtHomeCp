#include "pch.h"
#include "SumCal1Test.hpp"


TEST_F(SumCal1Test, Target35ElementShouldBe3and7) {
	std::vector<int> inNums = { 1, 11, 111, 2, 22, 222, 3, 33, 333 };
	std::vector<int> outNums = sCal1.twoSum(inNums, 35);

	int i = 0;
	for (std::vector<int>::const_iterator it = outNums.begin();
		it != outNums.end(); it++)
	{
		if (0 == i)
		{
			EXPECT_EQ(3, *it);
		}

		if (1 == i)
		{
			EXPECT_EQ(7, *it);
		}

		++i;
		//std::cout << "print vector element: " << *it << std::endl;
	}
}

TEST_F(SumCal1Test, BigNumAdding7add8shouldBe15) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

	ListNode l1(7);
	ListNode l2(8);

	ListNode* l3 = sCal1.addTwoNumbers(&l1, &l2);
	ListNode* curNode = l3;
	for (int i = 0; ; ++i)
	{
		if (NULL != curNode)
		{
			if (0 == i)
			{
				EXPECT_EQ(5, curNode->val);
			}
			else
			{
				EXPECT_EQ(1, curNode->val);
			}
			//std::cout << "print sum: " << curNode->val << std::endl;
			curNode = curNode->next;
		}
		else
		{
			break;
		}
	}
}

TEST_F(SumCal1Test, isPalindrome0) {
	EXPECT_EQ(true, sCal1.isPalindrome(0));
}

TEST_F(SumCal1Test, isPalindrome121) {
	EXPECT_EQ(true, sCal1.isPalindrome(121));
}

TEST_F(SumCal1Test, isPalindrome121minus) {
	EXPECT_EQ(false, sCal1.isPalindrome(-121));
}

TEST_F(SumCal1Test, isPalindrome123456) {
	EXPECT_EQ(false, sCal1.isPalindrome(123456));
}



TEST_F(SumCal1Test, lengthOfLongestSubstringabcabcbb) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
	EXPECT_EQ(6, sCal1.lengthOfLongestSubstring("abcabcbbcdefg"));
}

TEST_F(SumCal1Test, lengthOfLongestSubstringbbb) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

	EXPECT_EQ(1, sCal1.lengthOfLongestSubstring("bbb"));
}



TEST_F(SumCal1Test, lengthOfLongestSubstringpwwkew) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

	EXPECT_EQ(3, sCal1.lengthOfLongestSubstring("pwwkew"));
}

TEST_F(SumCal1Test, lengthOfLongestSubstringEmptyStr) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

	EXPECT_EQ(0, sCal1.lengthOfLongestSubstring(""));
}


TEST_F(SumCal1Test, lengthOfLongestSubstringSpaceStr) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

	EXPECT_EQ(1, sCal1.lengthOfLongestSubstring(" "));
}

TEST_F(SumCal1Test, IntegerReverse1534236469) {
	EXPECT_EQ(0, sCal1.integerReverse(INT_MIN));
}

TEST_F(SumCal1Test, IntegerReverseINTMAX) {
	EXPECT_EQ(0, sCal1.integerReverse(INT_MAX));
}

TEST_F(SumCal1Test, IntegerReverse0) {
	EXPECT_EQ(0, sCal1.integerReverse(0));
}

TEST_F(SumCal1Test, IntegerReverse120) {
	EXPECT_EQ(-21, sCal1.integerReverse(-120));
}

TEST_F(SumCal1Test, IntegerReverse12100) {
	EXPECT_EQ(-121, sCal1.integerReverse(-12100));
}

TEST_F(SumCal1Test, IntegerReverse1900) {
	EXPECT_EQ(91, sCal1.integerReverse(1900));
}




