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
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int INF = 1e9+9;
const ll LINF = 1e18+9;
int n,c,d,q,T;

int chk(int a){
    if(a<c) return 0;
    if(a>=c+d) return 2;
    return 1;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>c>>d>>q>>T;
    vector<int> a(n+1,-1);
    int cnt[3] = {};
    while(q--){
        int x,t;
        cin>>x>>t;
        if(a[x]==-1){
            a[x]=t;
        }
        else{
            cnt[chk(t-a[x])]++;
            a[x]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=-1){
            cnt[chk(T-a[i])]++;
        }
    }
    for(int i=0;i<3;i++){
        cout << cnt[i] << ' ';
    }
}