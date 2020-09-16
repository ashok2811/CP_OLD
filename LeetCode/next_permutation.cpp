// Implement next permutation, which rearranges numbers
// into the lexicographically next greater permutation of numbers.

 class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        if(n<2) return; // if size is 1 just return
        
        int ind_1= n-2;   
        while(ind_1>=0&&nums[ind_1]>=nums[ind_1+1]) ind_1--;
        
        if(ind_1>=0){
            int ind_2 = n-1 ;
            while(nums[ind_2]<=nums[ind_1]) ind_2--;
            swap(nums[ind_1] ,nums[ind_2]);
         
        }
                
        reverse(nums.begin()+(ind_1+1), nums.end());
      
        
    }
};