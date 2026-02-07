#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    while(q--){
        int x,y;
        cin>>x>>y;
        int l=0,r=y+n+10;
        int ans=r;
        int dx= lower_bound(v.begin(),v.end(),x)-v.begin();
        while(l<=r){
            int k = (l+r)/2;
            int cur = x+k;
            int d = upper_bound(v.begin(),v.end(),cur)-v.begin();
            int f = d-dx;
            int cnt = k+1;
            int valid_cnt=cnt-f;
            if(valid_cnt>=y){
                ans=k;
                r=k-1;
            }
            else l=k+1;
        }
        cout << x+ans << "\n";
    }
}