/*
 All Paths From Source to Target
Medium
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, 
find all possible paths from node 0 to node n - 1, and return them in any order.
The graph is given as follows: graph[i] is a list of all nodes you can visit 
from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Example 1:
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/

class Solution {
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>> &result, vector<int> &path, int u){
        
        path.push_back(u);
        if(u == graph.size()-1) result.push_back(path);
        else{
            for(int v : graph[u]){
                dfs(graph, result, path, v);
            }
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(graph, result, path, 0);
        
        return result;
    }
};