/*____________________________Definitions__________________________*/
#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long int ll;
typedef vector<int> vi;
#define Rep(i, a, b) for (int i=a; i<(b); i++)
#define trav(a,x) for(auto& a : x)
#define nl '\n'
#define ri(n) int n; scanf("%d", &n);
#define rll(n) ll n; scanf("%lld", &n);
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define mod 100000000
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

int limit_f, limit_h;
ll dp[101][101][11][11];
int getAns(int f , int h, int k1 , int k2){
	if ((f + h )== 0) return 1;
	if(dp[f][h][k1][k2] != -1)	return dp[f][h][k1][k2];
	
	int x = 0;
	if(f>0 && k1 > 0) x = getAns( f-1 , h, k1-1 , limit_h);
	int y = 0 ;
	if(h>0 && k2> 0) y= getAns(f , h-1, limit_f , k2-1);

	return dp[f][h][k1][k2] = (x + y) % mod;
}
int main() {

	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T=1;
		int n1 , n2 ;
	while (T--) {
	
		cin >> n1 >> n2 >> limit_f >> limit_h ;

			for ( int i = 0; i <=n1; i++)
			{
					for (int j = 0; j <=n2; j++)
					{
						for (int k = 0; k <=limit_f; k++)
						{
							for (int l = 0; l <=limit_h; l++)
								dp[i][j][k][l] = -1 ;
							
							
						}
						
					}
					
			}
			
		int ans = getAns(n1 , n2 , limit_f , limit_h);
 
		cout<<ans<<endl;
	}
	return 0;
}

