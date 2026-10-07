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
struct eve{
    int t,x;
};
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n>>q;
    vi a(n+1);
    vector<vector<eve>> e(n+1);
    REP(cnt,0,q){
        int l,r,x;
        cin>>l>>r>>x;
        e[l].push_back({1,x});
        e[r].push_back({-1,x});
    }
    multiset<int> ms;
    set<int> s;
    for(int i=1;i<=n;i++){
        EACH(x,e[i]){
            if(x.t==1){
                ms.insert(x.x);
                s.insert(x.x);
            }
        }
        cout << s.size() << ' ';
        EACH(x,e[i]){
            if(x.t==-1){
                ms.erase(ms.find(x.x));
                if(ms.find(x.x)==ms.end()){
                    s.erase(s.find(x.x));
                }
            }
        }
    }
}