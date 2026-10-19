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
    vi a(n+1),b(n+1);
    int sumA=0,sumB=0;
    REP(i,1,n+1) {
        cin>>a[i]>>b[i];
        sumA+=a[i];
        sumB+=b[i];
    }
    vpii dp(sumB+1,{-INF,0});// dp[j] = 容量為j的狀況下最少數量及最少搬運次數
    dp[0] = {0,0};
    REP(i,1,n+1){
        RREP(j,sumB,b[i]){
            auto p = dp[j-b[i]];
            if(p.f==-INF) continue;
            p.f-=1;
            p.s+=a[i];
            if(p>dp[j]) dp[j] = p;
        }
    }
    pii best={-INF,0};
    REP(i,sumA,sumB+1){
        if(dp[i].f==-INF) continue;
        if(best<dp[i]) best = dp[i];
    }
    cout << -best.f << ' ' << sumA-best.s << '\n';
}
/*
?? 複習
*/