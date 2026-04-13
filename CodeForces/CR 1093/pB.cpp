#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
bool solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int cur=1;
    for(int i=1;i<n;i++){
        if(v[i]==v[i-1]){
            cur++;
            if(cur==m){
                return false;
            }
        }
        else{
            cur = 1;
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        if(solve()){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }   
}