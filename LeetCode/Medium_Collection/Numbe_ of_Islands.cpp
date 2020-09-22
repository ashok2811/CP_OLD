/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

*/


class Solution {
public:
    int H , W ;
    bool vis[301][301];
    int dx[4] = {-1 ,  0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};
    
    bool isValid(vector<vector<char>>& grid, int x , int y){
        
        if(x<0 || x>=H || y<0 || y>=W ) return false;
         if(grid[x][y]=='0') return false;
        if(vis[x][y]== 1 ) return false;
        
        return true;
    }
    
    void dfs(vector<vector<char>>& grid, int x , int y){
        vis[x][y] = 1 ;
        
        for(int i = 0 ; i< 4 ; i++){
            if(isValid(grid, x+dx[i] , y+dy[i]) == 1){
                dfs(grid,  x + dx[i] , y + dy[i]);
            }
        }
    }
       
    int numIslands(vector<vector<char>>& grid) {
        
        H = grid.size();
        if(H==0) return 0;
        W = grid[0].size();
     
        int count = 0;
        for(int i = 0 ; i< H ; i++){
            for(int j = 0 ; j< W; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    dfs(grid,  i, j);                    
                }
               
            }
        }
                
        return count ;
        
        
    }
};

