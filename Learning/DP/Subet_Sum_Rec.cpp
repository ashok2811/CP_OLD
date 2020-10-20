#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
bool SubsetSum(int arr[], int n, int sum){
        // base
        if(sum==0) return 1;
        if(n==0) return 0;

        // Memoization
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }

        if(arr[n-1]<=sum){
            // Two Choices: 1 Take it , 2 Leave it
            
            bool a = SubsetSum(arr, n -1 , sum - arr[n-1]); // Taken
            bool b = SubsetSum(arr,n-1,sum); // Left
            dp[n][sum] = (a|b);
            return dp[n][sum];
        }

        else if(arr[n-1]>sum){
            dp[n][sum] =  SubsetSum(arr,n-1,sum); // No choice, can't take
            return dp[n][sum];
        }
}



int main(){
    int arr[] = {1, 5, 11, 5 };
    int sum = 13;
    int n = 4;
  
   // Filling with zero
    for(int i = 0; i<=n; i++){
        for (int j = 0; j <=sum; j++)
        {
            dp[i][j] = -1;
        }
        
    }
    cout << SubsetSum(arr, n, sum);
    return 0;
}