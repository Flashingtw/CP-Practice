#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF = 1e18+9;

ll dx[3];
// 0 ->
// 1 donw up 
// 2 up down
int sf = 10000;
int a[(int)2e5+5];
int shf;
ll cst(int x,int y){
    int typ=-1;
    if(x<=a[y]) typ=0;
    else if (x>=0) typ=1;
    else typ=2;
    return dx[typ];
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int y0,y1,h0,h1,n;
    cin>>y0>>y1>>dx[0]>>dx[1]>>dx[2]>>h0>>h1>>n;
    y0-=h0,y1-=h0,h1-=h0,shf=h0,h0=0;
    vector<vector<vector<ll>>> dp((h1-h0+2),vector<vector<ll>>(n+2,vector<ll>(3,INF)));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]-=h0;
    }
    //init
    dp[y0][1][0] = cst(y0,1);
    for(int i=y0+1;i<=h1;i++){
        dp[i][1][1] = min({dp[i-1][1][0],dp[i-1][1][1]}) + cst(i,1);
    }
    for(int i=y0-1;i>=h0;i--){
        dp[i][1][2] = min({dp[i+1][1][0],dp[i+1][1][2]}) + cst(i,1);
    }

    for(int j=2;j<=n;j++){
        for(int i=h0;i<=h1;i++){
            dp[i][j][0] = min({dp[i][j-1][0],dp[i][j-1][1],dp[i][j-1][2]}) + cst(i,j);
        }
        for(int i=h0+1;i<=h1;i++){
            dp[i][j][1] = min({dp[i-1][j][0],dp[i-1][j][1]}) + cst(i,j);
        }
        for(int i=h1-1;i>=h0;i--){
            dp[i][j][2] = min({dp[i+1][j][0],dp[i+1][j][2]}) + cst(i,j);
        }
    }
    cout << min({dp[y1][n][0],dp[y1][n][1],dp[y1][n][2]}) << '\n';
    
}