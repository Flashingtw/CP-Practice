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
    multiset<int> s;
    for(int &i:v) {
        cin>>i;
        s.insert(i);
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++){
        auto it = s.upper_bound(v[i]);
        if(it!=s.end()){
            ans++;
            s.erase(it);
        }
    }
    cout << ans << '\n';
}