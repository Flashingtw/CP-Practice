#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
ll pre[1005][3005],suf[1005][3005];

int main(){
    int n,m;
    cin>>n>>m;
    vector<pii> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i].first>>v[i].second;
    }
    for(int i=1;i<=n;i++){
        for(int w=0;w<=m;w++){
            pre[i][w] = pre[i-1][w];
            if(w>=v[i].first){
                pre[i][w] = max(pre[i][w],pre[i-1][w-v[i].first]+v[i].second);
            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int w=0;w<=m;w++){
            suf[i][w] = suf[i+1][w];
            if(w>=v[i].first){
                suf[i][w] = max(suf[i][w],suf[i+1][w-v[i].first]+v[i].second);
            }
        }
    }
    ll g = pre[n][m];
    for(int i=1;i<=n;i++){
        ll cur=-1;
        for(int w=0;w<=m-v[i].first;w++){
            cur = max(cur, pre[i-1][w]+suf[i+1][m-v[i].first-w]+v[i].second);
        }
        cout << (cur==g?"Yes":"No") << "\n";
    }
}