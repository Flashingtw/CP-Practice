#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    string s;
    getline(cin,s);
    int sz = s.size();
    bool chk=0;
    for(int i=0;i<sz;i++){
        if(s[i]>='0'&&s[i]<='9'&&!chk){
            int j=i+1;
            string a;
            a+=s[i];
            while(j<sz&&s[j]>='0'&&s[j]<='9'){
                a+=s[j];
                j++;
            }
            bool can=0;
            if((i==0||(s[i-1]!='^'&&s[i-1]!='_'&&!isalpha(s[i-1])))&&(j==sz||(s[j]!='^'&&s[j]!='_'&&!isalpha(s[j])))){
                can=1;
            }
            if(can){
                int cnt0=0;
                for(int i=a.size()-1;i>=0;i--){
                    if(a[i]=='0') cnt0++;
                    else break;
                }
                if(cnt0>=4&&cnt0==a.size()-1&&a[0]=='1'){
                    cout << "10^{" << cnt0 << "}";
                }
                else if (cnt0>=4){
                    cout << a[0];
                    if(a.size()-cnt0>1){
                        cout << '.';
                    }
                    for(int i=1;i<a.size()-cnt0;i++){
                        cout << a[i];
                    }
                    cout << "\\cdot10^{" << a.size()-1 << "}";
                }
                else cout << a;
            }
            else cout << a;
            i = j-1;
            continue;
        }
        cout << s[i];
        if(s[i]=='{') chk=1;
        if(s[i]=='}') chk=0;
    }
    cout << '\n';
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--) solve();
}