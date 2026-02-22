#include <bits/stdc++.h>
using namespace std;
const int N = 270005;
int n,K;
int tree[N];

void update(int idx,int val){
    for(;idx<=n;idx+= idx&-idx){
        tree[idx]+=val;
    }
}
int query(int k){
    int pos=0;
    for(int step=(2<<17);step>0;step>>=1){
        int next_pos = pos+step;
        if(next_pos<=n&&tree[next_pos]<k){
            pos = next_pos;
            k = k-tree[next_pos];
        }
    }
    return pos+1;
}

int main() {
    cin>>n>>K;
    for(int i=1;i<=n;i++){
        update(i,1);
    }
    int rem=n,p=0;
    for(int i=1;i<=n;i++){
        p = (p+K)%rem;
        int ans = query(p+1);
        cout << ans << " ";
        update(ans,-1);
        rem--;
    }
}