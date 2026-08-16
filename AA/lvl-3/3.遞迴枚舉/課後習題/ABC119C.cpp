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

int l[10];
int n,a,b,c;
int ans=INF;
void dfs(int idx,int sumA,int sumB,int sumC,int cntA,int cntB,int cntC){
    if(idx==n){
        if(cntA==0||cntB==0||cntC==0) return;
        ans = min(ans,abs(sumA-a)+abs(sumB-b)+abs(sumC-c) + 10*(cntA-1+cntB-1+cntC-1));
        return;
    }
    dfs(idx+1,sumA,sumB,sumC,cntA,cntB,cntC);
    dfs(idx+1,sumA+l[idx],sumB,sumC,cntA+1,cntB,cntC);
    dfs(idx+1,sumA,sumB+l[idx],sumC,cntA,cntB+1,cntC);
    dfs(idx+1,sumA,sumB,sumC+l[idx],cntA,cntB,cntC+1);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>a>>b>>c;
    rep(i,0,n) cin>>l[i];
    dfs(0,0,0,0,0,0,0);
    cout << ans << '\n';
}
/*
n<=8 -> 想到暴力枚舉
每個竹子有
**4種選擇, 放A 放B 放C 不放** "重點!"
做dfs模擬->
*/