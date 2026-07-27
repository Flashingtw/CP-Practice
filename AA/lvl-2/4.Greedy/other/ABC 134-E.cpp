#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &i:v) cin>>i;
    multiset<int> s;
    int ans=0;
    for(int i=n-1;i>=0;i--){
        auto it = s.upper_bound(v[i]);
        if(it!=s.end()){
            s.erase(it);
        }
        else{
            ans++;
        }
        s.insert(v[i]);
    }
    cout << ans << '\n';
}