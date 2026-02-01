#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int LOG = 20;
int val[N];
int st[N][LOG];
int n;
void build(){
    for(int i=0;i<n;i++) st[i][0]=val[i];
    for(int j=1;j<LOG;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            st[i][j] = min(st[i][j-1],st[i+(1<<j-1)][j-1]);
        }
    }
}
int query(int l,int r){
    int lg=__lg(r-l+1);
    return min(st[l][lg],st[r-(1<<lg)+1][lg]);
}
