/*
Given an array of integers nums sorted in ascending order, 
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
Follow up: Could you write an algorithm with O(log n) runtime complexity?
*/

class Solution {

public:
    vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size()==0){
        return {-1 , -1};
    } 
    auto first = lower_bound(nums.begin(), nums.end(), target);
    auto last = lower_bound(nums.begin(), nums.end(), target+1) - 1; 
        
    if(first<=last){
        return {(int)(first - nums.begin() ),(int)(last - nums.begin())};
    }
    else{
        return {-1 , -1};
    }
        
          
    }
};