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
// 元素 -> id:數量
// vector<元素> 
// 倍數 1

// 最後再map結
string s;
int n;
int i;
int get_num(){
    if(i>=n||!isdigit(s[i])) return 1;
    int a=0;
    while('0'<=s[i]&&s[i]<='9'){
        a*=10;
        a+=s[i]-'0';
        i++;
    }
    return a;
}
map<string,int> f(){
    map<string,int> res;
    while(i<n&&s[i]!=')'){
        if(s[i]=='('){
            i++;
            auto sub = f();
            i++;

            int mul = get_num();
            for(auto [a,b]:sub){
                res[a]+=b*mul;
            }
        }
        else{
            string na;
            na+=s[i++];
            if(i<n&&islower(s[i])) na+=s[i++];
            int mul = get_num();
            res[na]+=mul;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s;
    n = sz(s);
    auto a = f();
    cout << s << '\n';
    for(auto [a,b]:a){
        cout << a << ":" << b << '\n';
    }
}