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
#define pb push_back
/*__________________________________________________________________*/

void addEdge(vector<int> adj[], int a , int b) {
	adj[a].push_back(b);
	adj[b].push_back(a);
}


bool bipartDFS(vector <int> adj[] , vector<int>& vis, vector<int>& color , int node, int c) {

	vis[node] = 1;
	color[node] = c ;

	for (auto child : adj[node])
	{

		if (!vis[child]) { // if the child was not visited ;

			if (bipartDFS(adj , vis, color, child , c ^ 1) == false) { // toggling the color for child
				return false;
			}

		}

		else { // if child was visited, check if is has same color .
			if (color[child] == color[node])
			{
				return false;
			}
		}
	}

	return true;

}

// https://www.spoj.com/problems/BUGLIFE/

int main() {

	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int N ; cin >> N ;
	for (int k = 1 ; k <= N; k++) {

		int V , E; cin >> V >> E;

		vector<int> adj[V + 1];
		vector<int> vis(V + 1, 0);
		vector<int> color(V + 1);

		while (E--) {
			int a, b ; cin >> a >> b ;
			addEdge(adj, a, b);
		}

		int ans = 1;

		for (int i = 1; i <= V; ++i)
		{

			if (!vis[i]) {
				if (bipartDFS(adj, vis, color , i , 1) == false) {
					ans  = 0;
					break;
				}

			}
		}



		cout << "Scenario #" << k << ":" << nl;
		(ans) ? cout << "No suspicious bugs found!\n" : cout << "Suspicious bugs found!\n" ;



	}

	return 0;
}

