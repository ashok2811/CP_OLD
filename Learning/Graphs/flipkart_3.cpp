/*____________________________Definitions__________________________*/
#include <bits/stdc++.h>
using namespace std;
#define INF 100000 ;
int grid[501][501];

int main() {

int N, K ; cin>> N>> K;
vector<int> arr(K);
for(int i =0; i<K; i++){ 
    cin>>arr[i];
}
//Initialisation
for(int i = 0; i<=N ; i++)
    for(int j =0 ;j <=N ; j++)
        grid[i][j] = INF ;

int V ; cin >> V ;
for (int i = 0; i < V; i++)
{   int u , v , cost ;
   cin >> u >> v >> cost;
    grid[u][v] = cost;
    grid[v][u] = cost;
}
//Flyod Warshall 
for(int k = 0 ; k <N ;k++)
    for(int i = 0 ; i<N ; i++)
        for (int j = 0; j <N; j++){
            grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
            grid[j][i] = min(grid[j][i], grid[i][k] + grid[k][j]);
        }  

int mn = INF;        
for (int i = 0; i <K; i++)
    for(int j = i+1 ; j< K; j++)
        mn = min(mn, grid[arr[i]][arr[j]]);     

cout << mn;
    return 0;
}

