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

priority_queue<int> lo,dl;
priority_queue<int,vector<int>,greater<int>> hi,dh;
int lsz,hsz;

void pl(){while(!dl.empty()&&dl.top()==lo.top()){lo.pop();dl.pop();}}
void ph(){while(!dh.empty()&&dh.top()==hi.top()){hi.pop();dh.pop();}}
void bal(){
    while(lsz>hsz+1){pl();hi.push(lo.top());lo.pop();lsz--;hsz++;}
    while(lsz<hsz){ph();lo.push(hi.top());hi.pop();lsz++;hsz--;}
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    rep(i,0,n){
        char c;
        int a;
        cin>>c>>a;
        if(c=='+'){
            pl(),ph();
            if(lo.empty()||a<=lo.top()){
                lo.push(a);
                lsz++;
            }
            else{
                hi.push(a);
                hsz++;
            }
            bal();
        }
        else{
            pl(),ph();
            if(a<=lo.top()) {dl.push(a);lsz--;}
            else {dh.push(a);hsz--;}
            bal();
        }
        pl(),ph();
        if((lsz+hsz)&1) cout << lo.top() << '\n';
        else cout << (lo.top()+hi.top())/2 << '\n';
    }
}