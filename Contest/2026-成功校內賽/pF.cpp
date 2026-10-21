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
struct ev{
    int l,r;
    bool operator< (const ev oth) const{
        return r<oth.r;
    }
};
struct eve{
    int l,r,idx;
    bool operator< (const eve oth) const{
        return l<oth.l;
    }
};

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,c;
    cin>>n>>c;
    vector<ev> a(n);
    vector<eve> b(n);
    REP(i,0,n){
        cin>>a[i].l>>a[i].r;
    }
    sort(ALL(a));
    REP(i,0,n){
        b[i].l=a[i].l;
        b[i].r=a[i].r;
        b[i].idx=i;
    }
    sort(ALL(b));
    int i=0;
    int ans=0;
    priority_queue<pii,vpii,greater<pii>> pq;
    vi vis(n);
    int ptr=0;
    while(i<n){
        if(vis[i]) {
            i++;
            continue;
        }
        while(ptr<n&&b[ptr].l<=a[i].r){
            pq.push({b[ptr].r,b[ptr].idx});
            ptr++;
        }
        int cur=1;
        while(cur<=c&&!pq.empty()){
            int idx=pq.top().s;
            pq.pop();
            vis[idx]=1;
            cur++;
        }
        ans++;
    }
    cout << ans << '\n';
}