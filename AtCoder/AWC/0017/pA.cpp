#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    int n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=0;i<n;i++){
        int c,d;
        cin>>c>>d;
        if(c<=k){
            ans+=d;
        }
    }
    cout << ans;
}