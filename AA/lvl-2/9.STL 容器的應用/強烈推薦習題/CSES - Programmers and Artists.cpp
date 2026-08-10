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
struct ev{
    ll x,y;
    int idx;
    bool operator<(const ev &oth) const{
        return x-y>oth.x-oth.y;
    }
};
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int a,b,n;
    cin>>a>>b>>n;
    vector<ev> v(n);
    rep(i,0,n) cin>>v[i].x>>v[i].y;
    sort(all(v));
    vector<ll> pre(n),suf(n);
    priority_queue<ll,vl,greater<ll>> pq;
    ll cur=0;
    rep(i,0,n){
        pq.push(v[i].x);
        cur+=v[i].x;
        while(pq.size()>a){
            cur-=pq.top();
            pq.pop();
        }
        pre[i]=cur;
    }
    while(!pq.empty()) pq.pop();
    cur=0;
    for(int i=n-1;i>=0;i--){
        pq.push(v[i].y);
        cur+=v[i].y;
        while(pq.size()>b){
            cur-=pq.top();
            pq.pop();
        }
        suf[i]=cur;
    }
    ll ans=0;
    rep(i,a-1,n-b) ans = max(ans,pre[i]+suf[i+1]);
    cout << ans << '\n';
}
/*
兩數值擇一 -> 取差值+排序
前k大選擇 -> pq反悔貪心
枚舉分界線取前a,後b個
-> TLE -> 預處理前綴表後綴表
*/