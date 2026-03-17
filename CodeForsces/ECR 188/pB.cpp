#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(v.begin(),v.end(),greater());
    int cur=n+1;
    int cnt=0;
    for(auto &[num,idx]:v){
        if(idx<cur){
            cnt++;
            cur=idx;
        }
    }
    cout << cnt << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}