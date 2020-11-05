#include <bits/stdc++.h>
using namespace std;

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

int main(){
    memset(dp , -1, sizeof(dp));
    string y = "ashvkdxcb";
    string x = "sasshddsfas";
   
    lcs(x, y, (int)x.length(), (int)y.length());
    short_super(x, y, (int)x.length(), (int)y.length());
    reverse(ans.begin(), ans.end());  
    cout << ans << endl ;
    return 0;
}