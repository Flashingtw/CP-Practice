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
int dp[10005];
int a[105];
int n,k;

int f(int i){
    if(dp[i]!=-1) return dp[i];
    REP(j,0,k){
        if(a[j]>i) break;
        dp[i] = max(dp[i],i-f(i-a[j]));
    }
    return dp[i];
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k;
    REP(i,0,k) cin>>a[i];
    REP(i,1,n+1){
        dp[i] = -1;
    }

    cout << f(n) << '\n';
}