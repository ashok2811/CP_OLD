/*
You are given weights and values of N items, put these items in a knapsack of 
capacity W to get the maximum total value in the knapsack. Note that we have 
only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which 
represent values and weights associated with N items respectively. Also given 
an integer W which represents knapsack capacity, find out the maximum value 
subset of val[] such that sum of the weights of this subset is smaller than 
or equal to W. You cannot break an item, either pick the complete item, or 
don’t pick it (0-1 property).

Input:
The first line of input contains an integer T denoting the number of test cases. 
Then T test cases follow. Each test case consists of four lines.
The first line consists of N the number of items.
The second line consists of W, the maximum capacity of the knapsack.
In the next line are N space separated positive integers denoting the values 
of the N items,
and in the fourth line are N space separated positive integers denoting the 
weights of the corresponding items.

Output:
For each testcase, in a new line, print the maximum possible value you can 
get with the given conditions that you can obtain for each test case in a new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000

Example:
Input:
2
3
4
1 2 3
4 5 1
3
3
1 2 3
4 5 6
Output:
3
0
Explanation:
Test Case 1: With W = 4, you can either choose the 0th item or the 2nd item. 
Thus, the maximum value you can generate is the max of val[0] and val[2], 
which is equal to 3.
Test Case 2: With W = 3, there is no item you can choose from the given 
list as all the items have weight greater than W. Thus, the maximum 
value you can generate is 0.

*/


// Code : Memoization Version

#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001] = {-1};

int knapsack(int val[], int wt[], int W, int N){
    // base condition:  either weight allowed = 0 or number of item = 0;
    if(W==0 || N==0) return 0;
    if(dp[N][W]!= -1) return dp[N][W]; // Using Memoization

    // Choices 1: choosen wt is > threshold weight, will not take
    if(wt[N-1] > W)  return dp[N][W] = knapsack(val, wt, W, N-1);
    // Choice 2: choosen wt is <= threshold weight, will take
    else if(wt[N-1] <= W){
        return dp[N][W] = max( val[N-1] + knapsack(val, wt, W-wt[N-1], N-1) ,  knapsack(val, wt, W, N-1)) ;  // maximisation step
        // Also storing the return value for further use
    }
    
}

int main() {
	//code
	int t ; cin >> t ;
	while(t--){
	       int N, W;
	       cin >> N >> W ;
	       int wt[N] , val[N] ;
	       for(int i = 0 ; i< N ; i++){
	           cin >>val[i];
	       }
	       
	       for(int i = 0 ; i< N ; i++){
	           cin >> wt[i];
	       }
	         
	         for(int i = 0 ; i<=N ;i++){ // Fill with -1
	           for(int j = 0 ; j<=W; j++){
	               dp[i][j]  =-1;
	           }	           
	       }

	     cout << knapsack(val, wt, W, N) << endl;
	   
	}
	
	return 0;
}


// Iterative Version


#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001] ;

int main() {
	//code
	int t ; cin >> t ;
	while(t--){
	       int N, W;
	       cin >> N >> W ;
	       int wt[N] , val[N] ;
	       for(int i = 0 ; i< N ; i++){
	           cin >>val[i];
	       }
	       
	       for(int i = 0 ; i< N ; i++){
	           cin >> wt[i];
	       }
	       // Intialisation Step 
	       for(int i = 0 ; i<=N ;i++){
	          dp[i][0] = 0 ;
	       }
	         for(int i = 0 ; i<=W ;i++){
	          dp[0][i] = 0 ;
	       }
	       
	    for(int i = 1 ; i <=N; i++){
	        for(int j = 1 ; j<=W; j++){
	            // Choice 1:  current weight <= max allowed weight
	            
	            if(wt[i-1]<=j){
	                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]); // max of taking this val or not
	            }
	            
	            
	            
	            // Choice 2 : current weight is greater than max alloed weight , not considering the current
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	       

	     cout << dp[N][W] << endl;
	   
	}
	
	return 0;
}