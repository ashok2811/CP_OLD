// Matrix chain multiplication
// Given an array, arr[] = {10, 20, 30, 20, 40}, find the max of matrix

#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int mcm(int arr[] , int i , int j){
    if(i>=j) return 0;
    if(dp[i][j]!= -1) return dp[i][j];

    int mn = INT_MAX;
    for(int k = i; k<j ; k++){
        int temp = 0;
        temp =  mcm(arr, i,k) + mcm(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        if(temp<mn){mn = temp;}        
    }
    dp[i][j] = mn;
    return mn;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int arr[] = {10, 20, 30, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<< mcm(arr, 1, size-1);
}
