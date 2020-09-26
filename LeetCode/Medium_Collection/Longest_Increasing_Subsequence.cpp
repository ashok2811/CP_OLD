/*
Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Note:

    There may be more than one LIS combination, it is only necessary for you to return the length.
    Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

*/


class Solution {   // N^2 Solution
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		int LIS[n]; int maxlen = 1 ;

		for (int i = 0; i < n; ++i)
		{
			LIS[i] = 1; //FILL WITH ONE
		}

		for (int i = 0 ; i < n ; i++ ) {
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] > nums[j]) {
					// Probable candidate
					if (LIS[i] <= LIS[j]) {
						LIS[i] = 1 + LIS[j];
						maxlen = max(maxlen , LIS[i]);

					}
				}
			}

		}

		return maxlen;

	}
};

// Follow up : If you want the elements , just interate from the last  -- >> first.
// Start first from maxlen index, and go to 1 . Each time you find any element with LIS = malen-1
// include it in you seq ab make now search for maxlen -2 ...... till 1
