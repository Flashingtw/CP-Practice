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
const int N = 1e8;
bool isP[N+1];

void init(){
    for(int i=2;1LL*i*i<=N;i++){
        if(isP[i]) continue;
        for(ll j=1LL*i*i;j<=N;j+=i){
            isP[j]=1;
        }
    }
    isP[0]=isP[1]=1;
}
int rnk[26];
int used[10];
string s;
int nnn;
bool chk;
void dfs(int n,int cur){
    if(chk) return;
    if(n==nnn){
        if(isP[cur]) return;
        chk=1;
        cout << cur << '\n';
        return;
    }
    int idx = (s[n]-'a');
    if(rnk[idx]>=0){
        cur*=10;
        cur+=rnk[idx];
        dfs(n+1,cur);
        return;
    }
    for(int i=(n==0?1:0);i<=9;i++){
        if(used[i]) continue;
        used[i]=1;
        rnk[idx]=i;
        dfs(n+1,cur*10+i);
        used[i]=0;
        rnk[idx]=-1;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s;
    nnn = SZ(s);
    init();
    REP(i,0,26) rnk[i] = -1;

    dfs(0,0);
    if(!chk) cout << -1 << '\n';
}