#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i=a;i<b;++i)

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
set<string> ans;
string s;
int n;
int used[10];
void dfs(int idx,string &cur){
    if(idx==n){
        ans.insert(cur);
        return;
    }
    for(int i=0;i<n;i++){
        if(used[i]) continue;
        cur.push_back(s[i]);
        used[i]=1;
        dfs(idx+1,cur);
        cur.pop_back();
        used[i]=0;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s;
    n = sz(s);
    string a;
    dfs(0,a);
    cout << ans.size() << '\n';
    for(string i:ans) cout << i << '\n';
}