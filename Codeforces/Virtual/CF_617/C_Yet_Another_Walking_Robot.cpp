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
            int n ; cin >> n;
        string str; 
        cin >> str ;
        
        bool found =0;

        for (int i = 2; i <=n, found == 0; i+=2)
        {   int hor = 0 , ver = 0 , k ;
            for( k = 0 ; k< i ; k++){
                if(str[k] == 'L') hor--;
                if(str[k] == 'R') hor++;
                if(str[k] == 'D') ver--;
                if(str[k] == 'U') ver++;
            }
            if(hor == 0 && ver ==0 ){
                cout << 1 << " " << k  << nl;
                found = 1 ;
                break;
            }

            for (int j = i; j < n; j++)
            {      
                if(str[j] == 'L') hor--; 
                if(str[j] == 'R') hor++;
                if(str[j] == 'D') ver--;
                if(str[j] == 'U') ver++;
                if(str[j-i] == 'L') hor++; 
                if(str[j-i] == 'R') hor--;
                if(str[j-i] == 'D') ver++;
                if(str[j-i] == 'U') ver--;               

                if(hor == 0 || ver ==0 ){
                cout << (j-i) << " " << j << nl;
                found =1;
                break;
                }
            }
            
        }

              
        if(!found){
            cout << -1 << nl;
        }



    }
    return 0;
}

