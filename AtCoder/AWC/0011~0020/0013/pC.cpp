#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i!=k&&v[i]<v[k]){
            ans++;
        }
    }
    cout << ans;
}