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

stack<char> op;
stack<int> d;
void f(){
    char c = op.top();
    op.pop();
    int a = d.top();
    d.pop();
    if(c=='!'){
        if(a) d.push(0);
        else d.push(1);
    }
    else{
        int b = d.top();
        d.pop();
        if(c=='+'){
            d.push(a|b);
        }
        else d.push(a&b);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    map<char,int> rk;
    rk['!']=1;
    rk['*']=2;
    rk['+']=3;
    while(1){
        string s;
        cin>>s;
        if(s=="END") break;
        for(char c:s){
            if(c=='!'){
                op.push('!');
            }
            else if (c=='0'||c=='1'){
                int a = c-'0';
                d.push(a);
            }
            else{
                while(!op.empty()&&rk[op.top()]<=rk[c]){
                    f();
                }
                op.push(c);
            }
        }
        while(!op.empty()){
            f();
        }
        cout << d.top() << '\n';
    }
}