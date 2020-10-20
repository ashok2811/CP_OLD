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


bool isCycle(vector <int> adj[] , vector<int>& vis , int node, int parent) {

	vis[node] = 1;


	for (auto child : adj[node])
	{

		if (!vis[child]) { // if the child was not visited ;

			if (isCycle(adj , vis, child , node) == true) {
				// toggling the color for child
				return true;
			}

		}

		else { // if child was visited, check if is has same parent .
			if (child != parent)
			{
				return true;
			}
		}
	}

	return false;

}

int main() {

	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int V , E; cin >> V >> E;

	vector<int> adj[V + 1];
	vector<int> vis(V + 1, 0);
	vector<int> color(V + 1);

	while (E--) {
		int a, b ; cin >> a >> b ;
		addEdge(adj, a, b);
	}

	cout << isCycle(adj, vis,  1, -1);


	return 0;
}

