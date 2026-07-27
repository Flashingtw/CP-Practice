#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<pii> v(m);
    for(auto &[a,b]:v) cin>>a>>b;
    sort(v.begin(),v.end());
    int cur=1;
    int ans=0;
    int it=0;
    while(cur<=n){
        int ls = cur-1;
        while(it<m&&v[it].first<=cur){
            ls = max(ls,v[it].second);
            it++;
        }
        if(ls<cur){
            ans = -1;
            break;
        }
        cur = ls+1;
        ans++;
    }
    cout << ans << '\n';
}