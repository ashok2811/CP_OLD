// Majority Element II

/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Note: The algorithm should run in linear time and in O(1) space.
Example 1:
Input: [3,2,3]
Output: [3]
*/

// Key : There will always be atmost 2 majority elements;  

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1 , num2 = -1, cnt1=0, cnt2 =0;
        int n = nums.size();
        
        for(auto x : nums){
          if(x == num1) cnt1++;
            else if(x == num2) cnt2++;
            else if(cnt1==0){
                num1=x; cnt1++;
            }
            else if(cnt2==0){
                num2 = x ; cnt2++;
            }
            else{
                cnt1--; cnt2--;
            }
          
        }
        
        cout << cnt1 << " " << cnt2 ; 
        vector<int> ans;
        cnt1 = 0, cnt2=0 ;
        
        for(int i = 0 ; i< n ;i++){
            if(nums[i] == num1) cnt1++;
            if(nums[i] == num2) cnt2++;
         }
        
        if(cnt1> n/3){
            ans.push_back(num1);
        }
        
        if(cnt2 > n/3){
            ans.push_back(num2);
        }
        
        return ans;
    }
};