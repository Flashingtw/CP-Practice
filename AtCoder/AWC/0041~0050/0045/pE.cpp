#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int LOG = 20;
const int N = 5e5+5;
ll val[N];
ll st[N][LOG];
int n;
void build(){
    for(int i=1;i<=n;i++) st[i][0]=val[i];
    for(int j=1;j<LOG;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r){
    if(r==-1) return 0;
    int lg=__lg(r-l+1);
    return min(st[l][lg],st[r-(1<<lg)+1][lg]);
}
int main(){
    ll w,k;
    cin>>n>>w>>k;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    build();
    ll cur=0;
    for(int i=1;i<w;i++){
        cur+=val[i];
    }
    int l=1;
    ll mx=-1e18;
    for(int r=w;r<=n;r++){
        cur+=val[r];
        mx = max(mx,cur+k*query(l,r));
        cur-=val[l];
        l++;
    }
    cout << mx;
}