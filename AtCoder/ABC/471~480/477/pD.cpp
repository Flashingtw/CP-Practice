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
    int n,q;
    cin>>n>>q;
    vector<char> ans(n+1,'a');
    vi cvr(n+1);
    vi time(n+1);
    char cur='a';
    int last=0;
    int tmr=0;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            if(cvr[x]==1){
                cvr[x]=0;
                time[x]=tmr+1;
            }
            else{
                if(last>time[x]) ans[x]=cur;
                cvr[x]=1;
            }
        }
        else{
            char c;
            cin>>c;
            cur = c;
            last=tmr+1;
        }
        tmr++;
    }
    for(int i=1;i<=n;i++){
        if(cvr[i]==1){
            cout << ans[i];
        }
        else{
            if(last<time[i]) cout << ans[i];
            else cout << cur;
        }
    }
}