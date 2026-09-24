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
    string s;
    cin>>s;
    map<char,int> in;
    char imp = s[0];
    for(auto c:s){
        in[c]++;
    }
    int n;
    cin>>n;
    REP(i,0,n){
        map<char,int> mp;
        string t;
        cin>>t;
        int typ=0;
        bool chkk=0;
        for(char c:t){
            if(c==imp) chkk=1;
            if(in[c]==0) {
                typ=1;
                break;
            }
            mp[c]++;
        }
        if(t.size()<4||typ||!chkk){
            cout << "Invalid" << '\n';
            continue;
        }
        bool chk=1;
        for(auto a:s){
            if(mp[a]==0){
                chk=0;
                break;
            }
        }
        if(chk) cout << "Pangram" << '\n';
        else cout << "Valid" << '\n';
    }
}