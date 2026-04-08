#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, d;
    cin>>a>>b>>d;
    for(long long i=a;i!=b;i+=d){
        cout << i << ' ';
    }
    cout << b;
}