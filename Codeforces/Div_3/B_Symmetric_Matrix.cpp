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

        int n , m ; cin >> n >> m;
        bool flag = 0 ;
        for(int i = 0 ;i < n ; i++){
            int a1 , a2 , b1 , b2 ;
            cin >> a1 >> a2 >> b1 >> b2 ;
            if(a2==b1) flag = 1 ;
        }

        if(m%2==0){
            (flag) ? cout<< "YES\n" : cout <<"NO\n" ;
        }

        else {
            cout<< "NO\n";
        }



    }
    return 0;
}

