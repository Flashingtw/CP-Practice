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
string s;
int idx,n;
ll cal_exp();
/*
*/
ll cal(){
    if(s[idx]=='f'){
        idx++;
        ll ma=0,mn=INF;
        while(s[idx]!=')'){
            idx++;
            ll val = cal_exp();
            ma = max(ma,val);
            mn = min(mn,val);
        }
        idx++;
        return ma-mn;
    }
    int st=idx;
    while('0'<=s[idx]&&s[idx]<='9') idx++;
    return stoi(s.substr(st,idx-st));
}
ll cal_exp(){
    vector<ll> num;
    num.push_back(cal());
    while(s[idx]=='+'||s[idx]=='*'){
        idx++;
        if(s[idx-1]=='+'){
            num.back()+=cal();
        }
        else{
            num.push_back(cal());
        }
    }
    ll r=1;
    for(ll a:num) r*=a;
    return r;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s;
    s+=')';
    cout << cal_exp() << '\n';
}