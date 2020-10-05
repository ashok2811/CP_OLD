/*
Find Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() ; 
        int peak;
        if(nums[0]>nums[n-1]) peak = 0 ;
        else peak = n-1;
        
        for(int i = 1; i< n-1 ; i++ ){
            if(nums[i-1] < nums[i] && nums[i]>nums[i+1]) {peak = i; break;}
        }
        
        return peak;
    }
};
