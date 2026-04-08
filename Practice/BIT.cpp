#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
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
