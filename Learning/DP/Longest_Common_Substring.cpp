#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int lcstr(string X , string Y, int n , int m, int count){
        
        if(n == 0 || m == 0) return count;
        if(dp[n][m]!= -1) return dp[n][m];
        if(X[n-1] == Y[m-1]){
            count = lcstr(X,Y,n-1,m-1, count+1);
        }
        count = max(count , lcstr(X,Y,n-1, m, 0));
        count = max(count , lcstr(X,Y,n, m -1, 0));
        //dp[n][m] = count;
        cout<< count << " - " << dp[n][m] << endl;
        return  count;
}


int main(){
    memset(dp, -1 , sizeof(dp));
    string X = "ashok";
    string Y = "shoaka";

    int n = X.length();
    int m = Y.length();

    cout << lcstr(X ,Y , n , m , 0); 

}