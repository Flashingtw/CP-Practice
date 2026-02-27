#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct BIT{
    vector<int> tree;
    int sz;
    BIT(int _sz) :tree(_sz+1,0),sz(_sz+1) {};
    void update(int idx,int val){
        for(;idx<=sz;idx+= idx&-idx){
            tree[idx]+=val;
        }
    }
    int query(int idx){
        int sum=0;
        for(;idx>0;idx-=idx&-idx){
            sum+=tree[idx];
        }
        return sum;
    }
};
struct qu{
    int l,r,id;
};
int main(){
    int n,query;
    cin>>n>>query;
    vector<int> v(n+1);
    vector<qu> q(query);
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=0;i<query;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q.begin(),q.end(),[&](qu &a,qu &b){return a.r<b.r;});
    BIT bit(n+1);
    vector<int> last_pos(n+1,0),ans(query);
    int j=0;
    for(int i=1;i<=n;i++){
        int sp=v[i];
        if(last_pos[sp]!=0){
            bit.update(last_pos[sp],-1);
        }
        last_pos[sp]=i;
        bit.update(i,1);
        while(j<query&& i==q[j].r) {
            ans[q[j].id] = (bit.query(i) - bit.query(q[j].l-1));
            j++;
        }
    }
    for(int i:ans) cout << i << '\n';
}