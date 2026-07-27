#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &i:v) cin>>i;
    set<int> s = {v[0]};
    int cnt=1,l=1;
    for(int i=1;i<n;i++){
        if(s.count(v[i])){
            s.erase(v[i]);
        }
        if(s.empty()){
            for(int j=l;j<=i;j++){
                s.insert(v[j]);
            }
            cnt++;
            l = i+1;
        }
    }
    cout << cnt << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}