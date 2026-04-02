#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;
    int ans=0,cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]) {
            cnt++;
            if(cnt>k) ans++;
        }
    }
    cout << ans;
}