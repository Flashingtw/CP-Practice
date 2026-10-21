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
int n;
int a[10];
int ans;

int strtoi(string s){
    int ans=0;
    int sz = SZ(s);
    RREP(i,sz-1,0){
        ans*=10;
        ans+=s[i]-'0';
    }
    return ans;
}

string itostr(int num){
    string s;
    while(num>0){
        s.push_back((num%10)+'0');
        num/=10;
    }
    reverse(ALL(s));
    return s;
}
void rec(int idx,int cur){
    if(idx==n){
        ans = max(ans,cur);
        return;
    }
    cur+=a[idx];
    string ans = itostr(cur);
    sort(ALL(ans));
    do{
        rec(idx+1,strtoi(ans));
    }while(next_permutation(ALL(ans)));
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    REP(i,0,n) cin>>a[i];
    rec(0,0);
    cout << ans << '\n';
}