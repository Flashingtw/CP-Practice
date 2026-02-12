#include <bits/stdc++.h>
using namespace std;

struct BIT{
    vector<int> v;
    int sz;
    BIT(int _sz) : sz(_sz),v(_sz+1,0){};
    void add(int idx,int val){
        for(;idx<=sz;idx+=idx&-idx) v[idx]^=val;
    }
    int query(int idx){
        int res=0;
        for(;idx>0;idx-=idx&-idx){
            res ^= v[idx];
        }
        return res;
    }
};

int main(){
    int n,q;
    cin>>n>>q;
    BIT bit(n);
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        bit.add(i,num);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout << (bit.query(b)^bit.query(a-1)) << "\n";
    }
}