#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF = 1e18+9;
vector<vector<ll>> grid;
vector<vector<ll>> prefix;
int r,c;
ll ans=-INF;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>r>>c;
    grid.resize(r+1,vector<ll>(c+1));
    prefix.resize(r+1,vector<ll>(c+1));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++) {
            cin>>grid[i][j];
            prefix[i][j] = prefix[i-1][j]+grid[i][j];
        }
    }
    for(int b=1;b<=r;b++){
        for(int t=b;t<=r;t++){
            ll cur=0;
            for(int i=1;i<=c;i++){
                cur+=prefix[t][i]-prefix[b-1][i];
                ans = max(ans,cur);
                if(cur<0) cur=0;
            }
        }
    }
    cout << ans;
}