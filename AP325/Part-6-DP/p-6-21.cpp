#include <bits/stdc++.h>
#define N 60
using namespace std;
int a[N][N];
int memo[N][N][N][N];
        //left  top   right   bottom
int cost (int l,int t,int r,int b) {
    int n0,n1,mcost,c;
    if (memo[l][t][r][b]>=0) return memo[l][t][r][b];

    //top change min
    n0 = n1 = 0;
    for (int i=l;i<=r;i++) a[t][i] ? n1++:n0++;
    mcost = cost(l,t+1,r,b) + (n1<n0?n1:n0);
    //bottom change min
    n0 = n1 = 0;
    for (int i=l;i<=r;i++) a[b][i] ? n1++:n0++;
    c = cost(l,t,r,b-1) + (n1<n0?n1:n0);
    mcost = min(mcost,c);
    //left change min
    n0 = n1 = 0;
    for (int i=t;i<=b;i++) a[i][l] ? n1++:n0++;
    c = cost(l+1,t,r,b) + (n1<n0?n1:n0);
    mcost = min(mcost,c);
    //right change min
    n0 = n1 = 0;
    for (int i=t;i<=b;i++) a[i][r] ? n1++:n0++;
    c = cost(l,t,r-1,b) + (n1<n0?n1:n0);
    mcost = min(mcost,c);
    memo[l][t][r][b] = mcost;
    return mcost;
}

int main() {
    int m,n;
    cin>>m>>n;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for (int l=0;l<n;l++) for (int r=l;r<n;r++)
            for (int t=0;t<m;t++) for (int b=t;b<m;b++)
                    memo[l][t][r][b] = (r==l || b==t)? 0: -1;
    cout << cost(0,0,n-1,m-1);
}