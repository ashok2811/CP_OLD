/*
1092. Shortest Common Supersequence
Hard

Given two strings str1 and str2, return the shortest 
string that has both str1 and str2 as subsequences.  
If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting 
some number of characters from T (possibly 0, and the 
characters are chosen anywhere from T) results in the 
string S.)

Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
*/

class Solution {
public:
    
string ans = "";
int dp[1001][1001];
void lcs(string x , string y , int n , int m){
    for(int i = 0 ; i <=n ; i++) dp[i][0]=0;
    for(int i = 0 ; i <=m ; i++) dp[0][i]=0;
    for(int i = 1; i<=n ;i++)
        for (int j = 1; j <= m; j++)
        {
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1] + 1;
            }
            else{

                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
}

void short_super(string x ,string y, int n , int m){
    int i = n , j = m;

    while(i>0 && j>0){

        if(x[i-1]==y[j-1]){
                ans.push_back(x[i-1]);
                i--; j--;
            }
        else{

            if(dp[i][j-1] > dp[i-1][j]){
                ans.push_back(y[j-1]);
                j--;
            }
            else{
                ans.push_back(x[i-1]);
                i--;
            }
        }
    }
    while(i>0){
        ans.push_back(x[i-1]);
        i--;
    }
    while(j>0){
        ans.push_back(y[j-1]);
        j--;
    }
}

    
    string shortestCommonSupersequence(string str1, string str2) {
    memset(dp , -1, sizeof(dp));
    string x = str1;
    string y = str2;
    lcs(x, y, (int)x.length(), (int)y.length());
    short_super(x, y, (int)x.length(), (int)y.length());
    reverse(ans.begin(), ans.end());
    return ans;
    }
};