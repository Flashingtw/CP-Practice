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
    priority_queue<int> pq;
    REP(i,0,n) {
        int a;
        cin>>a;
        pq.push(a);
    }
    bool chk=0;
    while(!pq.empty()){
        if(chk) break;

        int u = pq.top();
        pq.pop();
        if(pq.size()<u){
            chk=1;
            break;
        }
        vi v;
        for(int i=0;i<u;i++){       
            v.push_back(pq.top()-1);
            pq.pop();
        }
        EACH(x,v) {
            if(x==0) continue;
            if(x<0){
                chk=1;
                break;
            }
            pq.push(x);
        }
    }
    if(chk) cout << "No" << '\n';
    else cout << "Yes" << '\n';
}