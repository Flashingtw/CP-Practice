#include <bits/stdc++.h>
using namespace std;
int cnt;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        string num = to_string(i);
        int sum=0;
        for(char c:num) sum+= c-'0';
        if(sum==k) cnt++;
    }
    cout << cnt;
}