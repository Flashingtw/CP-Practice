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

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vpll a(n+1);
    REP(i,1,n+1) cin>>a[i].f>>a[i].s;
    int q;
    cin>>q;
    vi query(q);
    REP(i,0,q) cin>>query[i];
    ll MAX = *max_element(ALL(query));

    vector<vector<ll>> dp(n+1,vl(MAX+1));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(MAX,a[i].f);j++){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=a[i].f;j<=MAX;j++){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i].f]+a[i].s);
        }
    }
    EACH(qu,query){
        string s;
        int cur=qu;
        for(int i=n;i>0;i--){
            if(cur-a[i].f>=0&&dp[i][cur]==dp[i-1][cur-a[i].f]+a[i].s){
                s.push_back('1');
                cur-=a[i].f;
            }
            else{
                s.push_back('0');
            }
        }
        reverse(ALL(s));
        cout << s << '\n';
    }
}