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

void solve() {
    cin.ignore();
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1,1e9);
    int now=2e9;
    map<int,int> mp;//紀錄車頭
    mp[0]=now,mp[n+1]=-1;
    rep(i,1,n+1) {
        cin>>a[i];
        if(a[i]<now){
            mp[i] = a[i];
            now = a[i];
        }
    }
    while(m--){
        int t,d;
        cin>>t>>d;
        a[t]-=d;
        auto it = mp.lower_bound(t);
        while(it->second>=a[t]) it = mp.erase(it);
        if(a[t]<prev(it)->second) mp[t]=a[t];
        cout << mp.size()-2 << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}
/*
*其中一個減少時後面也會跟著減少*
a[i] = min(a[1],...a[i])
遞減數列 求相同數字的排列有幾種
使用map紀錄車頭位置 由於性質所以i越大a[i]會越小
erase後會回傳下一個迭代器
最後再判斷是否能成為新車頭

每個i只會被加入一次 刪除一次
*/