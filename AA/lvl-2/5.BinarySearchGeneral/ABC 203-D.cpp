#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int grid[805][805];
ll n,k;

bool chk(ll tar){
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j] = (grid[i][j]>=tar);   
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    ll l=0,r=1e9+9;
    while(l<r){
        ll mid = (l+r)/2;
    }
}