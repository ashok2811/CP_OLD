/*
Remove Covered Intervals
Given a list of intervals, remove all intervals that are covered by another interval in the list.
Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.
After doing so, return the number of remaining intervals.
Example 1:
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        sort(inter.begin() , inter.end());
    
        int n = inter.size();
        for(int i = 1; i<n ;i++){
            if(inter[i][0]>inter[i-1][0]  && inter[i][1]<=inter[i-1][1] ){            
                inter.erase(inter.begin() + i) ; i--; n--;              
                
            }
            
            else if(inter[i][0]==inter[i-1][0]){
                if(inter[i][1]<=inter[i-1][1] ){
                    inter.erase(inter.begin() + i) ; n--;
                }
                
                else{
                    inter.erase(inter.begin() + i-1) ; 
                    i--; n--;
                }               
                
            }
        }

        return inter.size();
    }
};
