#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
map<char,int> mp;
int main(){
    mp['A']=0;
    mp['C']=1;
    mp['G']=2;
    mp['T']=3;
    ios::sync_with_stdio(0),cin.tie(0);
    vector<int> cnt(4);
    string s;
    cin>>s;
    int n = s.size();
    string ans;
    for(char c:s){
        cnt[mp[c]]++;
        bool a=1;
        for(int i=0;i<4;i++){
            if(cnt[i]==0) a=0;
        }
        if(a){
            ans.push_back(c);
            for(int i=0;i<4;i++) cnt[i]=0;
        }
    }
    if(!ans.empty()){
        cout << ans;
    }
    for(auto &[a,b]:mp){
        if(cnt[b]==0){
            cout << a << '\n';
            return 0;
        }
    }
}