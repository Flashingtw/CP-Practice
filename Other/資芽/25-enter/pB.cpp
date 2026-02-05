#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
vector<int> v;
int n;
int jpl(int i){
    if(v[i-1]==0) return 1;
    int cnt=0;
    while(i-2>=0){
        if(v[i-1]==1&&v[i-2]==0){
            cnt++;
            i-=2;
        }
        else break;
    }
    return cnt;
}
int jpr(int i){
    if(v[i+1]==0) return 1;
    int cnt=0;
    while(i+2<n){
        if(v[i+1]==1&&v[i+2]==0){
            cnt++;
            i+=2;
        }
        else break;
    }
    return cnt;
}
int chk(int i){
    if(v[i]==0) return -1;
    int mx=0;
    if(i!=n-1) mx=max(mx,jpr(i));
    if(i!=0) mx=max(mx,jpl(i));
    return mx;
}
int main(){
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++){
        cout << chk(i) << " ";
    }
}