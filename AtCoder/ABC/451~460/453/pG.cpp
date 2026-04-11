#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int M = 2e5+5;
const int N = 2e5+5;
struct BIT{
    vector<ll> tree;
    int sz;
    BIT(int _sz){
        sz=_sz+1;
        tree.resize(_sz+1,0);
    }
    void add(int idx,int val){
        for(;idx<=sz;idx+=idx&-idx) tree[idx]+=val;
    }
    ll query(int idx){
        ll sum=0;
        for(;idx>0;idx-=idx&-idx) sum+=tree[idx];
        return sum;
    }
    ll query(int l,int r){
        return query(r)-query(l-1);
    }
};
struct Edge{
    int to;
    int idx;
    int val;
};
struct Q {
    int id;
    int l,r;
};

int node_cnt = 0;
vector<Edge> adj[M];
vector<Q> queries[M];
ll ans[M];
int cur_ver[N];
int actval[200005];

BIT bit(M); 

void dfs(int u){
    for(auto q:queries[u]){
        ans[q.id] = bit.query(q.l,q.r);
    }
    for(auto e:adj[u]){
        int old_val = actval[e.idx];
        actval[e.idx] = e.val;
        bit.add(e.idx, e.val-old_val);
        dfs(e.to);
        bit.add(e.idx, old_val-e.val);
        actval[e.idx] = old_val;
    }
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    int qcnt=0;
    for(int i=1;i<=q;i++){
        int type;
        cin>>type;
        if(type==1){
            ll x,y;
            cin>>x>>y;
            cur_ver[x] = cur_ver[y];
        }
        else if (type==2){
            int x,idx,val;
            cin>>x>>idx>>val;
            int newver = ++node_cnt;
            adj[cur_ver[x]].push_back({newver,idx,val});
            cur_ver[x] = newver;
        }
        else{
            int x,l,r;
            cin>>x>>l>>r;
            qcnt++;
            queries[cur_ver[x]].push_back({qcnt, l, r});
        }
    }
    dfs(0);
    for(int i=1;i<=qcnt;i++){
        cout << ans[i] << '\n';
    }
}