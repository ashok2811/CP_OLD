// A technique to improve running time of find operation
#include <bits/stdc++.h>
using namespace std;

vector<int> parent(100001, -1);
vector<int> Rank(100001, 1);
 
int findSet(int a){ // union using path compression
    if(parent[a]<0) return a;
    return parent[a] = findSet(parent[a]);
}

void Merge(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a==b) return ;
    if(Rank[a] >= Rank[b]){
        // a would be parent;
        parent[b] = a ;
        Rank[a] += Rank[b];
    }

    if(Rank[a] < Rank[b]){
        // b would be parent;
        parent[a] = b ;
        Rank[b] += Rank[a];
    }

}

int main (){

    int n , m ;
    cin >> n >> m;

    for(int i = 0 ; i<m ; i++){
        int a , b ; 
        cin >> a >> b ;
        Merge(a , b); // union if they have diff parent      
    }
}
