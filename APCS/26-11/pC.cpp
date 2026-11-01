#include <bits/stdc++.h>
using namespace std;
string s;
int n,m;
int ans=0;
int cnt=0;
void rec(int idx,int cur){
    if(idx==n){
        if(cur>ans){
            ans=cur;
            cnt=1;
        }
        else if(cur==ans){
            cnt++;
        }
        return;
    }
    int ccr=0;
    for(int i=idx;i<n;i++){
        ccr = ccr*10+(s[i]-'0');
        if(cur+ccr>m) break;
        rec(i+1,cur+ccr);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>s>>m;
    n = s.size();
    rec(0,0);
    cout << ans << '\n' << cnt << '\n';
}