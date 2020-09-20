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

        int n ;
        string a ;
        cin >> n >> a;
        int raze_c=0, bre_c=0; 
       for(int i=0; i<n; i++){
            if(i%2 == 0){
                if(int(a[i]-'0')%2 == 1){
                    raze_c++;
                }
            }
            else{
                if(int(a[i]-'0')%2 == 0){
                    bre_c++;
                }
            }
        }

         if(n%2){
            if(raze_c>0){
                cout<<1<<'\n';
            }
            else{
                cout<<2<<'\n';
            }
        }
        else{
            if(bre_c>0){
                cout<<2<<'\n';
            }
            else{
                cout<<1<<'\n';
            }
        }
       

    }
    return 0;
}

