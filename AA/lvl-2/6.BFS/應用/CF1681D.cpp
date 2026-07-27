#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct state{
    ll x;
    int d;
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,x;
    cin>>n>>x;
    set<ll> vis;
    queue<state> q;
    q.push({x,0});
    vis.insert(x);
    while(!q.empty()){
        auto [a,d] = q.front();
        q.pop();
        string b = to_string(a);
        int sz = b.size();
        if(sz>n) continue;
        if(sz==n){
            cout << d << '\n';
            return 0;
        }
        for(int i=0;i<sz;i++){
            ll nxt = a*(b[i]-'0');
            if(vis.find(nxt)!=vis.end()) continue;
            q.push({nxt,d+1});
            vis.insert(nxt);
        }
    }
    cout << -1 << '\n';
}