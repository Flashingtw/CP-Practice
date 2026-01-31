#include <algorithm>
#include <vector>
#include "lib1617.h"
bool cmp(int &x, int &y);
int a=1,b=2;

int n;
int main() {
    n = Get_Box();
    if (n == 1) {
        Report(1);
        return 0; // 確保程式在此結束
    }
    for (int i=3;i<=n;i++) {
        int k = Med3(a,b,i);
        if (a==k) a=i;
        if (b==k) b=i;
    }
    std::vector<int> v;
    for (int i=1;i<=n;i++) if (i!=a&&i!=b) v.push_back(i);

    std::nth_element(v.begin(),v.begin()+(n-2)/2,v.end(),cmp);
    Report(v[(n-2)/2]);

}
bool cmp(int &x,int &y) {
    int k = Med3(a,x,y);
    return k==x;
}