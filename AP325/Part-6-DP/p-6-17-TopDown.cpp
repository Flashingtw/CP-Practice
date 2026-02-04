#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memo(600,vector<int>(600,-1));
int p[200];

int cut(int l,int r) {
    if (memo[l][r]>=0) return memo[l][r];
    int mincost=1e9;
    for (int i=l+1;i<r;i++) {
        mincost = min(mincost, cut(l,i)+cut(i,r));
    }
    mincost+=p[r]-p[l];
    return mincost;
}

int main() {
    int n,L;
    cin>>n>>L;
    for (int i=1;i<=n;i++) {
        cin>>p[i];
    }
    p[0]=0,p[n+1]=L;
    for (int i=0;i<n+1;i++) {
        memo[i][i+1] = 0;
    }
    cout << cut(0,n+1);
}