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

typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 1e9+9;
const int V = 60;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    REP(i,0,n) cin >> a[i];
    vector<array<int,V+1>> go(n+1);

    REP(i,0,n+1) go[i].fill(-1);
    
    REP(i,0,n) go[i][a[i]] = i+1;
    
    for(int x=2;x<=V;x++){
        REP(i,0,n){
            if(go[i][x] != -1) continue;
            int mid = go[i][x-1];
            if(mid==-1||mid>= n) continue;
            if(go[mid][x-1] != -1){
                go[i][x] = go[mid][x-1];
            }
        }
    }
    vi dp(n+1,INF);
    dp[0] = 0;
    REP(i,0,n){
        if(dp[i] == INF) continue;
        for(int x=1;x<=V;x++){
            int j = go[i][x];
            if(j != -1){
                dp[j] = min(dp[j],dp[i]+1);
            }
        }
    }

    cout << dp[n] << '\n';
}