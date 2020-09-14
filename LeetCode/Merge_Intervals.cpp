/*
Given a collection of intervals, merge all overlapping intervals.
Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
       
        int len = interval.size() ;
         vector<vector<int>> ans ;
         if(len==0){
        return ans;
    }
   
         sort(interval.begin(), interval.end());
           vector<int> temp = interval[0];
        
    for(int i = 0 ; i<len; i++){
        
        if(temp[1] >=interval[i][0]){
            temp[1] = max(interval[i][1], temp[1]);
            
        }
        else{
            
            ans.push_back(temp);
           temp[0] = interval[i][0];
            temp[1]= interval[i][1];
           
            }
      }
        
        ans.push_back(temp);
        
        return ans;
    }
        
    
};