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
const ll mod = 1e9+7;
stack<char> op;
stack<ll> d;
string s;
int n;

ll num(ll x,ll y,char c){
    if(c=='+'){
        return x+y;
    }
    if(c=='-'){
        return x-y;
    }
    if(c=='*'){
        return x*y;
    }
}

void cnt(){
    ll y = d.top();
    d.pop();
    ll x = d.top();
    d.pop();
    char c = op.top();
    op.pop();
    d.push((num(x,y,c)+mod)%mod);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s;
    n = sz(s);
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            op.push(s[i]);
        }
        else if(s[i]==')'){
            while(op.top()!='('){
                cnt();
            }
            op.pop();
        }
        else if (s[i]=='-'){
            op.push(s[i]);
        }
        else if (s[i]=='+'){
            while(!op.empty()&&(op.top()=='-')){
                cnt();
            }
            op.push(s[i]);
        }
        else if(s[i]=='*'){
            while(!op.empty()&&(op.top()=='-'||op.top()=='+')){
                cnt();
            }
            op.push(s[i]);
        }
        else{
            ll num=0;
            int ptr=i;
            while(ptr<n&&s[ptr]>='0'&&s[ptr]<='9'){
                num*=10;
                num+=(s[ptr]-'0');
                ptr++;
            }
            i = ptr-1;
            d.push(num);
        }
    }
    while(!op.empty()){
        cnt();
    }
    cout << d.top() << '\n';
}
/*
沒看好題目 優先級較高的先算, 然後算數字要弄好
*/