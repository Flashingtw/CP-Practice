#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
vector<char> col = {'R','G','B'};
map<char,int> mp = {{'R',0},{'G',1},{'B',2}};
void solve(){
    vector<int> cnt(3);
    cin>>cnt[0]>>cnt[1]>>cnt[2];
    string s;

    while(1){
        int sz = s.length();
        int i = sz-1;
        vector<char> cl;
        for(char &c:col){
            if(cnt[mp[c]]==0) continue;
            if(sz>=1&&c==s[sz-1]) continue;
            if(sz>=3&&c==s[sz-3]) continue;
            cl.push_back(c);
        }
        if(cl.size()==0) break;
        if(cl.size()==1){
            s.push_back(cl[0]);
            cnt[mp[cl[0]]]--;
        }
        else{
            char best = cl[0];
            for(char &c:cl){
                if(cnt[mp[c]]>cnt[mp[best]]){
                    best = c;
                }
                else if (cnt[mp[c]]==cnt[mp[best]]){
                    if(sz>=2&&c==s[sz-2]){
                        best = c;
                    }
                }
            }
            s.push_back(best);
            cnt[mp[best]]--;
        }
    }
    cout << s << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}