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

void printGraph(vector<int> adj[] , int V) {
	for (int i = 0; i < V; ++i)
	{
		cout << "\n Adjacency list of vertex "
		     << i << "\n head ";
		for (auto x : adj[i])
			cout << "-> " << x;
		printf("\n");
	}
}



void dfs(vector <int> adj[] , vector<int>& vis , int node) {

	vis[node] = 1;

	//cout << node << " ";
	for (auto child : adj[node])
	{

		if (!vis[child]) {
			dfs(adj , vis, child);

		}
	}

}


int main() {

	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int V , E; cin >> V >> E;

	vector<int> adj[V];
	vector<int> vis(V, 0);
	int EE = E;
	while (E--) {
		int a, b ; cin >> a >> b ;
		addEdge(adj, a, b);
	}


	//printGraph(adj, V);
	int cc = 0 ;
	for (int i = 0; i < V; ++i)
	{

		if (!vis[i]) {
			dfs(adj, vis , i);
			cc++;
		}
	}

	cout << "\nNumber of Connected Component: " <<  cc << nl;

	if ((cc == 1) && (V - EE == 1)) {
		cout << "It is a tree.";
	}
	else {
		cout << "It is not a Tree.";
	}

	return 0;
}

