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

vector<int > ar[100];
int in[101], low[101], vis[101];
int timer = 0 ;
void dfs(int node, int parent) {
	vis[node]  = 1 ;
	in[node] = low[node] = timer ;
	timer ++;
	trav(child , ar[node]) {
		if (child == parent) { continue;}

		if (!vis[child]) {
			// edgenode - child is forward edge
			dfs(child , node) ;
			if (low[child] > in[node]) {
				cout << node << " -- " << child << " is a bridge" << nl;
			}

			low[node] = min(low[node], low[child]);
		}
		else if (vis[child] == 1) {
			// child is a backedge

			low[node] = min(low[node] , in[child]) ;
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
		int n , m , x , y ;
		cin >> n >> m ;
		while (m--) {
			cin >> x >> y ;
			ar[x].pb(y); ar[y].pb(x);
		}

		dfs(1 , -1) ;




		/*_____________________End Here____________________________*/
	}
	return 0;
}

