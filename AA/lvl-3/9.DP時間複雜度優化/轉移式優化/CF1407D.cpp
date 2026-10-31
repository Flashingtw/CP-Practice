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
    cin>>n;
    vi a(n+1);
    REP(i,1,n+1) cin>>a[i];
    vi dp(n+1,INF);
    dp[1]=0;
    stack<int> st1,st2;
    st1.push(1);
    st2.push(1);
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+1;
        while(!st1.empty()&&a[st1.top()]<a[i]){
            dp[i] = min(dp[i],dp[st1.top()]+1);
            st1.pop();
        }
        while(!st2.empty()&&a[st2.top()]>a[i]){
            dp[i] = min(dp[i],dp[st2.top()]+1);
            st2.pop();
        }

        if(!st1.empty()) dp[i] = min(dp[i],dp[st1.top()]+1);
        if(!st2.empty()) dp[i] = min(dp[i],dp[st2.top()]+1);

        while(!st1.empty()&&a[st1.top()]==a[i]) st1.pop();
        while(!st2.empty()&&a[st2.top()]==a[i]) st2.pop();

        st1.push(i);
        st2.push(i);
    }
    cout << dp[n] << '\n';
}