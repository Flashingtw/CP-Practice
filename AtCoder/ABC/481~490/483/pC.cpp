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
    int n,m;
    cin>>n>>m;
    vvi adj(n+1);
    vi cnt(n+1);
    priority_queue<vi> pq;
    REP(i,0,m){
        int a,b;
        cin>>a>>b;
        cnt[a]++;
        adj[a].push_back(b);
        pq.push({cnt[a],-a,INF});
    }
    
    vi used(n+1);
    for(int k=1;k<=n;k++){
        vi cur;
        for(int v:adj[k]){
            cnt[v]++;
            if(!used[v]){
                used[v]++;
                cur.push_back(v);
            }
        }
        for(int v:cur){
            pq.push({cnt[v],-v,k});
        }
        vvi curr;
        while(-pq.top()[1]==k||pq.top()[2]<k){
            curr.push_back(pq.top());
            pq.pop();
        }

        cout << -pq.top()[1] << '\n';
        
        for(int v:adj[k]){
            cnt[v]--;
            used[v]=0;
        }
        for(auto &v:curr){
            if(v[2]>k){
                pq.push(v);
            }
        }
    }
}