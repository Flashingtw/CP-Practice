#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
int prefix[1005][1005];
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+(grid[i][j]=='*');
        }
    }
    while(q--){
        //y->i x->j
        int x1,x2,y1,y2;
        cin>>y1>>x1>>y2>>x2;
        cout << prefix[y2][x2]-prefix[y1-1][x2]-prefix[y2][x1-1]+prefix[y1-1][x1-1] << "\n";
    }
}