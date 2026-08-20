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
    string s;
    cin>>s;
    int n = sz(s);
    stack<char> op;
    stack<int> d;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            if(s[i+1]==')'){
                i++;
                d.push(0);
            }
            else op.push('(');
        }
        else if (s[i]==')'){
            while(op.top()!='('){
                int y = d.top();
                d.pop();
                int x = d.top();
                d.pop();
                op.pop();
                d.push(max(x+1,y));
            }
            op.pop();
        }
        else{
            op.push('-');
            i++;
        }
    }
    while(!op.empty()){
        int y = d.top();
        d.pop();
        int x = d.top();
        d.pop();
        op.pop();
        d.push(max(x+1,y));
    }
    cout << d.top() << '\n';
}
/*
遇到)可以先把裡面的算到(為止
->等最後結合
) 1
( 2
-> 3
*/