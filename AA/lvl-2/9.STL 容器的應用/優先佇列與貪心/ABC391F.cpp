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
const int N = 2e5+5;
ll A[N],B[N],C[N];
ll f(vi v){
    ll a=A[v[0]];
    ll b=B[v[1]];
    ll c=C[v[2]];
    return a*b+b*c+c*a;
}
int dx[] = {1,0,0};
int dy[] = {0,1,0};
int dz[] = {0,0,1};
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k;
    cin>>n>>k;
    rep(i,0,n) cin>>A[i];
    rep(i,0,n) cin>>B[i];
    rep(i,0,n) cin>>C[i];
    sort(A,A+n,greater());
    sort(B,B+n,greater());
    sort(C,C+n,greater());
    using plv = pair<ll,vi>;
    priority_queue<plv> pq;
    set<vi> s;
    vi st = {0,0,0};
    s.insert(st);
    pq.push({f(st),st});
    for(int i=0;i<k-1;i++){
        auto [val,v] = pq.top();
        pq.pop();
        for(int d=0;d<3;d++){
            int nx = v[0]+dx[d],ny=v[1]+dy[d],nz=v[2]+dz[d];
            vi nxt = {nx,ny,nz};
            if(nx>=n||ny>=n||nz>=n||s.find(nxt)!=s.end()) continue;
            pq.push({f(nxt),nxt});
            s.insert(nxt);
        }
    }
    cout << pq.top().first << '\n';
}