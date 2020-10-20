#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define Rep(i, a, b) for (int i=a; i<(b); i++)
#define trav(a,x) for(auto& a : x)
#define nl '\n'
#define ri(n) int n; scanf("%d", &n);
#define rll(n) ll n; scanf("%lld", &n);

vector<int> primes;
vector<int> adj[10001];
vector<int> vis(10001 , 0);
vector<int> dis(10001, -1);

void bfs(int node) {
    queue<int> Q;
    Q.push(node);
    vis[node] = 1;
    dis[node] = 0 ;

    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        for (auto child : adj[curr]) {
            if (!vis[child]) {
                Q.push(child);
                dis[child] = dis[curr] + 1;
                vis[child] = 1 ;
            }
        }
    }


}

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}


bool isValid(int a , int b) {
    int cnt = 0;
    while (a > 0) {
        if (a % 10 != b % 10) {
            cnt++;
        }
        a /= 10 , b /= 10;

    }

    return (cnt == 1) ? true : false ;
}


void buildGraph() {
    for (int i = 1000; i < 9999; ++i)
    {
        if (isPrime(i)) {
            primes.pb(i);
        }
    }

    for (int i = 0; i < (int)primes.size(); ++i)
    {
        for (int j = i + 1; j < (int)primes.size(); ++j)
        {
            int a = primes[i];
            int b = primes[j];

            if (isValid(a, b)) {
                adj[a].pb(b);
                adj[b].pb(a);
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
    buildGraph();
    int t ; cin >> t;

    while (t--) {
        int N = 10001, a, b;  cin >> a >> b ;
        for (int i = 0; i < 10000; ++i)
        {
            dis[i] = -1; vis[i] = 0 ;
        }



        bfs(a);

        if (dis[b] == -1) {
            cout << "Impossible" << endl;
        }
        else {
            cout << dis[b] << endl;
        }


    }
}