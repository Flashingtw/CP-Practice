#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll s;
vector<ll> a;
void dfs(int idx,ll sum,int end,map<ll,ll> &res){
    if(sum>s) return;
    if(idx==end){
        res[sum]++;
        return;
    }
    dfs(idx+1,sum,end,res);
    dfs(idx+1,sum+a[idx],end,res);
}
int main(){
    cin>>n>>s;
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<ll,ll> left,right;
    int mid = n/2;
    dfs(0,0,mid,left);
    dfs(mid,0,n,right);
    ll ans=0;
    for(auto [num,cnt]:right){
        ll t = s-num;
        if(t<0) continue;
        if(left.count(t)){
            ans+=cnt*left[t];
        }
    }
    cout << ans;
}