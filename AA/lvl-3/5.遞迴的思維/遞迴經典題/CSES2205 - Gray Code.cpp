#include <bits/stdc++.h>
using namespace std;

vector<string> rec(int n){
    if(n==1){
        return {"0","1"};
    }
    vector<string> a = rec(n-1);
    vector<string> r;
    for(string i:a){
        r.push_back(i);
        r.back()+='0';
    }
    for(int i=a.size()-1;i>=0;i--){
        r.push_back(a[i]);
        r.back()+='1';
    }
    return r;
}

int main(){
    int n;
    cin>>n;
    vector<string> ans = rec(n);
    for(auto i:ans){
        cout << i << '\n';
    }
}