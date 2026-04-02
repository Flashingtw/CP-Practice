#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 1e9+9;
int main(){
    ll n,m,s;
    cin>>n>>m>>s;
    vector<ll> d(n+1);
    for(int i=1;i<=n;i++) cin>>d[i];
    vector<pii> pr(m);
    for(int i=0;i<m;i++){
        cin>>pr[i].first>>pr[i].second;
    }
    sort(pr.begin(),pr.end());
    int cur=0;
    bool is=false;
    for(int i=1;i<=n;i++){
        if(!is){
            s-= d[i];
        }
        else{
            s-= 2*d[i];
        }
        if(s<=0) is=true;
        if(cur<m&&pr[cur].first==i){
            s+=pr[cur].second;
            cur++;
        }
    }
    cout << s;
}