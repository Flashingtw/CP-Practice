#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
ll a[15];
int n;
vector<ll> ans;

void dfs(int idx,vector<ll> &v){
    if(idx==n){
        ll sn=0;
        for(ll i:v) sn^=i;
        ans.push_back(sn);
        return;
    }
    int sz = v.size();
    for(int i=0;i<sz;i++){
        v[i]+=a[idx];
        dfs(idx+1,v);
        v[i]-=a[idx];
    }
    v.push_back(a[idx]);
    dfs(idx+1,v);
    v.pop_back();
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    vector<ll> v;
    dfs(0,v);
    sort(ans.begin(),ans.end());
    cout << unique(ans.begin(),ans.end())-ans.begin() << '\n';
}