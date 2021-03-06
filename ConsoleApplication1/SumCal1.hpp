#include <vector>
#include <string>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class SumCal1
{
public:
	int strStr(string haystack, string needle);
	int removeElement(vector<int>& nums, int val);
	int removeDuplicates(vector<int>& nums);
	bool isPalindrome(int x);
	std::vector<int> twoSum(std::vector<int>& nums, int target);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	int lengthOfLongestSubstring(std::string s);
	int lengthOfLongestSubstringLowSpeed(std::string s);
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
	int integerReverse(int x);
};



