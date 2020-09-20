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

int is_prime[1000001];

void sieve(){
    int maxN = 1000000;
    for(int i = 1 ; i<=maxN ; i++) is_prime[i] =1 ;

    is_prime[0] = is_prime[1] = 0 ;
    for (int i = 2; i*i<= maxN; i++)
    {
            if(is_prime[i]){
                for (int j = i*i; j <=maxN; j = j+i)
                {
                    is_prime[j] = 0 ;
                }
                
            }
    }
    
}

int main() {

    fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    sieve();
    int T; cin >> T;
    while (T--) {
        int a , b ;
        cin >> a >>b;
        for(int i = a ; i<=b ; i++) {
            if(is_prime[i]) cout << i  << " " ;
        }
        cout << nl;

    }
    return 0;
}

