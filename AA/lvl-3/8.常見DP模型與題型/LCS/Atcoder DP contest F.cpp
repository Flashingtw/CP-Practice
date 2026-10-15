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
    string s,t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    s = "_"+s;
    t = "_"+t;
    vvi dp(n+1,vi(m+1));
    REP(i,1,n+1){
        REP(j,1,m+1){
            dp[i][j] = max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+(s[i]==t[j])});
        }
    }
    int i = n,j = m;
    string ans;
    while(i>0&&j>0){
        if(s[i]==t[j]&&dp[i][j]==dp[i-1][j-1]+1){
            ans.push_back(s[i]);
            i--;
            j--;
        }
        else if(dp[i][j]==dp[i-1][j]) i--;
        else j--;
    }
    reverse(ALL(ans));
    cout << ans << '\n';
}