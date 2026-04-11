#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool chk= s[0]=='o';
    for(int i=0;i<n;i++){
        if(chk&&s[i]=='o') continue;
        chk=0;
        cout << s[i];
    }
}