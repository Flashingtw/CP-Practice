#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m,c;
    cin>>n>>m>>c;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a.begin(),a.end(),greater());
    sort(b.begin(),b.end(),greater());
    ll ans=0;
    int i=0,j=0;
    while(i<n&&j<m){
        if(b[j]>a[i]){
            j++;
        }
        else if (a[i]>=b[j]){
            ans++;
            j++;
            i++;
        }
    }
    cout << ans*c;
}