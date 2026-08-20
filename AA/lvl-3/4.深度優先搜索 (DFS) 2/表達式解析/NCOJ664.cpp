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
stack<int> num;

int f(int x,int y,char c){
    if(c=='+') return x+y;
    if(c=='-') return x-y;
    if(c=='*') return x*y;
    if(c=='/') return x/y;
    return 0;
}

void cal(){
    int y = num.top();
    num.pop();
    int x = num.top();
    num.pop();
    char c = op.top();
    op.pop();
    num.push(f(x,y,c));
}
map<char,int> lvl;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    lvl['+'] = lvl['-'] = 1;
    lvl['('] = 2;
    while(cin>>s){
        if(s=="(") op.push(s[0]);
        else if (s==")"){
            while(op.top()!='('){
                cal();
            }
            op.pop();
        }
        else if(isdigit(s[0])) num.push(stoi(s));
        else{
            while(!op.empty()&&lvl[op.top()]<=lvl[s[0]]){
                cal();
            }
            op.push(s[0]);
        }
    }
    while(!op.empty()) cal();
    cout << num.top() << '\n';
}
/*
重點 ! map存優先級
明確定義誰先算 算完後要推入,彈出
*/