#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    vector<int> p(m);
    for(int i=0;i<m;i++){
        cin>>p[i];
    }
    sort(v.begin(),v.end());
    sort(p.begin(),p.end());
    priority_queue<ll> pq;
    ll ans=0;
    for(int i=0,j=0;i<m;i++){
        while(j<n&&v[j].first<=p[i]){
            pq.push(v[j].second);
            j++;
        }
        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        else {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans;
}