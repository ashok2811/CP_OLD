/*
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

*/


/// Long but intutive 

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(); 
        
        if(n<=1) return s ;
        int max_len = 1;
        int start = 0 , end = 0 ;
        
        // Odd
        
        for(int i = 0 ; i< n ; ++i){
            int L = i ; int R = i ;
            while(L>=0 && R <n){
                
                if(s[L] == s[R]) {
                    L-- ; R++;
                }                
                else break;
            }
            
            int len = R-L-1;
            if(len>max_len){
                max_len = len;
                start = L+1;
                end = R-1;
            }
            
        }
        
        
        // Even
        
        
        for(int i = 0 ; i< n ; ++i){
            int L = i ; int R = i+1 ;
            while(L>=0 && R <n){
                
                if(s[L] == s[R]) {
                    L-- ; R++;
                }                
                else break;
            }
            
            int len = R-L-1;
            if(len>max_len){
                max_len = len;
                start = L+1;
                end = R-1;
            }
            
        }
           
        return s.substr(start, max_len);
        
        
        
        
    }
};