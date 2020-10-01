/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]


*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        if(nums.size()<=1) return {nums};
        
        vector<vector<int>> result;
        
        for(int i =0 ; i< nums.size() ; i++){
            vector<int> temp = nums;
            temp.erase(temp.begin()+i); // erase the chosen one
            auto res = permute(temp); // apply the same on the rest of the element
            
            for(int j = 0 ; j < res.size(); j++){  // for each lement in the permutation
                vector<int> temp1 = res[j];
                temp1.insert(temp1.begin(), nums[i]); // add the deleted in the front
                result.push_back(temp1); // push the final into result
            }
            
        }
        return result; // return results
        
    }
};  