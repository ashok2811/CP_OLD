/*
Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter 
combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int size = digits.size() ;
        if(size == 0) return {}; // Corner Case
        
        unordered_map<char, string> n2val; // bulding a key mapping
        n2val['2'] = "abc"; n2val['3'] = "def"; 
        n2val['4'] = "ghi"; n2val['5'] = "jkl"; n2val['6'] = "mno";
        n2val['7'] = "pqrs"; n2val['8'] = "tuv"; n2val['9'] = "wxyz";
        
        deque<string> combs; // to store element
        combs.push_back("");
        
        for(int i = 0 ; i< size ; i++){ // iterate in all digits
            
            int deque_size = combs.size();
            
            for(int k = 0 ; k< deque_size ; k++){ //iterated on the current digit
                
                int d_size = n2val[(char)digits[i]].size();
                
                string f = combs.front();
                combs.pop_front();
                
            for(int j = 0 ; j < d_size ; j++){ // Generate all the pairs 
                combs.push_back(f + n2val[(char)digits[i]][j]);
                }               
                
            }
            
        }
        
        vector<string> ans; // return in asked format
        int sz =combs.size();
        for(int i = 0 ; i < sz ; i++){
            ans.push_back(combs.front());
            combs.pop_front();
        }
        
        return ans;
    }
};