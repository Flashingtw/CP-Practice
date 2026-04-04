#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,q;
ll tree[N],v[N];
void update(int idx,int val){
    for(;idx<=n;idx+= idx&-idx){
        tree[idx]+=val;
    }
}
ll query(int idx){
    ll sum=0;
    for(;idx>0;idx-= idx&-idx){
        sum+=tree[idx];
    }
    return sum;
}

int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        update(i,v[i]);
    }
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int x;
            cin>>x;
            update(x+1,-v[x+1]);
            update(x,v[x+1]);
            
            update(x+1,v[x]);
            update(x,-v[x]);

            swap(v[x],v[x+1]);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout << (query(r)-query(l-1)) << '\n';
        }
    }
}