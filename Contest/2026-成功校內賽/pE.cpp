#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define EB emplace_back
#define f first
#define s second
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SZ(x) (int)(x).size()
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define RREP(i,a,b) for(int i=(a);i>=(b);--i)
#define EACH(x,a) for(auto &x : a)

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
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;

const int INF = 1e9+9;
const ll LINF = (1LL<<62);
struct DSU{
    int sz;
    vi p;
    vl s;
    DSU(int _sz) : sz(_sz), p(_sz+1),s(_sz+1,1){
        iota(ALL(p),0);
    }
    int find(int x){
        if(p[x]==x) return x;
        return p[x] = find(p[x]);
    }
    ll merge(int x,int y){
        int rx = find(x);
        int ry = find(y);
        if(rx==ry) return 0;
        if(s[rx]>s[ry]) swap(rx,ry);
        p[rx] = ry;
        ll d = (1LL*s[ry]*(s[ry]-1)/2) + (1LL*s[rx]*(s[rx]-1)/2);
        s[ry] += s[rx];
        return 1LL*s[ry]*(s[ry]-1)/2-d;
    }
};

const int N = 2e5+5;
vi adj[N];
struct ev{
    int u,v,t;
    bool operator<(const ev &oth) const{
        return t>oth.t;
    }
};
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,Q;
    cin>>n>>m>>Q;
    vector<ev> edg;
    REP(i,0,m){
        int u,v,t;
        cin>>u>>v>>t;
        edg.push_back({u,v,t});
    }

    vpii q(Q);
    REP(i,0,Q) {
        cin>>q[i].f;
        q[i].s=i;
    }
    
    sort(ALL(q),greater());
    sort(ALL(edg));

    int ptr=0;
    vl ans(Q);

    ll cur=0;
    DSU dsu(n);
    REP(i,0,Q){
        while(ptr<m&&edg[ptr].t>q[i].f){
            auto [u,v,t] = edg[ptr];
            cur += dsu.merge(u,v);
            ptr++;
        }
        ans[q[i].s]=cur;
    }
    EACH(x,ans) cout << x << '\n';
}