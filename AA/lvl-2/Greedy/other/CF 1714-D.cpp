#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct LN{
    int l,r;
    int idx;
    bool operator<(const LN &i) const {
        return l<i.l;
    };
};
void solve(){
    string s;
    cin>>s;
    int t;
    cin>>t;
    vector<pair<string,int>> v(t);
    for(int i=0;i<t;i++) {
        cin>>v[i].first;
        v[i].second=i+1;
    }
    int sz = s.size();
    vector<LN> ln; 
    for(auto &[a,idx]:v){
        int m = a.size();
        for(int i=0;i+m-1<sz;i++){
            bool chk=1;
            for(int j=0;j<m;j++){
                if(s[i+j]!=a[j]) {
                    chk=0;
                    continue;
                }
            }
            if(!chk) continue;
            ln.push_back({i,i+m-1,idx});
        }
    }
    int n = ln.size();
    sort(ln.begin(),ln.end());
    int cur=0;
    int i=0;
    vector<pii> ans;
    while(i<n&&cur<sz){
        int mx = cur-1;
        int idx=-1;
        while(i<n&&ln[i].l<=cur){
            if(ln[i].r>mx){
                mx = ln[i].r;
                idx = i;
            }
            i++;
        }
        if(mx<cur) {
            cout << -1 << '\n';
            return;
        }
        ans.push_back({ln[idx].idx,ln[idx].l+1});
        cur = mx+1;
    }
    if(cur<sz){
        cout << -1 << '\n';
        return;
    }
    cout << ans.size() << '\n';
    for(auto &[a,b]:ans){
        cout << a << ' ' << b << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}