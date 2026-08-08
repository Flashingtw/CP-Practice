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

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n>>q;
    vi a(n+1),b(n+1);
    rep(i,1,n+1) {
        cin>>a[i];
        b[a[i]]=i;
    }
    bool inv=1;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int x,y;
            cin>>x>>y;
            if(inv){ 
                int u = a[x],v = a[y];
                swap(a[x],a[y]);
                swap(b[u],b[v]);
            }
            else{
                int u = b[x],v = b[y];
                swap(b[x],b[y]);
                swap(a[u],a[v]);
            }
        }
        else{
            inv^=1;
        }
    }
    rep(i,1,n+1){
        cout << (inv?a[i]:b[i]) << ' ';
    }
}