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
    vector<char> v;
    for(int i=0;i<n;i++){
        if(s[i]==')'&&!v.empty()&&v.back()=='('){
            v.pop_back();
        }
        else{
            v.push_back(s[i]);
        }
    }
    if(!v.empty()){
        cout << s << '\n';
    }
    else cout << '(' << s << '\n';
}