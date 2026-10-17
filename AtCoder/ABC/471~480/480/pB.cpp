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
    vector<string> str(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++) cin>>str[i];
    REP(cnt,0,m){
        string a;
        cin>>a;
        int tar=-1;
        for(int j=0;j<n;j++){
            if(a==str[j]){
                tar=j;
            }
        }
        if(tar==-1){
            for(int j=0;j<n;j++){
                string s = str[j];
                if(a.size()!=s.size()){
                    continue;
                }
            
                int sz = SZ(s);
                bool chk=0;
                bool t=1;
                for(int i=0;i<sz;i++){
                    if(a[i]!=s[i]){
                        if(chk){
                            t=0;
                            break;
                        }
                        chk=1;
                    }
                }
            
                if(t){
                    if(tar==-1){
                        tar=j;
                    }
                    else {
                        tar=-1;
                        break;
                    }
                }
            }
        }
        if(tar!=-1) ans[tar]++;
    }
    for(int i=0;i<n;i++) cout << ans[i] << '\n';
}