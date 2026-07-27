#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll val[2000005];
int n;
int lmt;

bool chk(ll mid){
    int cur=0;
    for(int i=0;i<2*n;i++){
        if(val[i%n]<mid){
            cur++;
        }
        else{
            cur=0;
        }
        if(cur>=lmt) return 0;
    }
    return 1;
}

int main(){
    cin>>n;
    lmt = (n-1)/2;
    ll l = 1,r = 0,ans;
    for(int i=0;i<n;i++){
        cin>>val[i];
        r = max(r,val[i]);
    }
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(val[i]>ans) cnt+=val[i]-ans; 
    }
    cout << cnt << '\n';
}