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

vector<int> ar[100];
vector<int> res;
int in[100];

void kahn(int n){
    queue<int> q;
    for (int i = 1; i <=n; i++)
    {
        if(in[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        res.push_back(curr);
        q.pop();

        for (auto node: ar[curr])
        {
            in[node]--;
            if(in[node]==0)
                q.push(node);
        }
        
    }

    cout << "Top Sort: " ;
    for (int node : res)
    {
        cout << node << " ";
    }
    
    
} 

int main() {

    fastIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n , m , x , y;
    cin >> n >> m ;
    for (int i = 0; i <=m; i++)
     {
        cin >> x >> y;
        ar[x].push_back(y);
        in[y]++;
    }

    kahn(n);

    return 0;
}

