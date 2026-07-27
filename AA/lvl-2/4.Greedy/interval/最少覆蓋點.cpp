#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int q;
    cin>>q;
    vector<pii> v(q);
    for(auto &[r,l]:v) cin>>l>>r;
    sort(v.begin(),v.end());
    int cur=0;
    int cnt=0;
    for(auto [r,l]:v){
        if(cur<l){
            cnt++;
            cur = r;
        }
    }
    cout << cnt << '\n';
}