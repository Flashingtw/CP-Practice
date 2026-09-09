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
    ll x,y;
    cin>>x>>y;
    int cnt=0;
    vector<int> d;
    for(int i=y;i>0;i--){
        if(x>=i*2-1){
            d.push_back(i*2-1);
            cnt++;
            x-=i*2-1;
        }
    }
    if(x>0){
        if(x==1&&d.size()>=2&&d[d.size()-2]>=7){
            cout << cnt+1 << '\n';
        }
        else cout << -1 << '\n';
    }
    else cout << cnt << '\n';
}
/*
要讓總和多1至少要能7+1 -> 5+3+1
*/