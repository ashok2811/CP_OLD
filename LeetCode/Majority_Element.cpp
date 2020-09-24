/*
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority 
element always exist in the array.
Example 1:
Input: [3,2,3]
Output: 3
Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2 */

// Key : Boyer's Moore Voting Algorithm : If you are sure that some one is 
// in majority try cancelling out count if it is not that element , eventually 
// you will end up with majority element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count  = 0 ;
        int m_ele ;
        int n = nums.size();
        
        for(int i = 0 ; i< n ; i++){
            if(count==0){
                m_ele = nums[i];
                count++;
            }
            else{
                if(nums[i]!=m_ele) count--;
                else count ++ ;
            }
            
        }
        
        
       return m_ele ; 
        
    }
};