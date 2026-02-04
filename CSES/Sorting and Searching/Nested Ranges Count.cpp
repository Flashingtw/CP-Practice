#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct L{
    int x,y,id;
};
struct BIT{
    int sz;
    vector<ll> tree;
    BIT(int _sz) : sz(_sz) ,tree(_sz,0){};
    void update(int idx){
        for(;idx<=sz;idx+= idx&-idx) tree[idx]++;
    }
    int query(int idx){
        ll s=0;
        for(;idx>0;idx-=idx&-idx){
            s+=tree[idx];
        }
        return s;
    }
};
int main(){
    int n;
    cin>>n;
    vector<L> v(n);
    vector<int> rk;
    for(int i=0;i<n;i++){
        cin>>v[i].x>>v[i].y;
        rk.push_back(v[i].x);
        rk.push_back(v[i].y);
        v[i].id=i;
    }
    sort(rk.begin(),rk.end());
    rk.erase(unique(rk.begin(),rk.end()),rk.end());
    sort(v.begin(),v.end(),[](L &a,L &b){return a.x!=b.x?a.x<b.x:a.y>b.y;});
    vector<int> inc(n),be_inc(n);
    BIT bit(rk.size()+1);
    for(int i=n-1;i>=0;i--){
        int rk_y = lower_bound(rk.begin(),rk.end(),v[i].y)-rk.begin();
        inc[v[i].id] = bit.query(rk_y);
        bit.update(rk_y);
    }
    BIT bit2(rk.size()+1);
    for(int i=0;i<n;i++){
        int rk_y = lower_bound(rk.begin(),rk.end(),v[i].y)-rk.begin();
        be_inc[v[i].id] = bit2.query(rk.size())-bit2.query(rk_y-1);
        bit2.update(rk_y);
    }
    for(int i:inc) cout << i << " ";
    cout << "\n";
    for(int i:be_inc) cout << i << " ";
}