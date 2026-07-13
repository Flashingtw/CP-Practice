#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<pii> v(n);
    for(auto &[a,b]:v) cin>>a>>b;
    sort(v.begin(),v.end());
    for(auto [a,b]:v) cout << a << ' ' << b << '\n';
}