/*
You are given coins of different denominations and a total 
amount of money amount. Write a function to compute the 
fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of
the coins, return -1.

You may assume that you have an infinite number of each kind of 
coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

*/

class Solution {
public:
    int dp[13][10001];
    const int INF = 1e9;
    int min_coin(vector<int>& coins, int n, int sum){
        if(n == 0) return INF;
        if(sum == 0) return 0;

        if(dp[n][sum] != -1) return dp[n][sum] ; 
        
        if(coins[n-1] <= sum){

            return dp[n][sum] = min(1 + min_coin(coins, n, sum - coins[n-1]), 
                                    min_coin(coins, n-1, sum));
        }
        
        else{
            return dp[n][sum] = min_coin(coins, n-1, sum);
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
       
        for(int i = 0; i <=n ; i++){
            for(int j =0; j<= amount ;j++)
                dp[i][j] = -1;
        }
        
         int ans = min_coin(coins, n , amount);
        
        
        if(ans == INF){
            return -1;
        }
        
        else{
            return ans ;
        }
        
    }
};