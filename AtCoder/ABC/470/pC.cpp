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
    map<int,int> mp;
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    int ans=0;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            x--;
            ans^=v[x];
            if(++v[x]>0){
                mp[x]=v[x];
            }
            ans^=v[x];
        }
        else{
            for(auto &[a,b]:mp){
                if(b>1){
                    ans^=b;
                    ans^=(b-1);
                }
                else{
                    ans^=1;
                }
            }
            auto it=mp.begin();
            while(it!=mp.end()){
                if(it->second==1) {
                    v[it->first]=0;
                    it=mp.erase(it);
                }
                else{
                    it->second--;
                    v[it->first]--;
                    it++;
                }
            }
        }
        cout << ans << '\n';
    }
}