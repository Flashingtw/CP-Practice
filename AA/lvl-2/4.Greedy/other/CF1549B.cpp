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

void solve() {
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'&&t[i]=='1'){
            ans++;
            t[i]='0';
        }
        else if(i>0&&s[i-1]=='1'&&t[i]=='1'){
            ans++;
            t[i]='0',s[i-1]=='0';
        }
        else if(i<n&&s[i+1]=='1'&&t[i]=='1'){
            ans++;
            t[i]='0',s[i+1]=='0';
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}