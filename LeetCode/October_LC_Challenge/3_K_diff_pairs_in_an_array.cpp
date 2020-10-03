/*
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

    0 <= i, j < nums.length
    i != j
    a <= b
    b - a == k

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

*/

class Solution {
public:
    int findPairs(vector<int >& nums, int k) {
        
        unordered_map<int,int> m ;
        for(int i = 0; i< nums.size() ; i++){
            m[nums[i]]++;
        }
        int count = 0;
        for(auto x : m){
            if(k==0){
                if(x.second>1) count++;
            }
            else{
                if(m.find(x.first + k) != m.end()){
                    if(m[x.first +k]>0) count++;
                }
            }
        }
        
        return count;
        
    }
};