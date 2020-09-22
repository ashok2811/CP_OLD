/*
A robot is located at the top-left corner of a m x n grid.

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid.

How many possible unique paths are there?
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int  i = 0 ; i < n-1 ; i++){
            dp[m-1][i] = 1 ;
        }
        
        for(int  i = 0 ; i < m-1 ; i++){
            dp[i][n-1] = 1 ;
        }
        
        for(int  i = m-2 ; i>=0 ; i--){
            for(int j = n-2 ; j>=0 ; j--){
                dp[i][j] = dp[i][j+1] + dp[i+1][j] ;              
            }            
        }
        
        return dp[0][0];
        
    }
};