#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct plant{
    int a,b,c;
};
ll dp[10005];
int main(){
    ll n,m,t;
    cin>>n>>m>>t;
    vector<plant> v;
    ll base=0;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(b<t){
            v.push_back({a,b,c});
        }
        else{
            base+=a;
        }
    }
    for(auto [a,b,c]:v){
        for(int i=m;i>=c;i--){
            dp[i] = max(dp[i],dp[i-c]+a);
        }
    }
    cout << base+dp[m];
}