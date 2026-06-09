#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
bool solve(){
    int n;
    cin>>n;
    vector<pii> v(n);
    for(auto &[l,r]:v) cin>>l>>r;
    sort(v.begin(),v.end());
    priority_queue<int,vector<int>,greater<>> pq;
    int cur=0;//next can use
    int i=0;
    while(i<n||!pq.empty()){
        if(i<n&&pq.empty()) cur = max(cur,v[i].first);
        
        while(i<n&&v[i].first<=cur){
            pq.push(v[i++].second);
        }
        if(!pq.empty()){
            if(pq.top()<cur) return 0;
            cur++;
            pq.pop();
        }
    }
    return pq.empty();
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        if(solve()){
            cout << "Yes" << '\n';
        }
        else cout << "No" << '\n';
    }
}