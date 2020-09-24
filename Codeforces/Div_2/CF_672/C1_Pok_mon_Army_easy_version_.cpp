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

        int n, q;
        cin>>n>>q;

        int k=1;

        vector<int> v(n);

        for(int i=0; i<n; i++){
            cin>>v[i];
        }

        long long int sum=0, val=v[0], ans=0;
        int i=0;
        while(i<n){
            val=v[i];
            if(k%2){
                while(i<=n-1 && val<=v[i]){
                    val=v[i];
                    i++;
                }
                k++;
                sum+=val;
            }
            else{
                while(i<=n-1 && val>=v[i]){
                    val=v[i];
                    i++;
                }
                k++;
                sum-=val;
            }

            ans = max(ans, sum);
            
        }

        cout<<ans<<'\n';


    }
    return 0;
}

