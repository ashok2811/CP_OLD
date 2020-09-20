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

int E[1000001] , S[1000001] , F[1000001];

int main() {

    fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

        string st;
        int mx = 0;

        stack<int> stk;
        
        cin >> st;
        
        for (int i = 0; i < (int)st.size(); i++)
        {
            char ch = st[i];
            if(ch == '('){
                stk.push(i);
            }
            else{
                if(stk.empty()){
                        S[i] = E[i] = -1 ;
                     }

                    else{
                        int idx = stk.top();
                        stk.pop();

                        S[i] = E[i] =idx ;

                        if(idx > 0 && st[idx-1] == ')' && S[idx-1] >= 0)
                            E[i] = E[idx -1];                  

                        int l = i - E[i] + 1 ;
                        F[l]++;
                        mx = max(mx , l);
                    }

            }

            
        }
        
        F[0] = 1 ;
        cout << mx << " " << F[mx];

}

