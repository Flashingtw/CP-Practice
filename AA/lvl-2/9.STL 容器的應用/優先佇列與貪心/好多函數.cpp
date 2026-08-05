#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
struct func{
    ll a,b,c;
};
ll f(ll x,func fun){
    return fun.a*x*x+fun.b*x+fun.c;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<func> v(n);
    for(int i=0;i<n;i++) cin>>v[i].a>>v[i].b>>v[i].c;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0;i<n;i++){
        pq.push({f(1,v[i])-f(0,v[i]),i});
    }
    vector<int> x(n);
    for(int i=0;i<k;i++){
        auto [a,idx] = pq.top();
        pq.pop();
        x[idx]++;
        pq.push({f(x[idx]+1,v[idx])-f(x[idx],v[idx]),idx});
    }
    ll t=0;
    for(int i=0;i<n;i++){
        t+=f(x[i],v[i]);
    }
    cout << t << '\n';
}