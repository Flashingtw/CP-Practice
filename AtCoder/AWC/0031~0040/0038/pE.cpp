#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int matr[40][40];
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> p(n+1);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<k;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        matr[u][v]=1;
        matr[v][u]=1;
    }
    int half = n/2;
    vector<ll> dp((1<<half));
    for(int mask=0;mask<(1<<half);mask++){
        bool a=0;
        for(int u=0;u<half;u++){
            for(int v=0;v<half;v++){
                if((mask&(1<<u)&&mask&(1<<v))&&matr[u][v]) a=1;
            }
        }
        if(a) continue;
        for(int u=0;u<half;u++){
            if(mask&(1<<u)){
                dp[mask]+=p[u];
            }
        }
    }
    for(int i=0;i<half;i++){
        for(int mask=0;mask<(1<<half);mask++){
            if(mask&(1<<i)){
                dp[mask] = max(dp[mask], dp[mask^(1<<i)]);
            }
        }
    }
    int rh = n-half;
    vector<int> ban(rh);
    for(int u=0;u<rh;u++){
        for(int v=0;v<half;v++){
            if(matr[u+half][v]){
                ban[u] |= (1<<v);
            }
        }
    }
    ll mx=0;
    for(int mask=0;mask<(1<<rh);mask++){
        bool a=0;
        for(int u=0;u<rh;u++){
            for(int v=0;v<rh;v++){
                if((mask&(1<<u)&&mask&(1<<v))&&matr[u+half][v+half]) a=1;
            }
        }
        if(a) continue;
        int safe = (1<<half)-1;
        ll t=0;
        for(int u=0;u<rh;u++){
            if(mask&(1<<u)){
                safe &= ~ban[u];
                t+=p[u+half];
            }
        }
        mx = max(mx,dp[safe]+t);
    }
    cout << min(mx,m);
}