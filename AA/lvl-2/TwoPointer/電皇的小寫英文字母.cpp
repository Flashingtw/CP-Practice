#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int cnt[26];
int main(){
    string s;
    cin>>s;
    int l=0,chk=0;
    int n = s.size();
    int mn=1e9,L=-1,R=-1;
    for(int r=0;r<n;r++){
        if(cnt[s[r]-'a']++==0) chk++;
        while(chk==26){
            if(r-l+1<mn){
                mn=r-l+1,L=l,R=r;
            }
            if(--cnt[s[l++]-'a']==0) chk--;
        }
    }
    if(L==-1) cout << "QQ" << '\n';
    else cout << s.substr(L,mn);
}
