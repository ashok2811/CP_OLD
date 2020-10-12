// A technique to improve running time of find operation
#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int findSet(int a){ // union using path compression
    if(parent[a]<0) return a;
    return parent[a] = findSet(parent[a]);
}
void unionSet(int a , int b){
        parent[a] = min(parent[a], parent[b]);
        parent[b] = a ;
}

int main (){

    int n , m ;
    cin >> n >> m;
    for(int i = 0 ; i<=n ; i++){
        parent.push_back(-i);
    }

    for(int i = 0 ; i<m ; i++){
        int a , b ; 
        cin >> a >> b ;
        a = findSet(a);
        b = findSet(b);
        if(a!=b) unionSet(a , b); // union if they have diff parent      
    }

    int q ;
	cin >> q ;
	  for(int i = 0 ; i<q ; i++){
        int a , b ; 
        cin >> a >> b ;
		int aa = a , bb = b ;
        a = findSet(a);
        b = findSet(b);
		if(a==b) cout << "TIE" << endl;
		else {
            if(parent[a]<parent[b]){
			cout << aa << endl;
		} 
		else{
			cout << bb << endl;
		} 

        }
        
             
    }
    


}
