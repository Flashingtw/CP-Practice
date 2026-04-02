#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    cin>>n>>m;
    long long sum=0;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        sum+=num;
    }
    cout << sum%m;
}