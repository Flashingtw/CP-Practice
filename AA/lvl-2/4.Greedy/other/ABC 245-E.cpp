#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF = 1e9+9;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pll> a(n),b(m);
    for(auto &[f,s]:a) cin>>f;
    for(auto &[f,s]:a) cin>>s;
    for(auto &[f,s]:b) cin>>f;
    for(auto &[f,s]:b) cin>>s;
    sort(a.begin(),a.end(),greater());
    sort(b.begin(),b.end(),greater());
    multiset<ll> s;
    int j=0;
    for(int i=0;i<n;i++){
        while(j<m&&b[j].first>=a[i].first){
            s.insert(b[j++].second);
        }
        auto it = s.lower_bound(a[i].second);
        if(it==s.end()){
            cout << "No" << '\n';
            return 0;
        }
        s.erase(it);
    }
    cout << "Yes" << '\n';
}