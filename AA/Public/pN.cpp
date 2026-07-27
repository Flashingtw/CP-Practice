#include <bits/stdc++.h>
using namespace std;
typedef pair<string,int> psi;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<psi> v(n);
    vector<int> ans(n); 
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        string &s = v[i].first;
        int len = s.size();
        int l=i-1;
        int r=i+1;
        int mx=0;
        if(l>=0){
            int lm=v[l].first.size();
            string &ls = v[l].first;
            for(int j=0;j<lm&&j<len;j++){
                if(s[j]==ls[j]){
                    mx = max(mx,j+1);
                }
                else break;
            }
        }
        if(r<n){
            int rm=v[r].first.size();
            string &rs = v[r].first;
            for(int j=0;j<rm&&j<len;j++){
                if(s[j]==rs[j]){
                    mx = max(mx,j+1);
                }
                else break;
            }
        }
        ans[v[i].second] = mx;
    }
    for(int i=0;i<n;i++) cout << ans[i] << '\n';
}