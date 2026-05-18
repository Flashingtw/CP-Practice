#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

int main(){
    int n,k;
    cin>>n>>k;
    vector<pii> v(n);
    for(auto &[a,b]:v) cin>>a>>b;
    priority_queue<int> pq;
    sort(v.begin(),v.end());
    int ans=2e9;
    
    for(int i=0;i<n;i++){
        pq.push(v[i].second);
        if(pq.size()>k) pq.pop();
        if(pq.size()==k){
            ans = min(ans,v[i].first+pq.top());
        }
    }
    cout << ans << '\n';
}