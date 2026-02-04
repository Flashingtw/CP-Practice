#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n;
    cin>>n;
    LL prefix_max=0,max_sum=0;
    for (int i=0;i<n;i++) {
        LL p;
        cin>>p;
        prefix_max  =  prefix_max >0? prefix_max +p:p;
        max_sum = max(max_sum,prefix_max);
    }
    cout << max_sum;
}