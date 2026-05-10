#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
set<string> s;
int n,m;
bool chk=0;
void dfs(int i,string &a){
    if(chk) return;
    if(i==m){
        if(s.find(a)==s.end()){
            cout << "Yes" << '\n';
            cout << a << '\n';
            chk=1;
        }
        return;
    }
    a.push_back('0');
    dfs(i+1,a);
    a.pop_back();
    a.push_back('1');
    dfs(i+1,a);
    a.pop_back();
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        string b;
        for(char c:a){
            b.push_back(c=='0'?'1':'0');
        }
        s.insert(b);
    }
    string a;
    dfs(0,a);
    if(!chk){
        cout << "No" << '\n';
    }
}