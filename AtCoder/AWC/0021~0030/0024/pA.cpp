#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    while(q--){
        int a,b;
        cin>>a>>b;
        cout << (v[a]>v[b]?"Yes":"No") << '\n';
    }
}