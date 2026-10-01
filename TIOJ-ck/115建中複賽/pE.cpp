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
ll g[505][505];
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<vl> dist(n+1,vl(n+1));
    REP(i,1,n+1){
        REP(j,1,n+1){
            cin>>g[i][j];
            dist[i][j] = g[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<vi> ans(n+1,vi(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) {
                continue;
            }
            if(dist[i][j]<g[i][j]){
                ans[i][j]=1;
                continue;
            }
            for(int k=1;k<=n;k++){
                if(k==j||k==i) continue;
                if(g[i][k]+dist[k][j]==dist[i][j]){
                    ans[i][j]=1;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout << ans[i][j];
        cout << '\n';
    }
}