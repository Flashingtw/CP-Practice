#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

struct node{
    int l,r,v,id;
    bool operator<(node oth){
        return v<oth.v;
    }
};

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int x,n;
    cin>>x>>n;
    vector<node> v(n+2);
    v[0].v=0,v[0].id=0,
    v[n+1].v=x,v[n+1].id=n+1;
    for(int i=1;i<=n;i++){
        cin>>v[i].v;
        v[i].id=i;
    }
    sort(v.begin(),v.end());
    vector<int> idx(n+2);
    v[0].r=v[1].id;
    v[n+1].l=v[n].id;
    int mx=0;
    for(int i=1;i<=n;i++){
        idx[v[i].id]=i;
        v[i].r=i+1;
        v[i].l=i-1;
    }
    for(int i=1;i<=n+1;i++){
        mx = max(mx,v[i].v-v[i-1].v);
    }
    vector<int> ans(n);
    for(int i=n;i>0;i--){
        ans[i-1]=mx;
        int id = idx[i];
        int nxt = v[id].r;
        int prv = v[id].l;
        v[nxt].l = prv;
        v[prv].r = nxt;
        mx= max(mx,v[nxt].v-v[prv].v);
    }
    for(int i:ans) cout << i << ' ';
}