// Given a string, your task is to count how many palindromic substrings in this 
// string.
// The substrings with different start indexes or end indexes are counted as 
// different substrings even they consist of same characters.
// Example 1:
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".


class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0 ;
        // making a DP Array and fill all with 0s
        vector<vector<int>> dp(n, vector<int> (n, 0)) ;
        
        // Fill the first row with 1s as we will always have 1 length pallindrome
        for(int i= 0; i< n ; i++)
            dp[0][i] = 1;
        // Fill second row with all 2 length pallindrom
        for(int i = 0; i< n-1 ; i++)
            if(s[i]==s[i+1]) {
                dp[1][i] = 1 ;
                count++;
            } 
        // Checking for valid pallindrom od size i+1 starting from j
        for(int i = 2; i < n; i++){
            for(int j = 0; j< n-i ; j++)                
                if(s[j]==s[j+i]){
                    if(dp[i-2][j+1]==1){
                        dp[i][j] =1;
                        count++;
                    }
                }             
        }        
        
        return count + n; // Adding n bcz of 1 length pallindrom
    }
};