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
const int N = 2e5+5;
//到idx前選出c個
int n,k,tar;
bool rev;
ll all,ans,a[N];
void dfs(int idx,int c,ll cur){
    if(c==tar){
        if(rev){
            ans = max(ans,all^cur);
        } 
        else ans = max(ans,cur);
        return;
    }
    if(idx==n) return;
    for(int i=idx;i<n;i++){
        dfs(i+1,c+1,cur^a[i]);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k;
    rep(i,0,n) {
        cin>>a[i];
        all^=a[i];
    }
    tar=k;
    if(k>n-k){
        tar=n-k;
        rev=1;
    }
    dfs(0,0,0);
    cout << ans << '\n';
}
/*
重點:
k太小時:選擇比較少
k太大時:選 (沒被選過) 的比較好
*/