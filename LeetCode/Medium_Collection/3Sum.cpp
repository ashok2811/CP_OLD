/*
3Sum

Given an array nums of n integers, are there elements a, b, c in nums 
such that a + b + c = 0? Find all unique triplets in the array which 
gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n  = nums.size();
        if(n <3 ) return {} ;
        vector<vector<int>> results ;
        sort(nums.begin() , nums.end()) ;
        for(int  i = 0  ; i< n-2 ;  i++){
            if( i == 0 || nums[i]!=nums[i-1]){
                int j = i+1 , k=n-1;
                while(j<k){
                    int sum = nums[i] + nums[j]  + nums[k] ;
                    if(sum == 0){
                        results.push_back({nums[i] , nums[j] , nums[k]});
                        while(j<k && nums[j] == nums[j+1]) j++;
                        while(j<k && nums[j] == nums[k-1]) k--;   
                        j++; k--;
                    }
                    
                    else if(sum> 0) k--;
                    else j++;
                    
                     
                }
            }
        }
        
        
        return results ; 
    }
};