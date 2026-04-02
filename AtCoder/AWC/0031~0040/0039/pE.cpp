#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e5+5;
ll val[N];
struct BIT{
    vector<ll> tree;
    int sz;
    BIT(int _sz){
        sz=_sz+1;
        tree.resize(_sz+1,0);
    }
    void update(int idx,int val){
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
struct e{
    int l,r,t,id;
    bool operator<(const e o) const{
        return t>o.t;
    }
};
int main(){
    int n,m,q,k;
    cin>>n>>m>>q>>k;
    vector<pii> book(m);
    for(int i=0;i<m;i++){
        cin>>book[i].second>>book[i].first;
    }
    vector<e> qu(q);
    for(int i=0;i<q;i++){
        cin>>qu[i].l>>qu[i].r>>qu[i].t;
        qu[i].id=i;
    }
    sort(book.begin(),book.end(),greater<pii>());
    sort(qu.begin(),qu.end());
    int j=0;
    BIT bit(n);
    vector<int> ans(q);
    for(int i=0;i<q;i++){
        while(j<m&&book[j].first>=qu[i].t){
            bit.update(book[j].second,1);
            j++;
        }
        ans[qu[i].id] = max(0LL,bit.query(qu[i].l,qu[i].r)-k);
    }
    for(int i=0;i<q;i++){
        cout << ans[i] << '\n';
    }
}