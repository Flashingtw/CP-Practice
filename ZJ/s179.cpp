#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
ll w[N];
ll prefix[N];
ll n,m;

ll s(int l,int r){
    if(l>r) return 0;
    return prefix[r]-prefix[l-1];
}

bool chk(int l,int r,int k,int a,int b){
    return (s(l,k)*(a+b))>=a*s(l,r);
}

void solve(){
    int l,r,a,b;
    cin>>l>>r>>a>>b;
    int left=l,right=r;
    int ans=0;
    while(left<=right){
        int mid = (left+right)/2;
        if(chk(l,r,mid,a,b)){
            right = mid-1;
            ans = mid;
        }
        else{
            left = mid +1;
        }
    }
    cout << ans << '\n';
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        prefix[i] = prefix[i-1]+w[i];
    }
    while(m--){
        solve();
    }
}