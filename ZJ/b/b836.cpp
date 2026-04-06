#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;
    while (cin >> n >> m) {
        if (m == 0) {
            cout << "Go Kevin!!\n";
            continue;
        }

        long long a = m;
        long long b = 2 - m;
        long long c = -2 * n;

        long long D = b * b - 4 * a * c;
        long long sqrtD = sqrt(D);

        if (sqrtD * sqrtD == D && (-b + sqrtD) % (2 * a) == 0 && (-b + sqrtD) > 0) {
            cout << "Go Kevin!!\n";
        } else {
            cout << "No Stop!!\n";
        }
    }
    return 0;
}