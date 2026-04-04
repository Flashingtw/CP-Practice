#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int cnt[26];
int main(){
    int n,L,R;
    cin>>n>>L>>R;
    string s;
    cin>>s;
    ll ans=0;
    for(int i=0;i<n;i++){
        int l = i-L;
        int r = i-R-1;
        if(l>=0){
            cnt[s[l]-'a']++;
        }
        if(r>=0){
            cnt[s[r]-'a']--;
        }
        ans+= cnt[s[i]-'a'];
    }
    cout << ans;
}