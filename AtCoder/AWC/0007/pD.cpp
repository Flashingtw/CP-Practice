#include <bits/stdc++.h>
using namespace std;
int A[505][505],B[505][505];
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    for(int c=0;c<a;c++){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                A[i][j]++;
            }
        }
    }
    for(int c=0;c<b;c++){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                B[i][j]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(A[i][j]&&B[i][j]) ans++;
        }
    }
    cout << ans;
}