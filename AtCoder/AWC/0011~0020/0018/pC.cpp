#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    int n,q;
    cin>>n>>q;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    char mp[26];
    for(char i='a';i<='z';i++){
        mp[i-'a']=i;
    }
    for(int i=0;i<q;i++){
        char a,b;
        cin>>a>>b;
        for(char j='a';j<='z';j++){
            if(mp[j-'a']==a) mp[j-'a']=b;
        }
    }
    for(string s:v){
        for(char c:s){
            cout << mp[c-'a'];
        }
        cout << '\n';
    }
}