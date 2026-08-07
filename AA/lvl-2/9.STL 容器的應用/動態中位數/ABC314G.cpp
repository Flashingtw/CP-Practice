#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i=a;i<b;++i)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<double,double> pdd;
typedef pair<char,int> pci;
typedef pair<int,char> pic;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int INF = 1e9+9;
const ll LINF = 1e18+9;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,h;
    cin>>n>>m>>h;
    vector<pli> v(n);
    rep(i,0,n) cin>>v[i].F>>v[i].S;
    vector<ll> cur(m+1);
    multiset<ll> l,r;//l擋傷害,r受傷害
    ll tr=0;
    vector<int> as(n+1);
    rep(i,0,n){
        ll d = v[i].F;
        int t = v[i].S;
        if(l.find(cur[t])!=l.end()){
            l.erase(l.find(cur[t]));
        }
        else if(r.find(cur[t])!=r.end()){
            r.erase(r.find(cur[t]));
            tr-=cur[t];
        }
        cur[t]+=d;
        tr+=cur[t];
        r.insert(cur[t]);
        if(!l.empty()&&!r.empty()&&*r.rbegin()>*l.begin()){
            ll mx = *r.rbegin();
            ll mn = *l.begin();
            tr = tr-mx+mn;
            r.insert(mn);
            l.insert(mx);
            r.erase(r.find(mx));
            l.erase(l.begin());
        }
        while(tr>=h){
            ll mx = *r.rbegin();
            r.erase(r.find(mx));
            tr-=mx;
            l.insert(mx);
        }
        while(!l.empty()&&tr+*l.begin()<h){
            ll mn = *l.begin();
            r.insert(mn);
            tr+=mn;
            l.erase(l.begin());
        }
        as[i]=l.size();
    }
    vector<int> ans(m+1);
    rep(i,0,n){
        ans[as[i]]=max(ans[as[i]],i+1);
    }
    rep(i,1,m+1){
        ans[i] = max(ans[i-1],ans[i]);
    }
    for(int i:ans) cout << i << ' ';
}
//利用類似動態中位數的作法做此題