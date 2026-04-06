#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N;
    long long sum = 1;
    cin>>N;

    for (int i=2;i*i<=N;++i) {
        if (N%i==0) {
            sum+=i;
            long long j = N/i;
            if (i!=j) {
                sum+=j;
            }
        }
    }
    cout << sum << endl;
    cout << (sum==N?"perfect":"not perfect") << endl;
    return 0;
}