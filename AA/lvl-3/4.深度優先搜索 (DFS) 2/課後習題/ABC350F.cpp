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
const int N = 5e5+5;
string ans;
string s;
int l[N],r[N];

char chk(char c,bool rev){
    if(!rev) return c;
    else {
        if(islower(c)) return c-'a'+'A';
        else return c-'A'+'a';
    }
}

void dfs(int ll,int rr,bool rev){
    if(!rev){
        for(int i=ll;i<=rr;i++){
            if(s[i]=='('){
                dfs(i+1,r[i]-1,!rev);
                i = r[i];
            }
            else ans.push_back(chk(s[i],rev));
        }
    }
    else{
        for(int i=rr;i>=ll;i--){
            if(s[i]==')'){
                dfs(l[i]+1,i-1,!rev);
                i = l[i];
            }
            else ans.push_back(chk(s[i],rev));
        }
    }
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s;
    int n = sz(s);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
        }
        else if(s[i]==')'){
            r[st.top()] = i;
            l[i] = st.top();
            st.pop();
        }
    }
    dfs(0,n-1,0);
    cout << ans << '\n';
}
/*
遇到括號就遞迴處理+跳過區間
複習
*/