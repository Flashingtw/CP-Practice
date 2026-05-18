#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 5e5+5;

int prv_n[N],nxt_n[N];
int isin[N];

void init(int x,int prv,int nxt,int ins){
    prv_n[x] = prv;
    nxt_n[x] = nxt;
    isin[x] = ins;
}

//idx 插到 x 後面
void insert(int x,int idx){
    int nxt = nxt_n[x];
    init(idx,x,nxt,1);
    prv_n[nxt] = idx;
    nxt_n[x] = idx;
}

void del(int x){
    int prv = prv_n[x];
    int nxt = nxt_n[x];
    prv_n[nxt] = prv;
    nxt_n[prv] = nxt;
    isin[x] = 0;
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    init(0,0,0,1);
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            insert(prv_n[i],i+1);
        }
        else{
            insert(i,i+1);
        }
    }
    int cur=0;
    if(s[0]=='R') cout << 0 << ' ';
    while(1){
        cur = nxt_n[cur];
        if(cur==0) break;
        cout << cur << ' ';
    }
    if(s[0]=='L') cout << 0 << ' ';
}