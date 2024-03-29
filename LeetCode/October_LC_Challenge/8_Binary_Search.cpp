// Binary Search
// Given a sorted (in ascending order) integer array nums of n 
// elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.
// Example 1:
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

class Solution {
    int BS(vector<int>& nums, int key , int l , int r){        
        while(l<=r){
            int mid = l + (r-l) / 2;
            if(nums[mid] == key){
                return mid;
            }
            
            else{
                if(nums[mid]<key){
                    l = mid + 1 ; 
                }
                else{
                    r = mid -1 ;
                }
            }
        }
        
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return BS(nums, target, 0 , n-1);
    }
};