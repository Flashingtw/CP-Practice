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
    int st,fi;
    int idx;
    bool operator<(const ev &oth) const{
        return st<oth.st;
    }
};
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<ev> a(n);
    rep(i,0,n){
        cin>>a[i].st>>a[i].fi>>a[i].idx;
        a[i].st-=a[i].idx;
        a[i].fi-=a[i].idx;
    }
    sort(all(a));
    multiset<pii> ing,wai;
    int cur=0;
    
    while(q--){
        int d;
        cin>>d;
        while(cur<n&&a[cur].st<=d){
            ing.insert({a[cur].idx,cur});
            wai.insert({a[cur].fi,cur});
            cur++;
        }
        while(!wai.empty()&&wai.begin()->first <= d){
            int idx = wai.begin()->second;
            ing.erase(ing.find({a[idx].idx,idx}));
            wai.erase(wai.begin());
        }
        if(ing.empty()) cout << -1 << '\n';
        else cout << a[ing.begin()->second].idx << '\n';
    }
}
/*
重點觀察:
可以把S<=D+X<T => S-X<=D<T-X
且每個事件最多只會被加入一次 刪除一次 (均攤分析)
所以只要將<=D開始的事件加入 <=D結束的事件刪除 即可
*/