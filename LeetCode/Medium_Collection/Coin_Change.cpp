/*
You are given coins of different denominations and a total amount
 of money amount. Write a function to compute the fewest number of 
 coins that you need to make up that amount. If that amount of money 
 cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0; 
        for(int i = 1 ; i<=amount ; i++){   // Init the dp array with INF
            dp[i] = 1e9;
        }
        
        for(int i = 1 ; i<=amount ; i++){  // Go for all amount
            for(auto x : coins){  // iterate over all coins
                if((i - x)>= 0){ // Check if is is not out of bound
                    dp[i] = min(dp[i], dp[i-x]+1); 
                }
            }
        }
        
        if(dp[amount] == 1e9){  // if still INF, return -1 i.e not possible
            return -1;
        }
        
        return dp[amount];
        
    }
};