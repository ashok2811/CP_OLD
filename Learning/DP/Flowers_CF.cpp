/*____________________________Definitions__________________________*/
#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
#define mod (1e9 + 7)
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

int k;
ll pre[100001];
ll dp[100001];
int getAns(int n){
    
    if(n==0) return 1 ;
      int ans = 0;

    if(dp[n]!= -1) return dp[n];
    //W
    if(n>=k){
         ans +=getAns(n-k), ans = ans % (int)mod;
    } 
   
    //R
    ans +=getAns(n-1), ans = ans % (int)mod;
    return dp[n] = ans;
}

void init(){

    for (int i = 1; i <=100000; i++)
    {
        dp[i] = -1;
    }
    
    for (int i = 1; i <= 100000; i++)
    {
        pre[i] = pre[i-1] + getAns(i) , pre[i] = pre[i] % (int)mod;
    }
    
}

int main() {

    fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T; cin >> T >>k;
    int a, b;
    init();
    while (T--) {
        cin >> a >> b ;
        int sum = (pre[b] - pre[a-1] + (int)mod)%(int)mod; 

        cout << sum << nl;

    }
    return 0;
}

