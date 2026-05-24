#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct ln{
    ll l,r;
    bool operator <(ln oth){
        return l<oth.l;
    }
};
ll n,m,k;
vector<ln> a;
bool chk(ll x){
    vector<ln> v;
    for(auto [l,r]:a){
        if(r-l+1<=x){
            continue;
        }
        v.push_back({l,r-x});
    }
    ll curr=0;
    ll cnt=0;
    for(auto [l,r]:v){
        if(curr<l) curr=l;
        if(curr<=r){
            ll len = r-curr+1;
            ll d = (len+x)/(x+1);
            cnt+=d;
            curr+=d*(x+1);
        }
    }
    return cnt<=k;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int cnt;
        cin>>cnt;
        vector<int> d(cnt);
        for(int &i:d) cin>>i;
        d.push_back(0);
        d.push_back(n+1);
        sort(d.begin(),d.end());
        for(int i=0;i<d.size()-1;i++){
            if(d[i+1]-d[i]>1){
                a.push_back({d[i]+1,d[i+1]-1});
            }
        }
    }
    sort(a.begin(),a.end());
    ll l=0,r=n,ans=-1;
    while(l<=r){
        ll mid = (l+r)/2;
        if(chk(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << '\n';
}