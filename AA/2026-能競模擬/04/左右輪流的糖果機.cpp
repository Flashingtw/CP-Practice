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

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    ll m;
    cin>>n>>m;
    vi a(n);
    REP(i,0,n) cin>>a[i];
    deque<ll> dq;
    REP(i,0,n) dq.push_back(i);
    vl cur(n);
    int cnt=1;
    while(m>0){
        if(m==1){
            m--;
            cur[dq.front()]++;
        }
        ll mid = m/2;
        int r = dq.back();
        int l = dq.front();
        ll d=0;
        if(a[r]-cur[r]>a[l]-cur[l]) d=a[l]-cur[l];
        else d=a[r]-cur[r];
        d = min(d,mid);
        cur[r]+=d; m-=d;
        if(r!=l) {
            cur[l]+=d;
            m-=d;
        }

        if(cur[dq.front()]==a[dq.front()]) dq.pop_front();
        if(cur[dq.back()]==a[dq.back()]) dq.pop_back();
        
        cnt++;
    }
    REP(i,0,n) cout << cur[i] << ' ';
}