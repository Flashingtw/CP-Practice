#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int a=0,ab=0,ans=0;
    for(char c:s){
        if(c=='A') a++;
        if(c=='B'&&a>0){
            ab++;
            a--;
        }
        if(c=='C'&&ab>0){
            ans++;
            ab--;
        }
    }
    cout << ans;
}