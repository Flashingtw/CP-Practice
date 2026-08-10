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
    int n;
    cin>>n;
    priority_queue<ll,vl,greater<ll>> pq;
    rep(i,0,n){
        ll x;
        cin>>x;
        pq.push(x);
    }
    ll ans=0;
    if(!(n&1)) pq.push(0);
    while(pq.size()>2){
        ll a = pq.top();pq.pop();
        ll b = pq.top();pq.pop();
        ll c = pq.top();pq.pop();
        ans+=(a+b+c);
        pq.push(a+b+c);
    }
    cout << ans << '\n';
}
/*
倒著做回去-> k元霍夫曼樹
-> 如果n奇數 -> 瘋狂三次
-> 如果n偶樹 -> 先合一次 2個的 再瘋狂3次
*/