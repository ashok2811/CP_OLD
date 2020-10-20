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
vector<int> adj[1000001];
int vis[1000001] , cc[1000001];
int cur_cc;

void dfs(int node)
{
	vis[node] = 1 ;
	cc[node] = cur_cc ;
	trav(child , adj[node]) {
		if (!vis[child])
		{
			dfs(child);
		}
	}
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

		int V, C ;  cin >> V >> C;
		for (int i = 1; i <= V; ++i)
		{
			adj[i].clear() , vis[i] = 0;
		}

		string op ;
		int a , b;
		vector<pair<int, int>> edge;

		for (int i = 1; i <= C; ++i)
		{
			cin >> a >> op >> b;
			if (op == "=") adj[a].pb(b) , adj[b].pb(a) ;
			else edge.pb({a , b});

		}

		for (int i = 1 ; i <= V ; i++) {
			if (!vis[i]) {
				cur_cc++;
				dfs(i);
			}
		}


		bool flag = true ;
		trav(x , edge) {
			a = x.f, b = x.s ;
			if (cc[a] == cc[b]) {flag = false ; break ;}
		}


		(flag) ? cout << "YES\n" : cout << "NO\n" ;



		/*_____________________End Here____________________________*/
	}
	return 0;
}

