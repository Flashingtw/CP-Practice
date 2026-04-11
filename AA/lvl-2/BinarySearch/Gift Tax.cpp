#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

ll n,a,b;
bool chk(vector<ll> &v,ll tar){
    ll left=0,right=0;
    for(int i=0;i<n;i++){
        if(v[i]<tar){
            left+=(tar-v[i] +a-1)/a;
        }
        if(v[i]>tar){
            right+= (v[i]-tar)/b;
        }
    }
    return left<=right;
}

int main(){
    cin>>n>>a>>b;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    ll l = 1,r = 1e9,ans=0;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(v,mid)){
            ans=mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans;
}