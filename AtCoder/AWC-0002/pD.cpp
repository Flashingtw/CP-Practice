#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> c(n),r(m);
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<m;i++) cin>>r[i];
    sort(all(c),greater());
    sort(all(r),greater());
    int c_i=0,cnt=0;
    for(int r_i=0;r_i<m&&c_i<n;r_i++){
        while(c_i<n&&r[r_i]<c[c_i]) c_i++;
        if(c_i<n&&r[r_i]>=c[c_i]) {
            cnt++;
            c_i++;
        }
    }
    cout << cnt;
}