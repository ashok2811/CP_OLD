/*____________________________Definitions__________________________*/
#include <bits/stdc++.h>
using namespace std;
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef vector<int> vi;
#define Rep(i, a, b) for (int i = a; i < (b); i++)
#define trav(a, x) for (auto &a : x)
#define nl '\n'
#define ri(n) \
    int n;    \
    scanf("%d", &n);
#define rll(n) \
    ll n;      \
    scanf("%lld", &n);
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

int main()
{

    fastIO
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
	int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> p(n);
		for (int i = 0; i < m; ++i) {
			int pos;
			cin >> pos;
			p[pos - 1] = 1;
		}
		for (int i = 0; i < n; ++i) {
			if (p[i] == 0) continue;
			int j = i;
			while (j < n && p[j]) ++j;
			sort(a.begin() + i, a.begin() + j + 1);
			i = j;
		}
		bool ok = true;
		for (int i = 0; i < n - 1; ++i) {
			ok &= a[i] <= a[i + 1];
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
    }
    return 0;
}
