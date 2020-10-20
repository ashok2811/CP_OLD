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

vector<int> adj[1000001];
int level[1000001], vis[1000001], dist[1000001];

void bfs(int node) {
	queue<int> q;
	q.push(node);
	vis[node] = 1;
	dist[node] = 0;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		trav(child, adj[curr]) {
			if (!vis[child]) {
				dist[child] = dist[curr] + 1;
				q.push(child);
				vis[child] = 1 ;
				level[dist[child]]++;
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

	int v, e , a , b , node , d ;

	cin >> v >> e ;
	for (int i = 0; i < e; ++i)
	{
		cin >> a >> b;
		adj[a].pb(b); adj[b].pb(a);
	}
	int q;
	cin >> q ;
	for (int i = 0; i < q; ++i)
	{
		cin >> node >> d ;
		for (int i = 0; i < v; ++i)
		{
			level[i] = 0 , vis[i] = 0;
		}
		bfs(node);
		cout << level[d] << nl;
	}
	return 0;
}

