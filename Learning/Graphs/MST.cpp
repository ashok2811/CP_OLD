#include <bits/stdc++.h>
using namespace std;

struct edge{ // A structure to contain the edge list
	int a ;
	int b; 
	int w;
};

bool comp(edge a , edge b){ // Custom comparator funtion
	if(a.w < b.w) return true ;
	else return false;
}

edge ar[100000];
vector<int> par(10001, -1);
vector<int> Rank(10001, 1);

int findSet(int a){ // find using path compression
    if(par[a]<0) return a;
    return par[a] = findSet(par[a]);
}

void Union(int a, int b){ // union by rank;
    a = findSet(a);
    b = findSet(b);
    if(a==b) return ;
    if(Rank[a] >= Rank[b]){
        // a would be parent;
        par[b] = a ;
        Rank[a] += Rank[b];
    }
    if(Rank[a] < Rank[b]){
        // b would be parent;
        par[a] = b ;
        Rank[b] += Rank[a];
    }
}


int main() {
int n , m , a, b ,w;
cin >> n >> m;

for(int i = 0 ; i< m ;i++){
	cin >> ar[i].a >> ar[i].b >> ar[i].w;
	}


int sum =0 ;
sort(ar, ar + m, comp);

for(int i = 0 ; i< m ; i++){
	a=findSet(ar[i].a);
	b=findSet(ar[i].b);
	if(a!=b){
		sum += ar[i].w;
		Union(a,b);
	}
}
	cout << sum ;
	return 0;
}

