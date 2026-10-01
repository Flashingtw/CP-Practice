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

struct eve{
    ll s,e,w;
    bool operator<(const eve &oth) const{
        return e<oth.e;
    }
};

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<eve> a(n);
    REP(i,0,n){
        cin>>a[i].s>>a[i].e>>a[i].w;
    }
    vl ed(n);
    sort(ALL(a));
    REP(i,0,n) ed[i] = a[i].e;
    vl dp(n);
    dp[0] = a[0].w;
    REP(i,1,n){
        int j = lower_bound(ed.begin(),ed.begin()+i,a[i].s)-ed.begin()-1;
        if(j==-1){
            dp[i] = max(dp[i-1],a[i].w);
            continue;
        }
        dp[i] = max(dp[i-1],a[i].w+dp[j]);
    }
    cout << dp[n-1] << '\n';
}
/*
j == -1 特判
*/