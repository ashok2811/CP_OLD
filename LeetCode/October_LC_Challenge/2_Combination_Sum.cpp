/*
Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all 
unique combinations of candidates where the chosen numbers sum to target. You may return the 
combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations 
are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 
150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
*/

using choice = vector<int>;
vector<int> arr = {};

// returning all possible choics to make target sum by using suffix of array [currInx]

vector<choice> getAllChoices(int curIndex, int target){
     // base cases
    if(target < 0) return {}; // no valid choice
    if(target == 0) return {{}}; // one choice ie choose nothing
    if(curIndex == arr.size()) return {}; // no valid choice
    
    
    int curNumber = arr[curIndex];
    
    vector<choice> ans =  getAllChoices(curIndex+1, target); // Curr Number is no used at all
    vector<choice> other = getAllChoices(curIndex, target - curNumber); // using it once
    
    for(choice c : other){
        c.push_back(curNumber);
        // Now c is a valid choice 
        ans.push_back(c);
    }
    
    return ans;
}

class Solution {
public:
    vector<choice> combinationSum(vector<int>& candidates, int target) {
        arr = candidates;
        return getAllChoices(0 , target);
    }
};