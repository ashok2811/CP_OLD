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

int main() {

    fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) {
       ll n;
        cin>>n;
        vector<ll> v(n);
         map<ll, vector<ll>> mp;
        for(int i=0; i<n; i++){
            cin>>v[i];
             mp[log2(v[i])].push_back(v[i]);
        }
        ll ans = 0;
        for(auto vi:mp){
            ll s=vi.second.size();
            ans+=((ll)s*(s-1))/2;
        }
        cout<<ans<<'\n';    

    }
    return 0;
}

