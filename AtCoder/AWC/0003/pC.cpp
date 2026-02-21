#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    long long sum=0;
    vector<int> diff(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        diff[i]=a-b;
        sum+=a;
    }
    sort(diff.begin(),diff.end(),greater());
    for(int i=0;i<k;i++){
        sum-=diff[i];
    }
    cout << sum;
}