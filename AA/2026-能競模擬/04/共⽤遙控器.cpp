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
struct state{
    pii b1,b2;
    int d=0;
};
int vis[25][25][25][25];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int h,w;
    cin>>h>>w;
    vvc g(h+2,vc(w+2,'#'));
    REP(i,1,h+1){
        REP(j,1,w+1){
            cin>>g[i][j];
        }
    }
    pii s1,s2,e1,e2;
    cin>>s1.f>>s1.s>>e1.f>>e1.s;
    cin>>s2.f>>s2.s>>e2.f>>e2.s;
    queue<state> q;
    q.push({s1,s2,0});
    vis[s1.f][s1.s][s2.f][s2.s] = 1;
    while(!q.empty()){
        auto [a,b,dis] = q.front();
        q.pop();
        if(a==e1&&b==e2){
            cout << dis << '\n';
            return 0;
        }
        for(int d=0;d<4;d++){
            pii nx1=a;
            pii nx2=b;
            nx1.f+=dx[d];
            nx1.s+=dy[d];
            nx2.f+=dx[d];
            nx2.s+=dy[d];
            if(g[nx1.f][nx1.s]=='#') nx1=a;
            if(g[nx2.f][nx2.s]=='#') nx2=b;
            if(vis[nx1.f][nx1.s][nx2.f][nx2.s]) continue;
            
            q.push({nx1,nx2,dis+1});
            vis[nx1.f][nx1.s][nx2.f][nx2.s]=1;
        }

    }
    cout << -1 << '\n';
}