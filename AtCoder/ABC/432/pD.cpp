#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct rect{
    ll xl,xr,yl,yr;
};
struct DSU{
    vector<ll> sz,p;
    void init(int _sz){
        sz.resize(_sz+1);
        p.resize((_sz+1));
        iota(p.begin(),p.end(),0);
    }
    ll fnd(int x){
        if(p[x]==x) return x;
        return p[x] = fnd(p[x]);
    }
    void merge(int i,int j){
        ll rootx = fnd(i);
        ll rooty = fnd(j);
        if(rootx==rooty) return;
        p[rootx] = rooty;
        sz[rooty] += sz[rootx];
    }
};
vector<rect> cur;
bool chk(int i,int j){
    rect a = cur[i],b=cur[j];
    bool x = max(a.xl,b.xl) <= min(a.xr,b.xr);
    bool y = max(a.yl,b.yl) <= min(a.yr,b.yr);

    bool xadj = (a.xr+1==b.xl)||(b.xr+1==a.xl);
    bool yadj = (a.yr+1==b.yl)||(b.yr+1==a.yl);
    return (x&yadj)||(y&xadj);
}
int main(){
    ll n,x,y;
    cin>>n>>x>>y;
    cur.push_back({0,x-1,0,y-1});
    for(int cnt=0;cnt<n;cnt++){
        char c;
        ll A,B;
        cin>>c>>A>>B;
        vector<rect> temp;
        for(auto [xl,xr,yl,yr]:cur){
            if(c=='X'){
                if(xr<A){
                    temp.push_back({xl,xr,yl-B,yr-B});
                }
                else if(xl>=A){
                    temp.push_back({xl,xr,yl+B,yr+B});
                }
                else{
                    temp.push_back({xl,A-1,yl-B,yr-B});
                    temp.push_back({A,xr,yl+B,yr+B});
                }
            }
            else{
                if(yr<A){
                    temp.push_back({xl-B,xr-B,yl,yr});
                }
                else if(yl>=A){
                    temp.push_back({xl+B,xr+B,yl,yr});
                }
                else{
                    temp.push_back({xl-B,xr-B,yl,A-1});
                    temp.push_back({xl+B,xr+B,A,yr});
                }
            }
        }
        cur = temp;
    }
    DSU dsu;
    dsu.init(cur.size());
    for(int i=0;i<cur.size();i++){
        auto [xl,xr,yl,yr] = cur[i];
        dsu.sz[i] = (xr-xl+1)*(yr-yl+1);
    }
    for(int i=0;i<cur.size();i++){
        for(int j=i+1;j<cur.size();j++){
            if(chk(i,j)){
                dsu.merge(i,j);
            }
        }
    }
    vector<bool> check(cur.size(),0);
    vector<ll> sz;
    for(int i=0;i<cur.size();i++){
        if(!check[dsu.fnd(i)]){
            sz.push_back(dsu.sz[dsu.fnd(i)]);
            check[dsu.fnd(i)]=1;
        }
    }
    sort(sz.begin(),sz.end());
    cout << sz.size() << "\n";
    for(ll i:sz) cout << i << " ";  
}