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

vi ar[1001];
int vis[1001];
int dist[1001];

void dfs(int node, int dis) {

	vis[node] = 1;
	dist[node] = dis;
	for (auto child : ar[node])
	{
		if (!vis[child]) {
			dfs(child , dist[node] + 1);
		}
	}

}


int main() {

	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int N ; cin >> N ;

	for (int  i = 1 ; i < N ; i++) {
		int a, b;
		cin >> a >> b ;
		ar[a].pb(b);
		ar[b].pb(a);
	}

	dfs(1 , 0);

	int q;  cin >> q;
	int ans = -1 , min_dis = (1e9);
	while (q--) {
		int girl_city ;
		cin >> girl_city ;

		if (dist[girl_city] < min_dis )
		{
			min_dis = dist[girl_city];
			ans = girl_city ;
		}
		if (dist[girl_city] == min_dis && girl_city < ans)
		{
			ans = girl_city ;
		}
	}

	cout << ans;



	return 0;
}

