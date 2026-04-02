#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int cur=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(v[i]==1){
            cur++;
        }
        else{
            if(cur>=k){
                ans++;
            }
            cur=0;
        }
    }
    if(cur>=k) ans++;
    cout << ans;
}