#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dist[5005][5005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dist[i][j];
        }
    }
}