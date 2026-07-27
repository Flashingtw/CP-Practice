#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool chk=0;
    for(int i=0;i<n-1;i++){
        if(s[i]=='W'&&s[i+1]!='A'){
            chk=1;
            break;
        }
    }
    if(s.back()=='W') chk=1;
    cout << (chk?"no":"yes") << '\n';
}