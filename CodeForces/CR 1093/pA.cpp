#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end(),greater());
    for(int i=1;i<n;i++){
        if(v[i]==v[i-1]){
            cout << -1 << '\n';
            return;
        }
    }
    for(int i=0;i<n;i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}