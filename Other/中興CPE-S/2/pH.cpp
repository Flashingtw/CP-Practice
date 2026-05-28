#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<char> v(n);
    for(char &c:v) cin>>c;
    string s;
    cin.ignore();
    while(getline(cin,s)){
        int sz = s.size();
        int cnt=0;
        for(int i=0;i<sz;i++){
            if(s[i]=='|') cnt++;
            if(s[i]=='-'){
                swap(v[cnt-1],v[cnt]);
            }
        }
    }
    for(char c:v) cout << c << ' ';
    cout << '\n';
}