#include "SumCal1.hpp"
#include  <iostream>
#include <map>
#include <algorithm>


int SumCal1::strStr(string haystack, string needle) {
	if (needle.empty())
	{
		return 0;
	}

	size_t hayLen = haystack.size();
	size_t neeLen = needle.size();
	
	for (int i = 0; i <= (int)(hayLen - neeLen); ++i)
	{
		int j = 0;
		for (; j < (int)neeLen; ++j)
		{
			if (haystack.at(i + j) != needle.at(j))
			{
				break;
			}			
		}

		if (j == neeLen)
		{
			return i;
		}
	}

	return -1;
}

int SumCal1::removeElement(vector<int>& nums, int val) {
	size_t len = nums.size();
	if (len == 0)
	{
		return 0;
	}

	size_t i = 0;
	for (size_t j = 0; j < len; ++j)
	{
		if (nums.at(j) != val)
		{
			nums.at(i++) = nums.at(j);
		}
	}

	return i;
}

int SumCal1::removeDuplicates(vector<int>& nums) {

	size_t len = nums.size();
	if (len == 0)
	{
		return 0;
	}
	int i = 0;
	for (size_t j = 1; j < len; ++j)
	{
		//cout << i << "," << j << endl;
		if (nums.at(i) != nums.at(j))
		{
			nums.at(++i) = nums.at(j);
		}
		
	}

	//cout << i << endl;
	return i + 1;
}


bool SumCal1::isPalindrome(int x) {
	if (x < 0 || (x % 10 == 0 && x != 0))
	{
		return false;
	}

	vector<int> numList;
	int tempNum = x;
	while (tempNum > 0)
	{	
		numList.push_back(tempNum % 10);
		tempNum /= 10;
	}

	size_t listLen = numList.size();
	for (int i = 0; i < (int)listLen / 2; ++i)
	{
		if (numList.at(i) != numList.at(listLen -1 - i))
		{
			return false;
		}
	}

	return true;
	
}

/***
https://leetcode-cn.com/problems/two-sum
***/
std::vector<int> SumCal1::twoSum(std::vector<int>& nums, int target)
{
	int countNums = (int)nums.size();
	for (int i = 0; i < countNums; ++i)
	{

		for (int j = i + 1; j < countNums; ++j)
		{
			if (target == nums[i] + nums[j])
			{
				//std::cout << "print vector element: " << i << "&" << j << std::endl;
				std::vector<int> resNums = { i, j };
				return resNums;
			}
		}
	}

	std::vector<int> resNums;
	return resNums;
}

/***
https://leetcode-cn.com/problems/add-two-numbers
***/
ListNode* SumCal1::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* l3 = NULL;
	ListNode* nowL1 = l1;
	ListNode* nowL2 = l2;
	int numPos = 0;
	ListNode* curNode = NULL;
	for (int i = 0; ; ++i)
	{
		if (NULL != nowL1 || NULL != nowL2 || 0 < numPos)
		{
			ListNode* tmpNode = new ListNode(numPos);
			if (0 == i)
			{
				l3 = tmpNode;
			}
			else
			{
				curNode->next = tmpNode;
			}
			curNode = tmpNode;
		}

		if (NULL == nowL1 && NULL == nowL2)
		{
			return l3;
		}

		if (NULL != nowL1)
		{
			curNode->val += nowL1->val;
			nowL1 = nowL1->next;
		}

		if (NULL != nowL2)
		{
			curNode->val += nowL2->val;
			nowL2 = nowL2->next;
		}

		numPos = curNode->val / 10;
		curNode->val = curNode->val % 10;
	}

	return l3;
}


/***
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
***/
int SumCal1::lengthOfLongestSubstring(std::string s) {
	size_t length = s.size();
	std::string tmpStr;
	//std::map<int, int> childPos;
	int maxLen = 0;

	size_t curStartPos = 0;
	for(size_t curPos = 0; curPos < length; ++curPos)
	{		
		char ch = s[curPos];
		//std::cout << "Charator: " << s[curPos] << "     cur Position: " << curPos << std::endl;
		
		const size_t lenTempStr = tmpStr.size();
		//std::cout << "tmpStr: " << tmpStr << std::endl;
		for(size_t i = 0; i < lenTempStr; ++i)
		{
			if (ch == tmpStr[i])
			{
				//std::cout << "find " << ch << " in tmpStr: " << tmpStr << std::endl;
				maxLen = std::max(maxLen, (int)lenTempStr);
				
				tmpStr = tmpStr.substr(i + 1);
				//std::cout << "updated tmpStr: " << tmpStr << std::endl;
				break;
			}
		}
		tmpStr += ch;
	}
	maxLen = std::max(maxLen, (int)tmpStr.size());
	//std::cout << "print vector element: " << i << "&" << j << std::endl;

	return maxLen;
}


/***
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
***/
int SumCal1::lengthOfLongestSubstringLowSpeed(std::string s) {
	size_t length = s.size();
	std::map<int, int> childStr;
	//std::map<int, int> childPos;
	int maxLen = 0;

	for (size_t i = 0; i < length; ++i)
	{
		for (size_t j = i; j < length; ++j)
		{
			char ch = s[j];
			std::cout << "lengthOfLongestSubstring: " << int(s[j]) << std::endl;
			if (childStr.find(ch) != childStr.end())//find same charator
			{
				maxLen = std::max(maxLen, (int)(j - i));

				childStr.clear();
				break;
			}
			else
			{
				//std::cout << "same charator not find! " << std::endl;
				childStr[ch] = ch;

				if (length - 1 == j)
				{
					maxLen = std::max(maxLen, (int)(length - i));
					childStr.clear();
				}

			}
		}
	}
	//std::cout << "print vector element: " << i << "&" << j << std::endl;

	return maxLen;
}


/***
https://leetcode-cn.com/problems/median-of-two-sorted-arrays
***/
double SumCal1::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	
	return 0.1;
}

/***
https://leetcode-cn.com/problems/reverse-integer
***/
int SumCal1::integerReverse(int x) {
	int pop = x;
	int push = 0;
	while (pop != 0)
	{
		int num = pop % 10;

		pop /= 10;

		if (push > (INT32_MAX / 10) || push < (INT_MIN / 10) 
			|| (push == INT_MAX / 10 && pop > 7) || (push == INT_MIN / 10 && pop < -8))
		{
			return 0;
		}
		push = push * 10 + num;
	}

	return push;
}



