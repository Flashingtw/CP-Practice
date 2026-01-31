#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>m>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    int l=0,ans=0;
    map<int,int> mp;
    for(int r=0;r<n;r++){
        mp[v[r]]++;
        while(mp[v[r]]>1){
            mp[v[l]]--;
            if(mp[v[l]]==0) mp.erase(v[l]);
            l++;
        }
        if(r-l+1>=m) ans++;
    }
    cout << ans ;
}
