#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
ll up[2*N][30];
ll n,q;
ll v[N];
void init(){
    for(int i=0;i<n;i++){
        up[i][0]=n+(i+v[i])%n;
    }
    for(int i=n;i<2*n;i++){
        int x = i-n;
        up[i][0]=(x-v[x]%n+n)%n;
    }
    for(int k=1;k<30;k++){
        for(int i=0;i<2*n;i++){
            up[i][k] = up[up[i][k-1]][k-1];
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>v[i];
    init();
    while(q--){
        ll p,d,k;
        cin>>p>>d>>k;
        p--;
        ll cur = (d==1)?p:p+n;
        for(int j=0;j<30;j++){
            if((k>>j)&1){
                cur = up[cur][j];
            }
        }
        cout << cur%n+1 << '\n';
    }
}