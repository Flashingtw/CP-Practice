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
    vs a(n);
    REP(i,0,n) cin>>a[i];
    unordered_map<string,ll> mp;
    for(auto &ss:a){
        mp[ss]++;
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                string s;
                if(j==i) s.push_back('1');
                else s.push_back('2');
                s.push_back('0'+i);
                s.push_back('0'+j);
                for(int k=0;k<m;k++){
                    if(!(k==i||k==j)){
                        s.push_back(ss[k]);
                    }
                }
                mp[s]++;
            }
        }
    }
    ll c0=0,c1=0,c2=0;
    for(auto [f,s]:mp){
        ll cnt = s*(s-1)/2;
        if(f[0]=='1'){
            c1 += cnt;
        }
        else if(f[0]=='2'){
            c2 += cnt;
        }
        else{
            c0 += cnt;
        }
    }
    cout << c2-(m-2)*c1+(1+m*(m-3)/2)*c0 << '\n';
}