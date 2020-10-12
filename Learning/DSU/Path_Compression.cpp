// A technique to improve running time of find operation
#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int findSet(int a){ // union using path compression
    if(parent[a]<0) return a;
    return parent[a] = findSet(parent[a]);
}
void unionSet(int a , int b){ // implemented according to the question
        parent[a] = min(parent[a], parent[b]);
        parent[b] = a ;
}

int main (){

}
