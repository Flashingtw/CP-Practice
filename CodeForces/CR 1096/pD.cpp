#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int n;
int chk(vector<int> &v,int l,int r){
    set<int> s;
    if(v[l]==v[r]){
        s.insert(v[l]);
    }
    else return 0;
    while(l>0&&r<2*n&&v[l-1]==v[r+1]){
        l--;
        r++;
        s.insert(v[l]);
    }
    int mx = 0;
    for(int i:s){
        if(i!=mx) break;
        mx++;
    }
    return mx;
}
void solve(){
    cin>>n;
    vector<int> v(2*n+5,-1);
    vector<int> pos;
    for(int i=1;i<=2*n;i++){
        cin>>v[i];
        if(v[i]==0) pos.push_back(i);
    }
    pos.push_back((pos[0]+pos[1])/2);
    int ans=1;
    for(int idx:pos){
        ans = max({ans,chk(v,idx,idx),chk(v,idx,idx+1)});
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}