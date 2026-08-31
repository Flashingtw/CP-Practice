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
int d[30];
map<int,int> used;
int n;
int ans = 30;
void dfs(int idx,int cur,int cnt){
    if(idx==n){
        ans = min(ans,cnt);
        return;
    }
    int r = cur+d[idx];
    used[r]++;
    if(cnt+(used[r]==1)<ans) dfs(idx+1,r,cnt+(used[r]==1));
    used[r]--;
    int l = cur-d[idx];
    used[l]++;
    if(cnt+(used[l]==1)<ans) dfs(idx+1,l,cnt+(used[l]==1));
    used[l]--;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    rep(i,0,n) cin>>d[i];
    used[0]++;
    dfs(0,0,1);
    cout << ans << '\n';
}