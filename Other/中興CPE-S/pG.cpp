#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll digsum(string a){
    ll res=0;
    for(char c:a){
        res+=c-'0';
    }
    return res;
}

bool chk(vector<int> cnt,string &s){
    for(char &c:s){
        if(cnt[c-'0']<1) return false;
        cnt[c-'0']--;
    }
    return true;
}

void solve(){
    string s;
    cin>>s;
    if(s.size()==1){
        cout << s << '\n';
        return;
    }
    ll total=0;
    vector<int> cnt(10,0);
    for(char c:s){
        cnt[c-'0']++;
        total += c-'0';
    }
    for(int i=1;i<=total;i++){
        int cur = i;
        int sum = i;
        string t = to_string(i);
        while(cur>9){
            int nxt = digsum(to_string(cur));
            sum += nxt;
            t+=to_string(nxt);
            cur = nxt;
        }
        if (i+digsum(t)==total){
            if(chk(cnt,t)){
                for(char c:t){
                    cnt[c-'0']--;
                }
                for(int i=1;i<=9;i++){
                    while(cnt[i]>=1) {
                        cout << i;
                        cnt[i]--;
                    }
                }
                while(cnt[0]>=1) {
                    cout << 0;
                    cnt[0]--;
                }
                cout << t << '\n';
                return;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}