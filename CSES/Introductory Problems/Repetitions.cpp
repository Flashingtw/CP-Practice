#include <bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cin>>n;
    int cnt=0,mx=1;
    char last=' ';
    for(char c:n){
        if(c!=last){
            cnt=1;
            last=c;
        }
        else{
            cnt++;
            mx=max(mx,cnt);
        }
    }
    cout << mx;
}