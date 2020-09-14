#include <bits/stdc++.h>
using namespace std;

long long nCr(int n , int r){
    long long res = 1 ;
    for(int i = 0 ; i< r ; i++){
        res *=(long long)(n-i);
        res /=(long long)(i+1);
    }
    return res;
}

int main() {

    int n , r ; cin  >> n >> r ;
    cout << nCr(n,r);

    return 0;
}

