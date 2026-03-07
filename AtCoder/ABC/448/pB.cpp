#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1005;
int d[N];

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> c(m+1);
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(c[a]>b){
            ans+=b;
            c[a]-=b;
        }
        else{
            ans+=c[a];
            c[a]=0;
        }
    }
    cout << ans;
}