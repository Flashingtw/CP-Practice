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
const ll mod = 998244353;
string s;

ll dp[5005][5005];

ll rec(int l,int r){
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    return dp[l][r] = max({rec(l+1,r),rec(l,r-1),rec(l+1,r-1)+(s[l]==s[r]?2:0)});
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s;
    int n = SZ(s);
    REP(i,0,n){
        REP(j,0,n){
            dp[i][j]=-1;
        }
    }
    REP(i,0,n){
        dp[i][i] = 1;
    }
    cout << rec(0,s.size()-1) << '\n';
}