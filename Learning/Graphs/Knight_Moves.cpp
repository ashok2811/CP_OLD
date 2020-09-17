// You are given a maze of size NxM, there is a knight on 
// point (x, y) and a target cell (a, b), find min steps 
// to reach the target

/*____________________________Definitions__________________________*/
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
bool vis[9][9];
int  dist[9][9];

bool isValid(int x , int y){
    if(x<1||x>N||y<1||y>M) return false ;
    if(vis[x][y]==true) return false;
    return true;
}

int dx[8] = {-2 , -1 , 1 , 2, 2, 1, -1, -2};
int dy[8] = {1 , 2 , 2 , 1, -1, -2, -2, -1};
void bfsg(int x , int y){

    queue<pair<int, int >> q ;
    q.push({x, y});
    vis[x][y] =1;
    dist[x][y] = 0;
    while (!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();


    for (int i = 0; i < 8; i++)
       if(isValid(cx + dx[i] , cy + dy[i])){
           int newX = cx + dx[i];
           int newY = cy + dy[i];
           q.push({newX, newY});
           vis[newX][newY] =1;
           dist[newX][newY] = dist[cx][cy] + 1;

       }

    }

    //   for (int i = 1; i <=N; i++)
    //    {
    //        for (int j = 1; j <=M; j++)
    //        {
    //            cout << dist[i][j]<< " ";
    //        }
    //        cout << nl;
    //    }   
      
        
}


int main() {

    fastIO
#ifndef ONLINE_JUDGE
 (void)freopen("input.txt", "r", stdin);
 (void)freopen("output.txt", "w", stdout);
#endif
    int T ; cin >> T;
    N = M = 8;
    while (T--)
    {    

    for (int i = 1; i <=8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            vis[i][j] = 0;
            dist[i][j] = 0;
        }
        
    }
    
       

    string st , ed;
    cin>> st >> ed;

    bfsg(st[0]-'a' + 1 , st[1] - '0');
    cout<<dist[ed[0]-'a'+1][ed[1]-'0']<<nl;
   
       
    }
    
    return 0;
}

