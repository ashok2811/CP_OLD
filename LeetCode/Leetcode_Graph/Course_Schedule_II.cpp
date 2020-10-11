/*
There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = 
[ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the 
prerequisite pairs, return the ordering of courses you should 
take to finish all courses.

If there are many valid answers, return any of them. If it is 
impossible to finish all courses, return an empty array.
Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take 
course 1 you should have finished course 0. So the correct 
course order is [0,1].
*/

class Solution {
public:
    vector<int> adj[2000];
    int vis[2000];
    int indeg[2000];
    vector<int> ans;
    
    void topo(int numC){
        queue<int> q;
        for(int i=0 ; i< numC ;i++){
            if(indeg[i]==0){                
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            
            for(auto child : adj[curr]){
                indeg[child]--;
                
                if(indeg[child]==0){
                    q.push(child);
                }
            }
        }
    }
    
    vector<int> findOrder(int numC, vector<vector<int>>& prereq) {
        for(auto x : prereq){
            adj[x[0]].push_back(x[1]);
            indeg[x[1]]++;
        }
        topo(numC);
        reverse(ans.begin(), ans.end());
        if(ans.size()==numC) return ans;
        else{
            return {};
        }
    }
};