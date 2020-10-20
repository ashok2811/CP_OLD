#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int SubsetSum(int arr[], int n, int sum){
        // base
        if(sum==0) return 1;
        if(n==0) return 0;

        // Memoization
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }

        if(arr[n-1]<=sum){
            // Two Choices: 1 Take it , 2 Leave it
            
            int a = SubsetSum(arr, n -1 , sum - arr[n-1]); // Taken
            int b = SubsetSum(arr,n-1,sum); // Left
            dp[n][sum] = a + b;
            return dp[n][sum];
        }

        else if(arr[n-1]>sum){
            dp[n][sum] =  SubsetSum(arr,n-1,sum); // No choice, can't take
            return dp[n][sum];
        }
}



int main(){
    int arr[] = {2, 3 , 5 ,6 , 8 ,10 };
    int sum = 10;
    int n = 6;
  
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