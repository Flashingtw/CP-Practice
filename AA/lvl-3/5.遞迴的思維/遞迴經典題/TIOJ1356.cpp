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
vpii ans;
void rec(int n,int from,int to){
    if((from==1&&to==3)||(from==3&&to==1)){
        rec(n,from,2);
        rec(n,2,to);
        return;
    }
    if(n==1){
        ans.push_back({from,to});
        return;
    }
    int oth = 6-from-to;
    rec(n-1,from,oth);
    ans.push_back({from,to});
    rec(n-1,oth,to);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    rec(n,1,3);
    int sz = sz(ans);
    for(int i=0;i<sz;i++){
        cout << '#' << i+1 << " : move the dish from " << '#' << ans[i].F << " to " << '#' << ans[i].S << '\n';
    }
}