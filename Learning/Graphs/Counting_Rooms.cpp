/*
You are given a map of a building, and your 
task is to count the number of its rooms. The 
size of the map is n×m squares, and each square
 is either floor or wall. You can walk left, 
right, up, and down through the floor squares.


Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3


*/

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

int N , M;
char grid[1001][1001];
bool vis[1001][1001];

int dx[4] = { -1 , 0 , 1 , 0};
int dy[4] = {0 , 1 , 0 , -1};

bool isValid(int x , int y){
    if(x<0 || x>=N || y<0 || y>=M) return false ;
    if(vis[x][y]==1 || grid[x][y] == '#') return false;
    return true;
}

void dfs(int x , int y){
    vis[x][y] = 1;

    for (int i = 0; i < 4; i++)
        if(isValid(x + dx[i] , y+dy[i]))
           dfs( x + dx[i], y + dy[i]);
    }

int main() {

    fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N >> M ;
    for (int i = 0; i < N; i++)
     for (int j = 0; j < M; j++)
         cin >> grid[i][j];
        
    int count = 0;
    
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if( grid[i][j]=='.' && vis[i][j]==0) {
            dfs(i , j );
             count++;
            }
       

    cout << count << nl;

    return 0;
}

