/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    void generate_brackets(string s , int open , int close, int n , vector<string> &ans){
        
        if(s.length() == 2*n){
            ans. push_back(s);
            return;
        }
        
        if(open<n) generate_brackets(s+"(" , open + 1 , close , n , ans);
        if(close<open) generate_brackets(s+")" , open , close + 1 , n , ans);
    }
    
    vector<string> generateParenthesis(int n) {        
        vector<string> ans; 
        generate_brackets("(" , 1 , 0 , n , ans);        
        return ans;        
    }
};