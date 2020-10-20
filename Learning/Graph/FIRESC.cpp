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

/*__________________________________________________________________*/

int dfs(vector<int> adj[] , vector<int>& vis , int node, int & count) {

	vis[node] = 1;
	count++;
	for (auto child : adj[node]) {
		if (!vis[child]) {

			dfs(adj , vis, child, count);
		}
	}
	return count;
}

int main() {

	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; cin >> T;
	while (T--) {
		/*_____________________Code Here____________________________*/

		int V , E;
		cin >> V >> E ;

		vector<int> adj[V + 1];
		vector<int> vis(V + 1, 0);
		while (E--) {
			int a , b; cin >> a >> b;
			adj[a].pb(b); adj[b].pb(a); //adding an edge
		}

		int c = 0 ;
		ll lead = 1 ;


		for (int i = 1; i <= V; ++i)
		{
			if (!vis[i]) {
				int count = 0 ;
				dfs(adj , vis , i, count);
				lead = (lead * (ll)(count)) % (ll)(1e9 + 7);
				c++;
			}

		}

		cout << c << " " << lead << nl;



		/*_____________________End Here____________________________*/
	}
	return 0;
}

