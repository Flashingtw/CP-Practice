#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int a[400005];
int ed[400005];
struct pr{
    int s,t;
    bool operator<(const pr &oth){
        return t<oth.t;
    }
};
pr v[200005];
int find(int x){
    if(a[x]==x) return x;
    return a[x] = find(a[x]);
}
int readint(){
    int res = 0;
    char c = getchar_unlocked();
    while(c>='0'&&c<='9'){
        res = res*10+(c-'0');
        c = getchar_unlocked();
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n=readint();
    int k=readint();
    for(int i=0;i<n;i++){
        v[i].s=readint();
        v[i].t=readint();
    }
    sort(v,v+n);
    int cur=k+1;
    for(int i=1;i<=k;i++) a[i]=i;
    int ans=0;
    for(int i=0;i<n;i++){
        int idx = upper_bound(ed+1,ed+cur,v[i].s)-ed-1;
        int act = find(idx);
        if(act<=0) continue;
        a[act]=act-1;
        a[cur]=cur;
        ed[cur]=v[i].t;
        ans++,cur++;
    }
    cout << ans << '\n';
}
