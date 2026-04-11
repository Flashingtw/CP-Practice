#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v = {1};
    while(v.size()<n){
        vector<int> t;
        for(int i:v){
            if(i*2-1>n) continue;
            t.push_back(i*2-1);
        }
        for(int i:v){
            if(i*2>n) continue;
            t.push_back(i*2);
        }
        swap(v,t);
    }
    for(int a:v){
        cout << a << ' ';
    }
}