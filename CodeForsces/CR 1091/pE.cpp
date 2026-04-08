#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
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
bool solve(){
    int n;
    cin>>n;
    vector<int> p(n+1);
    vector<int> d(n+1);
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>d[i];
    vector<int> mxd(n+1);
    BIT bit(n);
    for(int i=n;i>=1;i--){
        mxd[i] = bit.query(p[i],n);
        bit.update(p[i],1);
    }
    vector<int> q;
    for(int i=n;i>=1;i--){
        if(mxd[i]<d[i]){
            return false;
        }
        int sz=q.size();
        bool ins=0;
        int cnt=0;
        for(int j=0;j<sz;j++){
            int c = q[j];
            if(p[c]>p[i]) cnt++;
            if (cnt==mxd[i]-d[i]+1){
                q.insert(q.begin()+j,i);
                ins=1;
                break;
            }
        }
        if(!ins) q.push_back(i);
    }
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++){
        ans[q[i-1]]=i;
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        if(!solve()){
            cout << -1 << '\n';
        }
    }
}