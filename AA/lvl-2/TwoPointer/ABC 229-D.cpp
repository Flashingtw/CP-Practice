#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    string s;
    int k;
    cin>>s>>k;
    int n = s.size();
    int l = 0, cur = 0;
    int ans =0;
    for(int r=0;r<n;r++){
        cur+=s[r]=='.';
        while(cur>k){
            cur-= (s[l++]=='.');
        }
        ans = max(ans,r-l+1);   
    }
    cout << ans << '\n';
}