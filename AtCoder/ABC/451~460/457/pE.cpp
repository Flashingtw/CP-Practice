#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
vector<pii> a[N];
vector<int> clo[N];
struct ln{
    int l,r,idx;
    bool operator<(const ln &a) const{
        if(l==a.l) return r<a.r;
        return l<a.l;
    }
};

struct BIT{
    int sz;
    vector<ll> tree;
    BIT (int _sz): sz(_sz+1),tree(_sz+1) {};
    void add(int idx,ll val){
        for(;idx<=sz;idx+= idx&-idx) tree[idx]+=val;
    }
    ll query(int idx){
        ll sum=0;
        for(;idx>0;idx-= idx&-idx){
            sum+=tree[idx];
        }
        return sum;
    }
    ll query(int l,int r){
        return query(r)-query(l-1);
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<ln> lnl(m),lnr;
    lnr.reserve(m);
    int i=0;
    for(auto &[l,r,idx]:lnl){
        cin>>l>>r;
        clo[r].push_back(l);
        idx=i++;
        lnr.push_back({r,l,idx});
    }
    sort(lnl.begin(),lnl.end());
    sort(lnr.begin(),lnr.end());
    int q;
    cin>>q;
    vector<int> ans(q,0);
    for(int i=0;i<q;i++){
        int s,t;
        cin>>s>>t;
        auto iA = upper_bound(lnl.begin(),lnl.end(),(ln){s,t,INF});
        auto iB = lower_bound(lnr.begin(),lnr.end(),(ln){t,s,INF});
        int idxL=-1,idxR=-1;
        if(iA!=lnl.begin()){
            iA = prev(iA);
            if(iA->l==s) idxL = iA->idx;
        }
        
        if (iB != lnr.end()&&iB->l==t) {
            idxR = iB->idx;
        }
        if(idxL==-1||idxR==-1){
            ans[i]=0;
        }
        else if(idxL==idxR){
            a[t].push_back({s,i});
        }
        else if(iA->r>=iB->r -1){
            ans[i]=1;
        }
        else ans[i]=0;
    }
    BIT bit(n+1);
    for(int i=1;i<=n;i++){
        for(int a:clo[i]){
            bit.add(a,1);
        }
        for(auto [s,idx]:a[i]){
            if(bit.query(s,i)>=2){
                ans[idx]=1;
            }
        }
    }
    for(int i=0;i<q;i++){
        if(ans[i]) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}