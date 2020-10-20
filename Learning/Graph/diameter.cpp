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
int maxD , maxNode;

void dfs(vector<int> adj[] , vector<int>& vis , int node , int d) {

	vis[node] = 1;

	if (d > maxD) {
		maxD = d , maxNode = node ;
	}

	for (auto child : adj[node]) {
		if (!vis[child]) {

			dfs(adj , vis, child, d + 1);
		}
	}

}

int main() {

	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T = 1;
	while (T--) {
		/*_____________________Code Here____________________________*/

		int V , E;
		cin >> V;
		E = V - 1;
		vector<int> adj[V + 1];
		vector<int> vis(V + 1, 0);
		while (E--) {
			int a , b; cin >> a >> b;
			adj[a].pb(b); adj[b].pb(a); //adding an edge
		}


		maxD = -1;
		dfs(adj , vis , 1 , 0);

		for (int  i = 0 ; i < V + 1; i++) vis[i] = 0 ;
		maxD = -1;

		dfs(adj , vis , maxNode , 0);

		cout << maxD << nl;



		/*_____________________End Here____________________________*/
	}
	return 0;
}

