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

set<string> st;

int used[10];
int n,m;
string ans;
vector<string> s;

void dfs(int cur,vector<int> &v){
    if(cur==n){
        string str = s[v[0]];
        for(int i=1;i<n;i++){
            str.push_back('_');
            str+=s[v[i]];
        }
        if(st.find(str)==st.end()) ans=str;
        return;
    }
    for(int i=0;i<n;i++){
        if(used[i]) continue;
        v.push_back(i);
        used[i]=1;
        dfs(cur+1,v);
        v.pop_back();
        used[i]=0;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    rep(i,0,n){
        string a;
        cin>>a;
        s.push_back(a);
    }
    rep(i,0,m){
        string a;
        cin>>a;
        st.insert(a);
    }
    vector<int> v;
    dfs(0,v);
    cout << (ans.empty()?"-1":ans) << '\n';
}