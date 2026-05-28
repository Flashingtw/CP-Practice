#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;

bool chk(vector<int> &v,int tar){
    int cur=0;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(v[i]>tar) return false;
        if(cur+v[i]>tar){
            cnt++;
            cur=v[i];
        }
        else{
            cur+=v[i];
        }
    }
    return cnt<=m;
}

void solve(){
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int l=0,r=1e9,ans=0;
    while(l<=r){
        int mid = (l+r)/2;
        if(chk(v,mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << '\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}