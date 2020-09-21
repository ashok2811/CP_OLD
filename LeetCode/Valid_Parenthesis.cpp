/*

Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true


*/

class Solution {
public:
    bool isValid(string str) {
        
        stack<char> s ;
        int n = str.length();
        for(int i = 0 ; i< n ; i++){
            char ch = str[i];
            if(s.empty()){
                s.push(ch);
            }
            else{
                if(ch=='(' || ch =='{' || ch == '['){
                    s.push(ch);
                }
                
                else{
                    if((ch==')' && s.top() == '(' ) ||(ch=='}' && 
                    s.top() == '{' ) || (ch==']' && s.top() == '[' )){
                        s.pop();
                    }
                    else{
                        s.push(ch);
                    }
                }
            }
            
        }
        
        return s.empty();
        
        
    }
};