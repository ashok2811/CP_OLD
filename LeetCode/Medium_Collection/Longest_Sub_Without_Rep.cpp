/*
Longest Substring Without Repeating Characters
Medium

Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

*/


// Brute Force O(n^3)  ---- >>> Greet you TLE

class Solution {
public:
    bool allUnique(string str , int start , int end){
        set<char> s ;
        for(int i = start; i<end ; i++){
            char ch = str[i] ;
            if(s.find(ch) == s.end()) {
                s.insert(ch);
            }
            else {
                return 0;
            }
        }
        return 1 ; 
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n ==1 ) return 1;
        int ans = 0 ;
        for(int i = 0 ; i<n ; i++){
            for(int j = i+1 ; j<=n ;j++){
                if(allUnique(s , i , j )) ans = max(ans , j-i);
            }
        }
        
        return ans;
    }
};



<----------------------------------------------->

// With unoredered set  < Accepted > 

class Solution {
public:
 
    int lengthOfLongestSubstring(string str) {
        int n = str.length();
        unordered_set<char> s;
        if(n ==1 ) return 1;
        int ans = 0 , i = 0 , j = 0;
        while(i<n && j<n){
            if(s.find(str[j]) == s.end()){
                s.insert(str[j++]);
                ans = max(ans , j-i) ;
               
            }
            
            else{
                s.erase(str[i++]);
              
            }
        }
        return ans;
    }
};

