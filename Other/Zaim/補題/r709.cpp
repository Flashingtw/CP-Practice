#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    __int128 ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) ans+=((__int128)i*i+(__int128)i)*i;
    vector<int> res;
    while(ans>0){
        res.push_back(ans%10);
        ans/=10;
    }
    for(int i=res.size()-1;i>=0;i--) cout << res[i];
}
