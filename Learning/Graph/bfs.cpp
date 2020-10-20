#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int> adj[], vector<int> &vis, vector<int> &dis, int node) {
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


int main() {
    int t ; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M ;

        vector<int> adj[N + 1];
        vector<int> vis(N + 1 , 0);
        vector<int> dis(N + 1, 0);



        while (M--) {
            int a, b ; cin >> a >> b ;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }



        bfs(adj , vis , dis, 1);

        cout << dis[N] << endl;
    }
}