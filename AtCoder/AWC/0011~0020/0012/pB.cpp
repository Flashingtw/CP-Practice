#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,t,c,d;
    cin>>n>>t>>c>>d;
    long long cnt=0;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num>=t){
            cnt++;
        }
    }
    cout << (c>d?cnt*d:cnt*c);
}