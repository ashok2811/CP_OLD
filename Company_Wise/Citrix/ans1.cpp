class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {
        
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX/2));
        for(auto e : edges){ // Building Graphs
            adj[e[0]][e[1]] = adj[e[1]][e[0]] = e[2]; 
        }
        
        for(int i = 0 ; i< n ;i++){ // making self loop as 0
            adj[i][i] = 0;
        }
        
        for(int k = 0 ; k < n; k++){ // Floyd -Warshall
            for(int i = 0; i< n ; i++){
                for(int j =0 ; j< n ; j++){
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    adj[j][i] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        
        int count = INT_MAX;
        int ans = -1;
        for(int i = 0 ; i< n ;i++){
            int c = 0;
            for(int j =0 ; j< n ; j++){
                if(adj[i][j] <= dT) c++;
            }
            
            if(c<count || (c==count&&i>ans)){
                count = c;
                ans = i ;
            }
        }
        
        return ans;
    }
};
