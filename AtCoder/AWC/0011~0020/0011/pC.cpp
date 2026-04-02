#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,k,total=0;
    cin>>n>>k;
    int ans=0;
    for(int i=0;i<n;i++){
        ll num;
        cin>>num;
        if(((k|num)==k)){
            ans++;
            total|=num;
        }
    }
    if(ans==0||total!=k){
        cout << -1;
    }
    else{
        cout << ans;
    }
}