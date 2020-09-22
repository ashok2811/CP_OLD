/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.


*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int fuel = nums[0];
        bool ans = 1;
        for(int i =0 ; i < len-1 ; i++){
            if(fuel){ 
                fuel--;
                 if(nums[i+1]>=fuel){
                    fuel=nums[i+1];
                }
            }
            else{
                ans = 0;
                break;
            }
        }
        return ans;
    }
};