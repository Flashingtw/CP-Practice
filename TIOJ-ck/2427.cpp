#include <algorithm>
#include <vector>
#include "lib2427.h"

int n;

int main() {
    n = Get_Box();
    if (n == 1) {
        Report(1);
        return 0;
    }
    
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        int k = Med3(a, b, i);
        if (k == a) {
            a = i;
        } else if (k == b) {
            b = i;
        }
    }
    
    std::vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (i != a && i != b) {
            v.push_back(i);
        }
    }
    
    auto cmp = [&](int x, int y) {
        int k = Med3(a, x, y);
        if (k == x) return false; 
        if (k == y) return true;  
        int k2 = Med3(b, x, y);
        return k2 == x; 
    };
    
    int target = (n - 1) / 2 - 1;
    std::nth_element(v.begin(), v.begin() + target, v.end(), cmp);
    Report(v[target]);
}