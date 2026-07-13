#include <bits/stdc++.h>
using namespace std;
int main(){
      ios::sync_with_stdio(0),cin.tie(0);
      int n;
      cin>>n;
      long long ans=0;
      int max_v=0;
      for(int i=0;i<n;i++){
            int val;
            cin>>val;
            max_v=max(max_v,val);
            ans+=max_v-val;
      }
      cout << ans;
}
