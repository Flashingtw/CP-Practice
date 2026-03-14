#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 1e9+9;
const int N = 5e5+5;
int v[N],cnt[N],s_cnt[N],pref[N];
int n,m;
ll S(ll c){
    ll idx = upper_bound(s_cnt+1,s_cnt+m+1,c)-(s_cnt+1);
    return (idx*c)-pref[idx];
}

struct BIT{
    vector<ll> tree;
    int sz;
    void init(int _sz){
        sz=_sz;
        tree.assign(_sz+1,0);
    }
    void update(int idx,ll val){
        for(;idx<=sz;idx+= idx&-idx){
            tree[idx]+=val;
        }
    }
    ll q(int idx){
        ll sum=0;
        for(;idx>0;idx-= idx&-idx){
            sum+=tree[idx];
        }
        return sum;
    }
};

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        cnt[v[i]]++;
    }
    for(int i=1;i<=m;i++) s_cnt[i] = cnt[i];
    sort(s_cnt+1,s_cnt+m+1);
    pref[0] = 0;
    for(int i=1;i<=m;i++){
        pref[i] = pref[i-1]+s_cnt[i];
    }

    int q;
    cin>>q;
    vector<pii> query(q);
    vector<int> ans(q);
    for(int i=0;i<q;i++){
        cin>>query[i].first;
        query[i].second=i;
    }
    sort(query.begin(),query.end());

    vector<pii> freq(m+1);
    for(int i=1;i<=m;i++) freq[i] = {cnt[i],i};
    sort(freq.begin()+1,freq.end());
    int ptr=1;
    BIT bit;
    bit.init(m+1);
    for(int i=0;i<q;i++){
        ll x = query[i].first;
        int id = query[i].second;
        if(x>n){
            ll k = x-n;
            ll l=0,r=(2e18)/m+500000;
            ll rem;
            while(l<=r){
                ll mid = (l+r)/2;
                if(S(mid)<k){
                    rem=mid;
                    l = mid+1;
                }
                else r = mid-1;
            }
            ll cur = rem;
            rem = k-S(rem);
            while(ptr<=m&&freq[ptr].first<=cur){
                bit.update(freq[ptr].second,1);
                ptr++;
            }
            l=1,r=m;
            while(l<=r){
                int mid = (l+r)/2;
                if(bit.q(mid)>=rem){
                    ans[id]=mid;
                    r= mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        }
        else{
            ans[id] = v[x];
        }
    }
    for(int i=0;i<q;i++){
        cout << ans[i] << '\n';
    }
}