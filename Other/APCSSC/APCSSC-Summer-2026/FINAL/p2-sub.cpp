#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

ll dx[3];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    int y0,y1,h0,h1,n;
    cin>>y0>>y1>>dx[0]>>dx[1]>>dx[2]>>h0>>h1>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    ll ans =0;
    for(int i=1;i<=n;i++){
        int typ=-1;
        if(h0<=v[i]) typ=0;
        else if (h0>0) typ=1;
        else typ=2;
        ans = ans+dx[typ];
    }
    cout << ans << '\n';
}