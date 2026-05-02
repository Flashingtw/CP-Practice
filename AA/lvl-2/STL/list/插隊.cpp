#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;

int prv_n[N],nxt_n[N];

void init(int idx,int prv,int nxt){
    prv_n[idx]=prv;
    nxt_n[idx]=nxt;
}

// idx 插到 x 後面
void insert(int x,int idx){
    int nxt = nxt_n[x];
    init(idx,x,nxt);
    nxt_n[x] = idx;
    prv_n[nxt] = idx;
}

void del(int idx){
    prv_n[nxt_n[idx]] = prv_n[idx];
    nxt_n[prv_n[idx]] = nxt_n[idx];
}

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        insert(i-1,i);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        del(b);
        insert(prv_n[a],b);
    }
    int cur = 0;
    while(1){
        cur = nxt_n[cur];
        if(cur==0) break;
        cout << cur << '\n';
    }
}