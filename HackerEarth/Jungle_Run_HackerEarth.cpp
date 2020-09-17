// DFS or BFS in 2D grid
#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef vector<int> vi;
#define Rep(i, a, b) for (int i=a; i<(b); i++)
#define trav(a,x) for(auto& a : x)
#define nl '\n'
#define ri(n) int n; scanf("%d", &n);
#define rll(n) ll n; scanf("%lld", &n);
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

int N , M ;
const int gridSize = 31;
bool vis[gridSize][gridSize];
char grid[gridSize][gridSize];
int dist[gridSize][gridSize];

bool isValid(int x , int y){
    if(x<1||x>N||y<1||y>M) return false ;
    if(grid[x][y]=='T' || vis[x][y]==true) return false;
    return true;
}

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};
void bfsg(int x , int y){
    queue<pair<int, int >> q;
    q.push({x , y});
    dist[x][y] = 0 ;
    vis[x][y] =1; 

    while (!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if(isValid(currX + dx[i], currY + dy[i])){
                
                int newX = currX + dx[i] ;
                int newY = currY + dy[i] ; 
                q.push({newX , newY});
                vis[newX][newY] = 1;
                dist[newX][newY]= 1 + dist[currX][currY];
            }
        }
        


    }
    
}


int main() {

    fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    cin>>N;
    M = N;
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 1; i <= N; i++)
    { for (int j = 1; j <= M; j++)
        {   cin >> grid[i][j] ;
            if(grid[i][j]=='S'){
                start = {i, j} ;
            }

            if(grid[i][j]=='E'){
                end = {i, j} ;
            }
        }
    }

    bfsg(start.first , start.second);
    cout << dist[end.first][end.second];
    return 0;
}

