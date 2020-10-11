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

vector<int> adj[1000000];
vector<int> results;
int indegree[1000000];

void toposort(int n){
    queue<int> q;
    for(int i = 1 ; i<=n; i++){
        if (indegree[i] == 0)
        {
           q.push(i);
        }
        
    }

    while (!q.empty())
    {
        int curr = q.front();
        results.push_back(curr);
        q.pop();

        for (auto node : adj[curr])
        {
            indegree[node]--;
            if(indegree[node]==0)
                q.push(node);
        }
        
    }

    cout << "Topological Sort: " ;
    for (int node : results)
    {
        cout << node << " ";
    }
    
}

int main() {

    fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int V , E , x, y ;
    cin >> V >> E ;
    for (int i = 0; i < E; i++)
    {   cin >> x >> y ;
        adj[x].push_back(y);
        indegree[y]++;
    }
    toposort(V);
    
    return 0;
}

