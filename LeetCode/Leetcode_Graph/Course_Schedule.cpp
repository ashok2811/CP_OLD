/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take 
course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for 
you to finish all courses?

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

*/
class Solution {
public:
    vector<int>  adj[100000] ;
    bool vis[100000];
    bool c_vis[100000];
    
    bool dfs(int node){
        
        if(!vis[node]){
            
        vis[node] = 1 ;
        c_vis[node] = 1;
        
        for(auto child : adj[node]){
            
            if(!vis[child] && dfs(child)) return true;             
            
            if(c_vis[child]) return true;
            }
            
        }
        c_vis[node] = 0;
        return false;        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        
        for(auto x : prereq){
            adj[x[0]].push_back(x[1]);
        }
        
        for(int i= 0 ; i< numCourses; i++){
            
            if(vis[i]==0 && dfs(i)) return false;
        }
        
       return true;
    }
};