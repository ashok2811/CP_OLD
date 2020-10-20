class Solution {
public:
    int dp[1001][1001];
    
    int lcs(string &X, string &Y, int n , int m){
        
        if(n==0 || m == 0) return 0;
        
        if(dp[n][m] != -1){ // memoization
            return dp[n][m];
        }
        
        if(X[n-1] == Y[m-1]){ // Last character is equal
            return dp[n][m] = 1 + lcs(X, Y , n-1, m-1);
        }
        
        else{ // Last character is not equal 
            int a = lcs(X ,Y, n-1, m);
            int b = lcs(X ,Y, n, m-1);
            return dp[n][m] = max(a, b) ;
        }
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        for(int i = 0; i<=text1.length(); i++)
            for(int j = 0; j<=text2.length(); j++)
                dp[i][j] = -1;
        return lcs(text1, text2, text1.length(), text2.length());
    }
};