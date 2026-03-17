#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,s,t;
    cin>>n>>s>>t;
    int ans=0;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(abs(num-s)<=t) ans++;
    }
    cout << ans;
}