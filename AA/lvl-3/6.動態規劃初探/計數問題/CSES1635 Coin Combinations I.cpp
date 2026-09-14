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
const ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,x;
    cin>>n>>x;
    vector<ll> dp(x+1);
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(ALL(a));
    dp[0]=1;
    for(int i=0;i<=x;i++){
        for(int c:a){
            if(i+c>x) break;
            dp[i+c] = (dp[i+c] + dp[i])%mod;
        }
    }
    cout << dp[x] << '\n';
}