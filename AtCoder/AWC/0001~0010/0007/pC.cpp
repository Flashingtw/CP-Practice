#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int mx=0,idx=-1;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        if(num>mx){
            idx=i;
            mx=num;
        }
    }
    cout << idx;
}