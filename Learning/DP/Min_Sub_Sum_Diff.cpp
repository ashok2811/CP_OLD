#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
bool min_subset_sum_diff(int arr[], int n){
      
       int sum = 0;
       for(int i = 0 ; i<n ; i++) { // Init and calculating sum
           sum += arr[i] ;
           dp[i][0] = 1 ;
           }
        dp[n][0] = 1;

       for(int i = 1 ; i<=sum ; i++) dp[0][i] = 0 ;

        for(int i = 0; i<=n; i++){
        for (int j = 0; j <=sum; j++)
        {

            if(arr[i-i] <= j) {  
                int a  = dp[i-1][j-arr[i-1]];
                int b = dp[i-1][j] ; 
                dp[i][j] = (a||b);
            }

            else if(arr[i-1]>j) dp[i][j] = dp[i-1][j];
        }
        
    }

    int mn = INT_MAX;
    for(int i = 0 ; i<=(sum/2) ; i++) {
        if(dp[n][i]==1){
            mn = min(mn, sum - 2*i);
        }        
    }

    return mn;

}



int main(){
    int arr[] = {1, 5, 11, 7 };
    int n = 4;
  
   // Filling with zero
    
    cout << min_subset_sum_diff(arr, n);
    return 0;
}