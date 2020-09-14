/*____________________________Definitions__________________________*/
#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef vector<int> vi;
#define fo(i, a, b) for (int i=a; i<(b); i++)
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


vi adj[10001];
int vis[10001], in[10001], low[10001];
set<int> AP;
int timer;
void dfs(int node, int par){
    vis[node] = 1;

    in[node] = low[node] = timer++ ;
    int child_cnt = 0;

    for(int child : adj[node]){
        if(child == par){
            continue;
        }    

        else if(vis[child]==1){
             
            low[node] = min(low[node], in[child]);

        }

        else {
        dfs(child, node);
        child_cnt++;
        low[node] = min(low[node] , low[child]);

        if(in[node]<=low[child] && par!= -1) AP.insert(node);

    }
    } 

    if(par == -1 && child_cnt > 1){
        AP.insert(node);
    }
}
int main() {

    fastIO
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif

    while (1) {
      int V , E ; cin >> V >>E ;
      if(V==0 && E==0) break;

      fo(i,1,V+1){
          adj[i].clear(); vis[i]=0 ,in[i] = 0, low[i] = 0;
      }
        AP.clear();
        timer = 1;
        fo(i , 0 , E){
            int a ,b ; cin >>a>>b;
            adj[a].pb(b); adj[b].pb(a);
        } 

        fo(i , 1 , V+1){
            if(vis[i]==0){
                dfs(i , -1);
            }
        }

        cout << AP.size()<<nl;


    }
    return 0; 
}

