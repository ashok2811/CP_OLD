/*
You are given coins of different denominations and a total amount of money. 
Write a function to compute the number of combinations that make up that amount. 
You may assume that you have infinite number of each kind of coin.
Example 1:
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

class Solution {
public:
    
    int dp[500][5001];
    int min_coin(vector<int>& coins, int n, int sum){
        
        if(sum == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][sum] != -1) return dp[n][sum] ; 
        
        if(coins[n-1] <= sum){

            return dp[n][sum] = min_coin(coins, n, sum - coins[n-1]) +  
                                    min_coin(coins, n-1, sum);
        }
        
        else{
            return dp[n][sum] = min_coin(coins, n-1, sum);
        }
    }
    
    
    
    int change(int amount, vector<int>& coins) {
        
         int n = coins.size();
        
       
        for(int i = 0; i <=n ; i++){
            for(int j =0; j<= amount ;j++)
                dp[i][j] = -1;
        }
        
         int ans = min_coin(coins, n , amount);
        
     
        return ans ;
    }
};


