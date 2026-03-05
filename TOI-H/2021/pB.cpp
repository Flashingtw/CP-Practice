#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1005;
int n,m;
int t[N],s[N],d[N];

ll check(ll tc,ll k){
    ll l=0,r=2e9;
    ll c=-1;
    while(l<=r){
        ll mid = (l+r)/2;
        
        ll minu=0;
        for(int i=0;i<=k;i++){
            if(s[i]<mid) continue;
            if(d[i]==0){
                minu += tc+1;
                continue;
            }
            minu+= (s[i]-mid)/d[i] +1;
        }
        if(minu<=tc){
            c = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    ll cur=0,used=0;
    for(int i=0;i<=k;i++){
        if(s[i]<c) continue;
        if(d[i]==0){
            continue;
        }
        int x = (s[i]-c)/d[i] +1;
        used+=x;
        ll l = s[i]-(x-1)*d[i];
        cur+= (1LL*(s[i]+l)*x)/2;
    }
    cur += 1LL*(tc-used)*(max(0LL,c-1));
    return cur;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n-1;i++) cin>>t[i];
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++) cin>>d[i];
    ll mv=0;
    ll ans=-1;
    for(int i=0;i<n;i++){
        ll tclean = m-mv;
        if(m-mv<=0) break;
        ans = max(ans,check(tclean,i));
        mv+=t[i];
    }
    cout << ans;
}