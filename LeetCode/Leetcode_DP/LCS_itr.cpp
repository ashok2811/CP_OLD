/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some 
characters(can be none) deleted without changing the relative order of the remaining 
characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). 
A common subsequence of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

*/

class Solution {
public:
    int dp[1001][1001];
    
    int lcs(string &X, string &Y, int n , int m){
        
        for(int i = 0; i<=n; i++) dp[i][0] = 0;
        for(int j = 0; j<=m; j++) dp[0][j] = 0;
               
          
        for(int i = 1; i<=n; i++) 
            for(int j = 1; j<=m; j++){
                if(X[i-1] == Y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        
        return dp[n][m];
        
    }
    int longestCommonSubsequence(string text1, string text2) {

        return lcs(text1, text2, text1.length(), text2.length());
    }
};