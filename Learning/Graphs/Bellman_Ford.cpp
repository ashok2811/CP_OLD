// Implementation of Bellman Ford Algorithm
// Single Source Shorted Path with Negative Weights
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

struct edge
{
    int a , b , cost ;
};

int n , m , v ;
vector<edge> edgeList;

void Bellman_Ford(){
    vector<int> dist(n, INF);
    dist[v] = 0;
    for (int i = 0; i < n-1 ; ++i)
    {
        for (int j = 0; j < m; j++)
        { 
            if(dist[edgeList[j].a] < INF){
                dist[edgeList[j].b] = min(dist[edgeList[j].b], dist[edgeList[j].a] + edgeList[j].cost);
            }
        }     
    }    
}

int main(){
    // Driver code
}

