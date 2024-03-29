// Divisor Game
/*
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's 
turn, that player makes a move consisting of:

    Choosing any x with 0 < x < N and N % x == 0.
    Replacing the number N on the chalkboard with N - x.

Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both 
players play optimally.

Example 1:
Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.

*/

class Solution {
    
public:
    bool divisorGame(int N) {
        bool DP[1001];
        DP[1] = 0; DP[2] = 1 ;
        
        for(int j = 3 ;j<=N ; j++){                       
            DP[j] = !DP[j-1];
        }   
        
        return DP[N];
    }
};