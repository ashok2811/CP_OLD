// Implementation of Dijkstra's Algorithm
// Single Source Shorted Path
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
vector<pair<int,int>> adj[1001];

int main(){

    int n , m , a , b , w;
    cin >> n >> m ;

    while (m--) // Building graph
    {       cin>> a >> b >> w;
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
    }
    // A PQ to store pair of node and  distances with min heap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int , int>>> pq; 

    // Initialisation of distance array
    vector<int> dist(n+1, INF);
    dist[1] = 0 ;

    pq.push({0, 1});

    while (!pq.empty())     
    {
        int curr_n = pq.top().second;
        int curr_d= pq.top().first;
        pq.pop();
        for(auto edge : adj[curr_n]){
            if(curr_d + edge.second < dist[edge.first]){
                dist[edge.first] = curr_d + edge.second;
                pq.push({dist[edge.first], edge.first}); 
            }
        }
    }
    for (int i = 1; i <=n; i++)
    {
        cout << dist[i] << " " ;
    }
    
    

}

