#include <bits/stdc++.h>
using namespace std;
#define lb(x) (x&-x)
const int N = 200005;
struct BIT{
    long long tree[N];
    int sz;
    BIT(int _sz){
        sz =_sz;
        fill(tree,tree+sz+1,0);
    }
    long long query(int idx){
        long long sum=0;
        for(;idx>0;idx-=lb(idx)){
            sum+=tree[idx];
        }
        return sum;
    }
    void update(int idx,long long val){
        for(;idx<=sz;idx+=lb(idx)){
            tree[idx]+=val;
        }
    }
};
//static Range Sum Queries
int main(){
    int n,q;
    cin>>n>>q;
    BIT bt(n);
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        bt.update(i,num);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout << (bt.query(b)-bt.query(a-1)) << "\n";
    }
}