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
    vector<vi> a(n,vi(4));
    REP(i,0,n){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        a[i][3] = i+1;
    }
    sort(ALL(a));
    vi dp(n+1);
    vi p(n+1);
    for(int i=0;i<n;i++){
        dp[i] = a[i][2];
        p[i] = i;
        for(int j=0;j<i;j++){
            if(a[j][1]<a[i][0]&&dp[j]+a[i][2]>dp[i]) {
                dp[i] = dp[j]+a[i][2];
                p[i] = j;
            }
        }
    }
    int cur=-1;
    int mx=-1;
    for(int i=0;i<n;i++){
        if(dp[i]>mx){
            mx = dp[i];
            cur = i;
        }
    }
    vi ans;
    while(1){
        ans.push_back(a[cur][3]);
        if(cur==p[cur]) break;
        cur = p[cur];
    }
    reverse(ALL(ans));
    cout << mx << ' ' << ans.size() << '\n';
    EACH(x,ans) cout << x << ' ';
}
/*
沒定義清楚dp狀態
*/