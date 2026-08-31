#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> extended_gcd(long long a, long long b){
    if(b==0){
        return {a,0};
    }
    pair<long long, long long> p = extended_gcd(b,a%b);
    long long x = p.second;
    long long y = p.first-(a/b)*x;
    return {x,y};
}
int main() {
    int T;
    std::cin >> T;
    while (T--) {
        long long a, b;
        std::cin >> a >> b;
        pair<long long, long long> answer = extended_gcd(a, b);
        std::cout << answer.first << ' ' << answer.second << '\n';
    }
}
/*
b==0 return
*/