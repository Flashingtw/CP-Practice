#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &a:v) cin>>a;
    sort(v.begin(),v.end());
    ll ans = 0;
    for(int i=0;i<n;i++){
        int k=2;
        for(int j=i+1;j<n;j++){
            if(k<j) k = j+1;
            while(k<n&&v[i]+v[j]>v[k]) k++;
            ans += k-j-1;
        }
    }
    cout << ans << '\n';
}
//ai+aj>ak
//ai+ak>aj
//aj+ak>ai