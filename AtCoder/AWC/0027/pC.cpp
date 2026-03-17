#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    if(n==1){
        cout << 0;
        return 0;
    }
    sort(v.begin(),v.end());
    int mx = 0;
    for(int i=0;i<n-1;i++){
        mx = max(mx,v[i+1]-v[i]);
    }
    cout << mx;
}