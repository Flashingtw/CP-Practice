#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll a[20];
vector<pair<int,int>> adj[20];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++){
        int u,v,b;
        cin>>u>>v>>b;
        u--,v--;
        adj[u].push_back({v,b});
    }
    ll ans=-1e18;
    for(int mask=0;mask<(1<<n);mask++){
        int cnt=0;
        ll tmp=0;
        for(int i=0;i<n;i++) if(mask&(1<<i)) {
            cnt++;
            tmp+=a[i];
        }
        if(cnt!=k) continue;
        for(int u=0;u<n;u++){
            if(mask&(1<<u)){
                for(auto [v,b]:adj[u]){
                    if(mask&(1<<v)){
                        tmp-=b;
                    }
                }
            }
        }
        ans=max(ans,tmp);
    }
    cout << ans;
}