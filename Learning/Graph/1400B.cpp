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
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

/*__________________________________________________________________*/


int main() {

	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; cin >> T;
	while (T--) {
		/*_____________________Code Here____________________________*/
		int p , f , cnts , cntw , s , w ;
		cin >> p >> f >> cnts >> cntw >> s >> w;

		if (s > w) {
			swap(s, w);
			swap(cnts , cntw);
		}

		int ans = 0;
		for (int s1 = 0 ; s1 <= min(cnts , p / s) ; s1++) {

			int w1 = min(cntw ,  (p - s1 * s) / w) ;
			int s2 = min(cnts - s1, f / s);
			int w2 = min(cntw - w1 , (f - s2 * s) / w);

			ans = max(ans , s1 + s2 + w1 + w2) ;

		}


		cout << ans << nl;

		/*_____________________End Here____________________________*/
	}
	return 0;
}

