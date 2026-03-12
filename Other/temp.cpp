#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        for(int j=i;j;j=(i-1)&j){
            cout << i << ' ' << j << '\n';
        }
    }
}