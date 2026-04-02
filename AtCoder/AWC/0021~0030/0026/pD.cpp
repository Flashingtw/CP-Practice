#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

struct event{
    int d,type;
    bool operator<(event &ot){
        if(d==ot.d) return type<ot.type;
        return d<ot.d;
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<event> v;
    int mx=0,mn=2e9;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        v.push_back({l,1});
        v.push_back({r,-1});
        mx = max(r,mx);
        mn = min(l,mn);
    }
    sort(v.begin(),v.end());
    int cnt=0,cur=mn;
    int ans=0;
    for(auto [d,type]:v){
        if(cnt>=k){
            ans+= d-cur;
        }
        cur=d;
        if(type==1){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    cout << ans;
}