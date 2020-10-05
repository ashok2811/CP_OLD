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

using interval = vector<int>; // A particular Interval

bool cmp(const interval &left, const interval &right){ // Const bcz we dont want to modify the array
    if(left[0] == right[0]){
        return  left[1] > right[1] ;
    }    
    return left[0] < right[0] ; // asc order of first value
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end(), cmp);
        
        int ans = intervals.size();
        int maxEnd = 0 ;
        
        for(interval cur : intervals){
            // need to check if curr is already             
            int curEnd = cur[1];
            if(curEnd <= maxEnd){
                ans--;  // Reject away the current interval
            }
            
            maxEnd = max(maxEnd , curEnd);        
        }
        
        
        return ans;
    }
};