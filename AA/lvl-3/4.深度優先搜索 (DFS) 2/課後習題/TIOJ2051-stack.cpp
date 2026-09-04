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

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s;
    cout << s << '\n';
    n = sz(s);
    s+='#';
    stack<map<string,int>> st;
    st.push({});
    while(i<n){
        if(s[i]=='('){
            st.push({});
            i++;
        }
        else if(s[i]==')'){
            auto mp = st.top();
            st.pop();
            i++;
            int mul = get_num();
            for(auto [a,b]:mp){
                st.top()[a]+=b*mul;
            }
        }
        else if (isupper(s[i])){
            string a;
            a+=s[i++];
            if(islower(s[i])){
                a+=s[i++];
            }
            int cnt = get_num();
            st.top()[a]+=cnt;
        }
    }
    auto mp = st.top();
    for(auto [a,b]:mp){
        cout << a << ':' << b << '\n';
    }
}