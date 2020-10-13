/*
Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into 
two independent subsets A and B such that every edge in the graph has 
one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes 
j for which the edge between nodes i and j exists.  Each node is an 
integer between 0 and graph.length - 1.  There are no self edges or 
parallel edges: graph[i] does not contain i, and it doesn't contain 
any element twice.
Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
*/

class Solution {
  
    
public:
    int visited[101];
    int colour[101];
    
    bool bipartDFS(vector<vector<int>>& graph, int node, int c){
        visited[node] = 1;
        colour[node] = c ;
        for(auto child : graph[node]){
            if(!visited[child]){ // if child is not visited
                // check if there is some adj node having same colour
                if(bipartDFS(graph , child, c^1)==false) return false;
            }
            
            else{
                if(colour[child]==colour[node]) return false;
            }
        }        
        return true; // We are ok, graph is bipartite
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {  
        
        int sz = graph.size();
        for(int i = 0; i<sz ; i++){
            if(!visited[i] && (bipartDFS(graph, i, 1)==false)) return false;
        }
        
        return true;
    }
};