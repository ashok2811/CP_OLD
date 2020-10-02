/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.
*/

//Resursive Solution

class Solution {
    void gen_subset(vector<int>& nums, int idx, vector<vector<int>>& result){
      if(idx == nums.size()-1){
          // Base Case
          result.push_back({});
          result.push_back({nums[idx]}); // [1,2,3] idx == 2 {} , {3} 
           
      }  
        // {} , {3} , {2} , {3, 2} ,{1} , {3,1} , {2,1} , {3, 2, 1}
    else{
        gen_subset(nums, idx+1 , result); // First return idx == 2
        int n = result.size();
        for(int i = 0 ; i< n ;i++){
            vector<int> temp = result[i]; 
            temp.push_back(nums[idx]);
            result.push_back(temp);
        }
            
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        gen_subset(nums, 0 , result);
            
        return result;
    }
};


// Iterative Solution

//IterativeSolution

class Solution {   
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return {{}};
        vector<vector<int>> result = {{}};
        
        for(int x : nums){
            int n = result.size();
            for(int i = 0 ; i < n ; i++){
                vector<int> temp = result[i];
                temp.push_back(x);
                result.push_back(temp);
            }
        }
            
        return result;
    }
};


// DP & BitMasking 

// (N)*(2^N)

class Solution {   
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return {{}};
        vector<vector<int>> result ;        
        int n = nums.size();
        int total = 1<<n ; // Number of subsets

            for(int i = 0 ; i < total ; i++){ // generate all of them
                vector<int> temp;
                for(int j = 0 ; j < n ; j++){  // iterate in all digits                  
                    int f = 1 << j ;   // 
                    if((i & f) !=0 ){
                        temp.push_back(nums[j]);
                    }
                    
                }
                result.push_back(temp);
            }
        
            
        return result;
    }
};

