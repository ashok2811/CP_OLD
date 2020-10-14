// Regions Cut By Slashes

/*
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, 
or blank space.  These characters divide the square into contiguous regions.
(Note that backslash characters are escaped, so a \ is represented as "\\".)
Return the number of regions.

Example 1:
Input:
[
  " /",
  "/ "
]
Output: 2
*/

class Solution {
    
public:
    int N;
    int arr[90][90];
    bool vis[90][90];
    
    int dx[4] = { -1 , 0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};
    
   bool isValid(int x , int y){
    if(x<0 || x>=N || y<0 || y>=N) return false ;
    if(vis[x][y]==1 || arr[x][y] == 1) return false;
    return true;
    }

    void dfs(int x , int y){
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
            if(isValid(x + dx[i] , y+dy[i]))
               dfs( x + dx[i], y + dy[i]);
        }


    int regionsBySlashes(vector<string>& grid) {
        N = 3*grid.size();
        for(int i = 0 ; i<grid.size(); i++)
            for(int j = 0 ; j< grid.size(); j++){
                if(grid[i][j]=='/')
                    arr[3*i+ 2][3*j]=arr[3*i+ 1][3*j +1]=arr[3*i][3*j +2]=1;
                else if(grid[i][j]=='\\')
                    arr[3*i][3*j]=arr[3*i+ 1][3*j +1]=arr[3*i+2][3*j +2] =1;                            }
      
        int count = 0;
        for(int i = 0 ; i<N ; i++)
            for(int j = 0 ; j < N; j++)
                if(!vis[i][j] && arr[i][j]==0){
                    dfs(i, j);
                    count++;                  
                    }                
            
       return count; 
    }
};