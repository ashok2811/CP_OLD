#include <bits/stdc++.h>
using namespace std;

string ans = "";
int dp[100][100];
int lcs(string x , string y , int n , int m){
    if(n==0 || m==0) return 0 ;
    if(dp[n][m]!=-1) return dp[n][m];
    if(x[n-1]==y[m-1]){
        ans.push_back(x[n-1]);
        dp[n][m] = 1+lcs(x ,y , n-1 ,m-1);
        return dp[n][m];
    }
    else{
        dp[n][m] = max(lcs(x,y,n-1,m) , lcs(x, y , n , m-1));
        return dp[n][m];
    }
}

int main(){
    memset(dp , -1, sizeof(dp));
    string x = "Asfhrdok";
    string y = "sho";
   
    int sx =  lcs(x, y, x.length(), y.length());
    for(auto x : ans) {
        cout << x ;
    }
    cout <<" Size: " << sx;
}