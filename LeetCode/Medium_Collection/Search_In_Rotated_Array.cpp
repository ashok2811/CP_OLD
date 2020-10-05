/*
Search in Rotated Sorted Array

You are given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand 
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
            int n = nums.size();
        if(n==0){
            return -1;
        }
        int L = 0 ; int R = n-1;
        int first = nums[0];
        while(L<=R){
            int mid = L + (R-L)/2;
            int value = nums[mid];
            if(value == target){
                return mid;
            }
           
            bool am_big = value >= first;
            bool target_big =  target >= first;
            
            if(am_big == target_big){
                if(value<target){
                    L = mid + 1;
                }
                else{
                    R = mid -1;
                }
            }
            
            else{
                if(am_big){
                    L  = mid +1;
                }
                else{
                    R = mid -1;
                }
        }
        }
        
        return -1;
    
    }
};