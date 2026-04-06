#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int convert[] = {
        10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21,
        22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33
    };
    string id;
    cin>>id;
    int letterNum = convert[id[0] - 'A'];
    int x1 = letterNum / 10;
    int x2 = letterNum % 10;
    
    int sum = x1 + x2 * 9;
    int weight = 8;
    for (int i = 1; i <= 8; i++) {
        sum += (id[i] - '0') * weight;
        weight--;
    }
    sum += (id[9] - '0');
    if (sum % 10 == 0) {
        cout << "real" << '\n';
    } else {
        cout << "fake" << '\n';
    }
}